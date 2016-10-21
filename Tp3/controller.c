#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "movie.h"
#include "utn.h"
#include "controller.h"

/** \brief Pide al usuario los datos de una nueva pelicula y luego lo agrega al array
 * \param sMovie* pMovies Puntero al array de peliculas
 * \param length int Longitud del array
 * \return int Return (-1) si hay un Error [Longitud invalida o puntero NULL o sin espacio libre] - (0) si Ok
 *
 */


int controller_altaMovie(sMovie* pMovies, int length)
{
    char titulo[20];
    char genero[20];
    char descripcion[50];
    unsigned int duracion;
    unsigned int puntaje;
    int retorno= -1;

    retorno = getValidString("Ingrese el nombre de la pelicula: ","Ingreso invalido.\n","Ingreso invalido\nIngrese hasta 20 caracteres.",titulo,20,3);

    if(retorno == 0)
    {
        retorno = getValidString("Ingrese el genero de la pelicula: ","Ingreso invalido.\n","Ingreso invalido\nIngrese hasta 20 caracteres.",genero,20,3);
        if(retorno == 0)
        {
            retorno = getValidString("Ingrese una descripcion de la pelicula: ","Ingreso invalido.\n","Ingreso invalido\nIngrese hasta 50 caracteres.",descripcion,50,3);
            if(retorno == 0)
            {
                retorno= getValidInt("Ingrese la duracion (Minutos) de la pelicula: ","Ingreso invalido.\n",&duracion,20,240,3);
                if(retorno == 0)
                {
                    retorno = getValidInt("Ingrese el puntaje de la pelicula (1 al 10): ","Ingreso invalido.\n",&puntaje,1,10,3);
                    if(retorno == 0)
                    {
                        retorno= movies_append(pMovies,length,titulo,genero,duracion,descripcion,puntaje);
                    }
                }
            }
        }
    }

    return retorno;

}

/** \brief Pide al usuario el ID, y un nuevo puntaje de una pelicula a ser modificadolos luego los modifica
 * \param sMovie* pMovies Puntero al array de peliculas
 * \param length int Longitud del array
 * \return int Return (-1) si hay un Error [Longitud invalida o puntero NULL]
 *                    (-2) si hay un Error [No se encontro la pelicula]
 *                    ( 0) si Ok
 */

int controller_modificarMovie(sMovie* pMovies,int length)
{
    int puntaje;
    int id;
    int retorno= -1;

    retorno= getValidInt("Ingrese el ID de la pelicula: ","Ingreso invalido (Ingrese entre 0-9999)\n",&id,0,9999,3);

    if(retorno==0)
    {
        if(movies_find(pMovies,length,id)== NULL)
        {

            printf("NO existe el ID\n");

        }
        else
        {
            retorno=getValidInt("Ingrese el puntaje: ","Ingreso invalido (Rango valido 1-10)\n",&puntaje,1,10,3);
            if(retorno == 0)
            {
                retorno=movies_update(pMovies,length,id,puntaje);

            }
        }
    }

    return retorno;

}

/** \brief Pide al usuario el ID de una pelicula a ser dada de baja
 * \param sMovie* pMovies Puntero al array de peliculas
 * \param length int Longitud del array
 * \return int Return (-1) si hay un Error [Longitud invalida o puntero NULL]
 *                    (-2) si hay un Error [No se encontro la pelicula]
 *                    ( 0) si Ok
 */

int controller_bajaMovie(sMovie* pMovies,int length)
{
    int id;
    int retorno = -1;

    retorno = getValidInt("Ingrese el ID a dar de baja: ","Ingreso invalido(Ingrese de 0-9999)\n",&id,0,9999,3);

    if(retorno == 0)
    {
        if(movies_find(pMovies,length,id)==NULL)
        {
            printf("El Id ingresado no existe\n");


        }
        else
        {
            retorno=movies_remove(pMovies,length,id);
        }
    }
    return retorno;
}


void controller_mock(sMovie* pMovies,int length)
{
    movies_append(pMovies,length,"Batman","Accion",180,"La primera edicion de la saga de batman",9);
    movies_append(pMovies,length,"Superman 2","Accion",150,"La segunda entrega",8);

}
/** \brief Muestra el listado de los titulos de las peliculas cargadas
 * \param sMovie* pMovies Puntero al array de peliculas
 * \param length int Longitud del array
 * \return Void
 */

