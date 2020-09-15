//Cpp de clase Episodio
#include "Episodio.h"

//Constructor. Primeros 5 parámetros para constructor de video. 3 parámetros extra: serie,temporada,episodio
Episodio::Episodio(string a,string b,int c,float d,string e,int nr,string f,int g,int h):Video(a,b,c,d,e,nr){
  serie=f;
  temporada=g;
  nepisodio=h;
}

//Añade información de serie, temporada y episodio al método de imprimir de video
void Episodio::mostrarVideo(){
  cout<<serie<<". Temporada "<<temporada<<", Episodio "<<nepisodio<<": "<<flush;
  Video::mostrarVideo();
}

////Regresa serie a la que pertence
string Episodio::getSerie(){
  return serie;
}
