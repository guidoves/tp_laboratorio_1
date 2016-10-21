#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "controller.h"
#include "movie.h"
#define CANTIDAD 10

int main()
{
    char seguir='s';
    FILE* pFile;
    sMovie arrayMovies[CANTIDAD];

    controller_cargarArchivo(arrayMovies,CANTIDAD);

    //movies_init(arrayMovies,CANTIDAD);
    //controller_mock(arrayMovies,CANTIDAD);
    //controller_guardarArchivo(arrayMovies,CANTIDAD);



    while(seguir =='s')
    {

        switch(menu("1- AGREGAR PELICULA\n2- BORRAR PELICULA\n3- MODIFICAR PELICULA\n4- GENERAR PAGINA WEB\n5- LISTAR\n6- SALIR\n",1,6))
        {
            case 1:
                controller_altaMovie(arrayMovies,CANTIDAD);
                controller_guardarArchivo(arrayMovies,CANTIDAD);
                break;
            case 2:
                controller_verID(arrayMovies,CANTIDAD);
                controller_bajaMovie(arrayMovies,CANTIDAD);
                controller_guardarArchivo(arrayMovies,CANTIDAD);
                break;
            case 3:
                controller_verID(arrayMovies,CANTIDAD);
                controller_modificarMovie(arrayMovies,CANTIDAD);
                controller_guardarArchivo(arrayMovies,CANTIDAD);
               break;
            case 4:
                controller_generarHtml(arrayMovies,CANTIDAD);
                break;
            case 5:
                controller_listarMovie(arrayMovies,CANTIDAD);
                break;
            case 6:
                seguir = 'n';
                break;
        }
        printf("Pulse una tecla para continuar...");
        pause();
        system("clear");
    }

    return 0;
}