void controller_listarMovie(sMovie* pMovies,int length)
{
    int i;

    if(pMovies != NULL && length>0)
    {
        printf("NOMBRE PELICULA\n");
        for(i=0;i<length;i++)
        {
            if((pMovies+i)->flagEstado==MOVIE_USED)
            {
                printf("%s\n",(pMovies+i)->titulo);
            }
        }
    }

}
/** \brief Genera un archivo HTML donde muestra el listado de peliculas con sus datos.
 * \param sMovie* pMovies Puntero al array de peliculas
 * \param length int Longitud del array
 * \return 0 si el archivo es valido o -1 si el archivo es NULL
 */


int controller_generarHtml(sMovie* pMovies,int length)
{
    int retorno=-1,i;
    char textoUno[]="<article class='col-md-4 article-intro'><a href='#'></a><h3><a href='#'>";
    char textoDos[]="</a></h3><ul><li>Género:";
    char textoTres[]="</li><li>Puntaje:";
    char textoCuatro[]="</li><li>Duración:";
    char textoCinco[]="</li></ul><p> ";
    char textoSeis[]="</p></article>";

    FILE* auxFile;

    auxFile=fopen("index.html","w");

    if(auxFile == NULL)
    {
        printf("No se pudo crear el archivo.\n");
    }
    else
    {
        for(i=0;i<length;i++)
        {
            if((pMovies+i)->flagEstado==MOVIE_USED)
            {
                fprintf(auxFile,"%s",textoUno);
                fprintf(auxFile,"%s",(pMovies+i)->titulo);
                fprintf(auxFile,"%s",textoDos);
                fprintf(auxFile,"%s",(pMovies+i)->genero);
                fprintf(auxFile,"%s",textoTres);
                fprintf(auxFile,"%d",(pMovies+i)->puntaje);
                fprintf(auxFile,"%s",textoCuatro);
                fprintf(auxFile,"%d",(pMovies+i)->duracion);
                fprintf(auxFile,"%s",textoCinco);
                fprintf(auxFile,"%s",(pMovies+i)->descripcion);
                fprintf(auxFile,"%s",textoSeis);

            }



        }

        fclose(auxFile);
        retorno=0;
    }

    return retorno;

}
/** \brief Carga el archivo de datos con la informacion del array de peliculas
 * \param sMovie* pMovies Puntero al array de peliculas
 * \param length int Longitud del array
 * \return Void
 */


void controller_cargarArchivo(sMovie* pMovies, int length)
{
    FILE* auxFile;
    int i;


    auxFile=fopen("movie.dat","r");

    if(auxFile == NULL)
    {
        printf("No existe el archivo.\n");


    }
    else
    {
        for(i=0;i<length;i++)
        {
            fread((pMovies+i),sizeof(sMovie),1, auxFile);
        }

        }


}
/** \brief Guarda el archivo de datos con la informacion actualizada del array de peliculas
 * \param sMovie* pMovies Puntero al array de peliculas
 * \param length int Longitud del array
 * \return Void
 */

void controller_guardarArchivo(sMovie* pMovie,int length)
{
    FILE* auxFile;
    auxFile=fopen("movie.dat","w");

    if(auxFile==NULL)
    {
        printf("No se pudo guardar el archivo.\n");

    }
    else
    {
        fwrite(pMovie,sizeof(sMovie),length,auxFile);

    }

    fclose(auxFile);

}
/** \brief Muestra los Id de las peliculas dadas de alta
 * \param sMovie* pMovies Puntero al array de peliculas
 * \param length int Longitud del array
 * \return 0 Si esta todo bien 0 -1 si el puntero es NULL
 */

int controller_verID(sMovie* pMovie,int length)
{
    int i;
    int retorno=-1;

    if(pMovie != NULL && length > 0)
    {
        printf("ID\t\tTITULO\n");
        for(i=0;i<length;i++)
        {
            if((pMovie+i)->flagEstado==MOVIE_USED)
            {
                printf("%d\t\t%s\n",(pMovie+i)->idMovie,(pMovie+i)->titulo);
            }
        }
    retorno=0;
    }

    return retorno;
}


