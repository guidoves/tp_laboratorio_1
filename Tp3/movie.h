#ifndef SMOVIE_H_INCLUDED
#define SMOVIE_H_INCLUDED

#define MOVIE_EMPTY 0
#define MOVIE_USED 1
#define MOVIE_DELETE 2


typedef struct{

    int idMovie;
    char titulo[20];
    char genero[20];
    int duracion;
    char descripcion[50];
    int puntaje;
    char linkImagen[50];
    int flagEstado;

}sMovie;


#endif // SMOVIE_H_INCLUDED
