//Clase Episodio
class Episodio:public Video{
private:
  string serie;
  int temporada;
  int nepisodio;
public:
  Episodio(string,string,int,float,string,int,string,int,int);
  void mostrarVideo();//Imprime info.
  string getSerie();//Da la serie a la que pertenece
};
