//Clase DataAdmin. Administrador de vector con todos los vídeos

class DataAdmin{
private:
  vector<Video*> allVideos;//Vector que contiene TODOS los videos

public:
  DataAdmin();//Constructor
  vector<Video*> getAll();//Regresa vector con todos los videos
  void readF(string);//Leer archivo
  void readPelicula(string);//Leer línea del archivo que contiene una película
  void readEpisodio(string);//Leer línea del archivo que contiene una serie
  void printAll();//Imprimir TODOS los vídeos
  void printVector(vector<Video*>);//Imprimir un vector de videos en específico
  vector<Video*> byCal(vector<Video*>,float,float);//Filtrar vector por calificaicón
  vector<Video*> byGen(vector<Video*>,string);//Filtrar vector por género
  vector<Video*> allSeries();//Filtrar para obtener todos los capitulos de todas las series
  vector<Video*> allMovies();//Filtrar para obtener todas las películas
  vector<Video*> detSerie(vector<Video*>,string);//Filtrar para obtener los episodios de una serie en específico
  Video* buscar(string);//Buscar un vídeo en específico
  int lenVector();//Numero de videos total
};
