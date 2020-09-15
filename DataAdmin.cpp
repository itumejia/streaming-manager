//Cpp de clase DataAdmin

#include "DataAdmin.h"

//Inicia objeto vacío. (Se llena hasta que se carga archivo)
DataAdmin::DataAdmin(){}

//Regresa vector con todos los vídeos
vector<Video*> DataAdmin::getAll(){
  return allVideos;
}

//Regesa tamaño del vector con todos los vídeos
int DataAdmin::lenVector(){
  return allVideos.size();
}

//Lector de archivos
void DataAdmin::readF(string archivo){
  ifstream reader;
  string line;
  reader.open(archivo);
  if (reader.is_open()){//Revisa que se abra archivo correctamente
    allVideos.clear();//Elimina datos que estuvieran antes
    while (getline(reader,line)){//lee línea por línea hasta el final del archivo
      if (line[0]=='M'){//Si el ID empieza con M, se lee una película
        readPelicula(line);
      }
      if (line[0]=='S'){//Si el ID empieza con S, se lee un episodio
        readEpisodio(line);
      }
    }
    reader.close();
    cout<<"Datos cargados correctamente."<<endl<<endl;
  }
  else{
    cout<<"No se encontró archivo."<<endl<<endl;
  }
}

//Lector de película
void DataAdmin::readPelicula(string line){
  string id="";
  string nombre="";
  string tiempo="";
  string cat="";
  string rat="";
  string nrat="";
  int count=1;
  for (int i = 0; i < line.length(); i++) {//Lee caracter por caracter de la línea
        if (line[i]==';'){//Cada dato está separado por punto y coma, cuando se lea el punto y coma, cambia el contador y lee el siguiente dato
          count+=1;
        }
        else if (count==1){//Lee ID
          id+=line[i];
        }
        else if (count==2){//Lee nombre de película
          nombre+=line[i];
        }
        else if (count==3){//Lee Duración
          tiempo+=line[i];
        }
        else if (count==4){//Lee género
          cat+=line[i];
        }
        else if (count==5){//Lee rating
          rat+=line[i];
        }
        else if (count==6){//Lee número de personas que han calificado
          nrat+=line[i];
        }
  }
  allVideos.push_back(new Pelicula(id,nombre,stoi(tiempo),stof(rat),cat,stoi(nrat)));//Agrega Pelicula al vector
}

//Lector de episodio
void DataAdmin::readEpisodio(string line){
  int count=1;
  string id="";
  string nombre="";
  string tiempo="";
  string cat="";
  string rat="";
  string nombres="";
  string temporada="";
  string episodio="";
  string nrat="";

  for (int i = 0; i < line.length(); i++) {//Lee caracter por caracter de la línea
        if (line[i]==';'){//Cada dato está separado por punto y coma, cuando se lea el punto y coma, cambia el contador y lee el siguiente dato
          count+=1;
        }
        else if (count==1){//Lee ID
          id+=line[i];
        }
        else if (count==2){//Lee nombre de la serie
          nombres+=line[i];
        }
        else if (count==3){//Lee nombre del episodio
          nombre+=line[i];
        }
        else if (count==4){//Lee Duración
          tiempo+=line[i];
        }
        else if (count==5){//Lee género
          cat+=line[i];
        }
        else if (count==6){//Lee rating
          rat+=line[i];
        }
        else if (count==7){//Lee número de personas que han calificado
          nrat+=line[i];
        }
  }
  temporada=id.substr(8,2);//El caracter 8 y 9 del ID de serie son el número de temporada
  episodio=id.substr(10,2);//El caracter 10 y 11 del ID de serie son el número de capítulo
  allVideos.push_back(new Episodio(id,nombre,stoi(tiempo),stof(rat),cat,stoi(nrat),nombres,stoi(temporada),stoi(episodio)));//Agrega capítulo al vector
}

//Imprime todos los vídeos
void DataAdmin::printAll(){
  for (int i = 0; i < allVideos.size(); i++) {//Recorre todo el vector
    cout<<i+1<<". "<<flush;
    allVideos[i]->mostrarVideo();//Método de video: mostrar video
    cout<<endl;
  }
}

//Filtra las películas
vector<Video*> DataAdmin::allMovies(){
  vector<Video*> rVector;//Vector de regreso
  string id;
  string identifier;
  for(int i=0;i<allVideos.size();i++){//Recorre todo el vector
    id=allVideos[i]->getID();
    identifier=id.substr(0,1);
    if(identifier=="M"){//Revisa que el ID empiece con M
      rVector.push_back(allVideos[i]);//Agrega el video al vector de regreso
    }
  }
  //cout<<"Len vector: "<<rVector.size()<<endl;
  return rVector;
}

