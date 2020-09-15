//Cpp de clase Pelicula
#include "Pelicula.h"

//Constructor con parámetros (igual que vídeo)
Pelicula::Pelicula(string a,string b,int c,float d,string e,int nr):Video(a,b,c,d,e,nr){}

//Constructor vacío llama contructor vacío de Video
Pelicula::Pelicula():Video(){}

//Imprime info. de película. (Igual que Video)
void Pelicula::mostrarVideo(){
  Video::mostrarVideo();
}
