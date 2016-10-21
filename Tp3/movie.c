#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "movie.h"

static int movies_findEmptyPlace(sMovie* pMovies, int length);
static int movies_findNextId(sMovie* pMovies, int length);

/** \brief  Se marcan todas las posiciones del array como libres
 *          colocando en cada elmento el flag de flagEstado en TRUE
 *
 * \param sMovie* pMovies Puntero al array de peliculas
 * \param length int Longitud del array
 * \return int Return (-1) si hay un Error [Longitud invalida o puntero NULL] - (0) si Ok
 *
 */

int movies_init(sMovie* pMovies,int length)
{
    int i;
    int retorno= -1;

    if(pMovies != NULL && length > 0)
    {
        for(i=0;i<length;i++)
        {
            (pMovies+i)->flagEstado = MOVIE_EMPTY;
            (pMovies+i)->idMovie = MOVIE_EMPTY;

        }

        retorno = 0;
    }

    return retorno;


}

/** \brief Agrega a la lista de movies un nuevo elemento, el id no lo recibe lo calcula
 * \param sMovie* pMovies Puntero al array de peliculas
 * \param length int Longitud del array
 * \param titulo nombre del titulo de la pelicula
 * \param genero tipo de genero de la pelicula
 * \param duracion duracion en minutos de la pelicula
 * \param descripcion descripcion de la pelicula
 * \param puntaje puntaje de la pelicula
 * \return int Return (-1) si hay un Error [Longitud invalida o puntero NULL o sin espacio libre] - (0) si Ok
 *
 */

int movies_append(sMovie* pMovies ,int length, char titulo[], char genero[], int duracion, char descripcion[], int puntaje)
{
    int retorno = -1;
    int id, index;

    if(pMovies != NULL && length > 0)
    {
        index = movies_findEmptyPlace(pMovies,length);
        if(index != -1)
        {
            id = index;
            strcpy((pMovies+index)->titulo,titulo);
            strcpy((pMovies+index)->genero,genero);
            strcpy((pMovies+index)->descripcion,descripcion);
            (pMovies+index)->idMovie = id;
            (pMovies+index)->duracion = duracion;
            (pMovies+index)->puntaje = puntaje;
            (pMovies+index)->flagEstado = MOVIE_USED;

            retorno=0;

        }
    }

    return retorno;

}

/** \brief Busca en la lista una pelicula que coincida con el Id recibido
 *
 * \param sMovie* pMovies Puntero al array de peliculuas
 * \param length int Longitud del array
 * \param idMovie int ID de la pelicula
 * \return int Return (-1) si hay un Error [Longitud invalida o puntero NULL o sin no se encontro la pelicula] - (0) si Ok
 *
 */

sMovie* movies_find(sMovie* pMovies, int length, int idMovie)
{

    sMovie* pRetorno = NULL;
    int i;

    if(pMovies != NULL && length > 0)
    {
        for(i=0;i<length;i++)
        {
            if((pMovies+i)->idMovie == idMovie && (pMovies+i)->flagEstado == MOVIE_USED)
            {
                pRetorno = (pMovies+i);
                break;
            }
        }
    }
    return pRetorno;

}

/** \brief Elimina de manera logica una pelicula de la lista
 *         colocando el flag de flagEstado en TRUE
 *
 * \param sMovie* pMovies Puntero al array de peliculas
 * \param length int Longitud del array
 * \param idMovie int ID del movie
 * \return int Return (-1) si hay un Error [Longitud invalida o puntero NULL]
 *                    ( 0) si Ok
 *
 */

int movies_remove(sMovie* pMovies , int length , int idMovie)
{
    sMovie* pAuxMovie;
    int retorno = -1;

    pAuxMovie = movies_find(pMovies,length,idMovie);
    if(pAuxMovie != NULL)
    {
        pAuxMovie->flagEstado = MOVIE_DELETE;
        retorno = 0;
    }

    return retorno;


}

/** \brief Modifica el puntaje de un movie existente
 *
 * \param sMovie* pMovies Puntero al array de peliculas
 * \param length int Longitud del array
 * \param idMovie int ID del Movie
 * \param puntaje int puntaje del movie
 * \return int Return (-1) si hay un Error [Longitud invalida o puntero NULL] - (0) si Ok
 *
 */

int movies_update(sMovie* pMovies, int length, int idMovie, int* puntaje)
{
    int retorno = -1;
    sMovie* pAuxMovie;

    if(pMovies != NULL && length > 0)
    {
        pAuxMovie = movies_find(pMovies,length,idMovie);
        if(pAuxMovie != NULL)
        {
            pAuxMovie->puntaje=puntaje;

            retorno=0;

        }
    }

    return retorno;
}

/** \brief  Busca en el array la primer posicion libre
 * \param sMovie* pMovies Puntero al array de peliculas
 * \param length int Longitud del array
 * \return int Return (-1) si hay un Error [Longitud invalida o puntero NULL] - (index del lugar libre) si Ok
 *
 */

static int movies_findEmptyPlace(sMovie* pMovies , int length)
{
    int i;
    int retorno = -1;

    if(pMovies != NULL && length > 0)
    {
        for(i=0;i<length;i++)
        {
            if((pMovies+i)->flagEstado == MOVIE_EMPTY)
            {
            retorno= i;
            break;
            }


        }


    }

    return retorno;
}

/** \brief  Busca en el array el id mas alto entre los usados y los borrados
 * \param sAbonado* pAbonados Puntero al array de peliculas
 * \param length int Longitud del array
 * \return int Return (-1) si hay un Error [Longitud invalida o puntero NULL] - (proximo ID) si Ok
 *
 */

static int movies_findNextId(sMovie* pMovies,int length)
{
    int i, maxId=-1;
    int retorno=-1;

    if(pMovies != NULL & length > 0)
    {
        for(i=0;i<length;i++)
        {
            if((pMovies+i)->flagEstado == MOVIE_EMPTY || (pMovies+i)->flagEstado == MOVIE_DELETE)
            {
                if((pMovies+i)->idMovie > maxId || maxId == -1)
                maxId = (pMovies+i)->idMovie;
            }
        }
        retorno = maxId;
    }
    return retorno;
}