//Filtra todos los episodios
vector<Video*> DataAdmin::allSeries(){
  vector<Video*> rVector;//Vector de regreso
  string id;
  string identifier;
  for(int i=0;i<allVideos.size();i++){//Recorre todo el vector
    id=allVideos[i]->getID();
    identifier=id.substr(0,1);
    if(identifier=="S"){//Revisa que el ID empiece con S
      rVector.push_back(allVideos[i]);//Agrega el video al vector de regreso
    }
  }
  //cout<<"Len vector: "<<rVector.size()<<endl;
  return rVector;
}

//Filtra los episodios de una serie en específico. Se tiene que dar como argumento vector de solo series y string con búsqueda
vector<Video*> DataAdmin::detSerie(vector<Video*> series,string ns){
  vector<Video*> rVector;//Vector de regreso
  string nss;//Variable que almacena nombre de cada serie
  //Convierte a minúsculas la búsqueda
  for (int i = 0; i < ns.length(); i++) {
    ns[i]=tolower(ns[i]);
  }
  for(int i=0;i<series.size();i++){//Recorre vector
    nss=series[i]->getSerie();//Obtiene nombre de serie
    //Convierte nombre de serie a minúscula
    for (int j = 0; j < nss.length(); j++) {
      nss[j]=tolower(nss[j]);
    }
    if(ns==nss){//Compara nombre con búsqueda
      rVector.push_back(series[i]);
    }
  }
  return rVector;
}

//Imprime vector en específico. Como argumento el vector a imprimir
void DataAdmin:: printVector(const vector<Video*> toPrint){//Recorre vector
  for (int i = 0; i < toPrint.size(); i++) {
    cout<<i+1<<". "<<flush;
    toPrint[i]->mostrarVideo();//imprime (método de video)
    cout<<endl;
  }
}

//Filtra por género. Argumentos: vector a filtrar y género buscado
vector<Video*> DataAdmin::byGen(const vector<Video*> toSort, string genero){
  vector<Video*> toReturn;//Vector a regresar
  string gVector;//Almacena género de cada video del vector
  //Convierte a minúsculas la búsqueda
  for (int i = 0; i < genero.length(); i++) {
    genero[i]=tolower(genero[i]);
  }
  for(int i=0;i<toSort.size();i++){//Recorre vector
    gVector=toSort[i]->getGenero();//Obtiene genero de cada video
    if(gVector==genero){//Compara con búsqueda
      toReturn.push_back(toSort[i]);//Agrega video al vector a regresar
    }
  }
  return toReturn;
}

//Filtra vector por calificación. Argumentos: vector, cal. mínima y cal. máxima
vector<Video*> DataAdmin::byCal(vector<Video*> toSort, float min,float max){
  vector<Video*> toReturn;//Vector a regresar
  float ratVector;
  for(int i=0;i<toSort.size();i++){//Recorre vector
    ratVector=toSort[i]->getRat();//obtiene rating de cada video
    if((ratVector>=min)&&(ratVector<=max)){//Compara con rango dado
      toReturn.push_back(toSort[i]);//Agrega video al vector a regresar
    }
  }
  return toReturn;
}


//Buscar video en específico por id o nombre
Video* DataAdmin::buscar(string bus){
  Video* toReturn;//Video a regresar
  string nombre;//nombre de cada video
  string id;//id de cada video
  int check=0;//Indicador de si se encontro video o no
  //Convierte a minúsculas la búsqyeda
  for (int i = 0; i < bus.length(); i++) {
    bus[i]=tolower(bus[i]);
  }
  for(int i=0;i<allVideos.size();i++){//Recorre vector de todos los videos
    nombre=allVideos[i]->getNombre();//Obtiene nombre
    id=allVideos[i]->getID();//Obtiene id
    //Convierte a minusculas el nombre
    for (int j = 0; j < nombre.length(); j++) {
      nombre[j]=tolower(nombre[j]);
    }
    //Convierte a minusculas el id
    for (int j = 0; j < id.length(); j++) {
      id[j]=tolower(id[j]);
    }
    if(bus==nombre||bus==id){//Compara si busqueda coincide con id o nombre
      toReturn=allVideos[i];//Asigna el video al video a regresar
      check=1;//Indicador de que sí encontró video
      break;//Detiene búsqueda
    }
  }
  //Si no se encuentra video, se crea una película con constructor vación (se indica que no existe en const. vacío)
  if (check==0){
    toReturn=new Pelicula();
  }
  return toReturn;
}
