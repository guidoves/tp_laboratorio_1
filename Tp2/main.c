#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include "util.h"
#define ITEMS 20
#define VACIO 0
#define ACTIVO 1


int main()
{

    EPersona miPersona[ITEMS];
    int i,aux;
    char seguir='s';


    setArray(miPersona,ITEMS,VACIO);


    while(seguir=='s')
    {

        switch(menu("1- Agregar persona\n2- Borrar persona\n3- Imprimir lista ordenada por nombre\n4- Imprimir grafico de edades\n5- Salir\n",1,5))
        {
            case 1:

                aux=obtenerEspacioLibre(miPersona,ITEMS);

                if(aux != -1)
                {
                    agregarPersona(miPersona,aux);
                }
                else
                {
                    printf("No hay campos vacios para el ingreso.\n");
                }

            break;

            case 2:

                aux=chequearActivos(miPersona,ITEMS);

                if(aux==1)
                {
                    ordenarListar(miPersona,ITEMS);
                    borrarPersona(miPersona,ITEMS);
                }
                else
                {
                    printf("Todos los campos estan vacios\n");
                }

                break;

            case 3:

                ordenarListar(miPersona,ITEMS);

                break;
            case 4:

                graficoEdades(miPersona,ITEMS);

                break;
            case 5:
                seguir = 'n';
                break;

        }

        printf("Precione una tecla para continuar...");
        flush_in();
        system("clear");

    }

    return 0;
}
