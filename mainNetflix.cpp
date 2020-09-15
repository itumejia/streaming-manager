#include <iostream>
#include<sstream>
#include <fstream>
#include<vector>
using namespace std;
#include "Video.cpp"
#include "Pelicula.cpp"
#include "Episodio.cpp"
#include "DataAdmin.cpp"

//Ejecución del programa
int main() {
  int menu=0;//Variable para hacer loop de menú infiniito
  string user;//Variable para almacenar inputs
  string file;//Variable para almacenar input (nombre de archivo)
  DataAdmin data=DataAdmin();//Objeto DataAdmin (admminstrador de la lista de todos los vídeos)
  vector<Video*> filtered;//Vector de pointers de videos que almacenará los resultados de búsquedas
  float min,max,cal;//Variables para rangos de calificación
  Video* buscado;//Objeto de video para almacenar video encontrado
  //mensaje de bienvenida:
  cout<<"***************************BIENVENIDO A  TU PLATAFORMA***************************\n******************************FAVORITA DE STREAMING******************************"<<endl<<endl;

  //Main menu:
  while (menu==0){
    cout<<"*********************************MENU  PRINCIPAL*********************************"<<endl;
    cout<<"1. Cargar archivo de datos\n2. Mostrar los videos en general, con una cierta calificación o de un cierto género\n3. Mostrar los episodios de una determinada serie con una calificacion determinada\n4. Mostrar las películas con cierta calificacion\n5. Calificar un video\n0. Salir"<<endl;

    cin>>user;//decision main menu
    cout<<endl;

    //Opción 1: Cargar archivo
    if(user=="1"){
      cout<<"Ingresa el nombre del archivo. (Por favor incluye la terminación .txt)"<<endl;
      cin>>file;//Leer nombre del archivo
      data.readF(file);//Carga datos
    }

    //Opción 1: MOstrar videos
    else if(user=="2"){
      //Submenú
      cout<<"Seleccione una opción:\n1. Mostrar todos los videos\n2. Filtrar por género\n3. Filtrar por calificación\n";
      cin>>user;
      //Submenu op. 1: Mostrar todos los videos
      if(user=="1"){
        if(data.lenVector()>0){//Revisar que haya videos en el vector
          cout<<"Todos los videos:\n";
          data.printAll();//Se imprimen todos los videos
        }
        else{
          cout<<"No se encontraron datos."<<endl<<endl;
        }
      }
      //Submenu op. 2: Mostrar videos
      else if(user=="2"){
        if(data.lenVector()>0){//Revisar que haya videos en el vector
          cout<<"Escriba el género:\n-Drama\n-Accion\n-Comedia\n-Misterio "<<endl;
          cin>>user;
          filtered=data.byGen(data.getAll(),user);//Filtra todos los videos por genero en el vector filtered
          if(filtered.size()>0){//Revisar que haya videos en el vector
            cout<<"\nResultados:"<<endl<<endl;
            data.printVector(filtered);//Imprimir vector
          }
          else{
            cout<<"No se encontraron datos."<<endl<<endl;
          }
        }
        else{
          cout<<"No se encontraron datos."<<endl<<endl;
        }
      }
      //Submenu op. 3: Mostrar videos por rating
      else if(user=="3"){
        if(data.lenVector()>0){//Revisar que haya videos en el vector
          cout<<"Escriba la calificación mínima (0-5): "<<flush;
          cin>>min;
          cout<<"Escriba la calificación máxima (0-5): "<<flush;
          cin>>max;
          filtered=data.byCal(data.getAll(),min,max);//Filtra todos los videos en el vector filtered
          if(filtered.size()>0){//Revisar que haya videos en el vector
            cout<<"\nResultados:"<<endl<<endl;
            data.printVector(filtered);//Imprimir vector
          }
          else{
            cout<<"No se encontraron datos."<<endl<<endl;
          }
        }
        else{
          cout<<"No se encontraron datos."<<endl<<endl;
        }
      }
      else{
        cout<<"Opción inválida"<<endl<<endl;
      }
    }
    //Opción 3: Filtrar videos de serie por rating
    else if (user=="3"){
      cout<<"Escriba el nombre de la serie que desea filtrar: "<<flush;
      getline(cin,user);
      getline(cin,user);
      cout<<"Escriba la calificación mínima (0-5): "<<flush;
      cin>>min;
      cout<<"Escriba la calificación máxima (0-5): "<<flush;
      cin>>max;
      if(data.lenVector()>0){//Revisar que haya videos en el vector
        filtered=data.allSeries();//Filtra todos los videos en el vector filtered
        filtered=data.detSerie(filtered,user);//Filtra todos los videos en el vector filtered
        filtered=data.byCal(filtered,min,max);//Filtra todos los videos en el vector filtered
        if(filtered.size()>0){//Revisar que haya videos en el vector
          cout<<"\nResultados:"<<endl<<endl;
          data.printVector(filtered);//Imprimir vector
        }
        else{
          cout<<"No se encontraron datos."<<endl<<endl;
        }
      }
      else{
        cout<<"No se encontraron datos."<<endl<<endl;
      }
    }
    //Opción 4: Filtrar películas por rating
    else if (user=="4"){
      cout<<"Escriba la calificación mínima (0-5): "<<flush;
      cin>>min;
      cout<<"Escriba la calificación máxima (0-5): "<<flush;
      cin>>max;
      if(data.lenVector()>0){//Revisar que haya videos en el vector
        filtered=data.allMovies();//Filtra todos los videos en el vector filtered
        filtered=data.byCal(filtered,min,max);//Filtra todos los videos en el vector filtered
        if(filtered.size()>0){//Revisar que haya videos en el vector
          cout<<"\nResultados:"<<endl<<endl;
          data.printVector(filtered);//Imprimir vector
        }
        else{
          cout<<"No se encontraron datos."<<endl<<endl;
        }
      }
      else{
        cout<<"No se encontraron datos."<<endl<<endl;
      }
    }
    //Opción 5: Calificar
    else if(user=="5"){
      cout<<"Escriba el nombre o ID del título a calificar: "<<flush;
      getline(cin,user);
      getline(cin,user);
      buscado=data.buscar(user);//Buscar título
      if ((buscado->getID())!="NE"){//Si el buscado no tiene la marca NE (no encontrado)
        cout<<"Introduzca calificación: "<<flush;
        cin>>cal;
        buscado->setRat(*buscado+cal);//Asignar nueva calificación (+ sobrecargado para calcular promedio correctamente)
        cout<<"Título calificado con éxito."<<endl<<endl;
        cout<<"Nueva calificación del título: "<<buscado->getRat()<<endl<<endl;
      }
      else{
        cout<<"No se encontró el título."<<endl<<endl;
      }
    }
    //Opción 0: Salir
    else if(user=="0"){
      cout<<"Vuelve pronto!"<<endl<<endl;
      break;
    }
    else{
      cout<<"Opción inválida. Intenta de nuevo."<<endl<<endl;
    }
  }
  return 0;
}
