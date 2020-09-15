//Clase video. ABSTRACTA

class Video{
protected:
  int duracion;//(min)
  string nombre;
  string IDvideo;
  string genero;
  float rating;
  int nrating;//numero de personas que han calificado título
  Video();//Constructor vación (no existe título)
  Video(string,string,int,float,string,int);//Constructor
public:
  virtual void mostrarVideo()=0;//Método virtual, imprime info. del video (Cambia para peli y episodio)
  string getID();
  string getNombre();
  string getGenero();
  float getRat();//get Rating
  void setRat(float);//Cambiar rating
  float operator+(const float&);//Sobrecarga de operador más para obtener nuevo promedio por nueva calificación
  virtual string getSerie();//Regresa nombre de serie (solo para episodio)
};
