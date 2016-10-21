#include "movie.h"

#ifndef CONTROLLER_H_INCLUDED
#define CONTROLLER_H_INCLUDED

#endif // CONTROLLER_H_INCLUDED

/** \brief Pide al usuario los datos de una nueva pelicula y luego lo agrega al array
 * \param sMovie* pMovies Puntero al array de peliculas
 * \param length int Longitud del array
 * \return int Return (-1) si hay un Error [Longitud invalida o puntero NULL o sin espacio libre] - (0) si Ok
 *
 */

int controller_altaMovie(sMovie* pMovies, int length);

/** \brief Pide al usuario el ID, y un nuevo puntaje de una pelicula a ser modificadolos luego los modifica
 * \param sMovie* pMovies Puntero al array de peliculas
 * \param length int Longitud del array
 * \return int Return (-1) si hay un Error [Longitud invalida o puntero NULL]
 *                    (-2) si hay un Error [No se encontro la pelicula]
 *                    ( 0) si Ok
 */

int controller_modificarMovie(sMovie* pMovies,int length);

/** \brief Pide al usuario el ID de una movie a ser dado de baja
 * \param sMovie* pMovies Puntero al array de peliculas
 * \param length int Longitud del array
 * \return int Return (-1) si hay un Error [Longitud invalida o puntero NULL]
 *                    (-2) si hay un Error [No se encontro la pelicula]
 *                    ( 0) si Ok
 */


int controller_bajaMovie(sMovie* pMovies,int length);
int controller_generarHtml(sMovie* pMovies,int length);
void controller_mock(sMovie* pMovies,int length);
void controller_listarMovie(sMovie* pMovies,int length);
void controller_cargarArchivo(sMovie* pMovies, int length);
void controller_guardarArchivo(sMovie* pMovie,int length);
int controller_verID(sMovie* pMovie,int length);
