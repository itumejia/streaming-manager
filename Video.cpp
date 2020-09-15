//Cpp de clase Video
#include "Video.h"

//Constructor con todos los atributos. Parámetros: id,nombre,duracion,rating,genero,no. de personas que han calificado
Video::Video(string a,string b,int c,float d,string e,int nr){
  IDvideo=a;
  nombre=b;
  duracion=c;
  rating=d;
  //Convierte genero a minúsculas
  for (int i = 0; i < e.length(); i++) {
    e[i]=tolower(e[i]);
  }
  genero=e;
  nrating=nr;
}

//Constructor vacío. Parámetros con "NE" para indicar no existe. Se utiliza para buscador, para indicar que no se encontró un título
Video::Video(){
  IDvideo="NE";
  nombre="NE";
  duracion=0;
  rating=0;
  genero="NE";
  nrating=0;
}

//Muestra información del video
void Video::mostrarVideo(){
  cout<<"''"<<nombre<<"''\n"<<"ID: "<<IDvideo<<" Duración: "<<duracion<<" min. Rating: "<<rating<<" Género: "<<genero<<endl;
}

string Video::getID(){
  return IDvideo;
}

string Video::getNombre(){
  return nombre;
}

string Video::getGenero(){
  return genero;
}

float Video::getRat(){
  return rating;
}

void Video::setRat(float r){
  rating=r;
}

//Sobrecarga de operador +. Se suma nueva calificación, regresa nuevo promedio
float Video::operator+(const float& cal){
  float prom=((rating*nrating)+cal)/(nrating+1);
  nrating++;//Se aumenta el número de personas que han calificado
  return prom;
}

string Video::getSerie(){}//Solo hace algo con episodios
