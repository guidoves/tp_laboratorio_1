#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include "util.h"
#define ITEMS 20

struct Persona
 {

    char nombre[ITEMS][50];
    int edad[ITEMS];
    int estado[ITEMS];
    int dni[ITEMS][30];

};


int main()
{

    struct Persona miPersona;
    int i,flag1=0;
    char seguir='s';


    for(i=0;i<ITEMS;i++)
    {
        miPersona.estado[i]=0;
    }


    while(seguir=='s')
    {

        switch(menu("1- Agregar persona\n2- Borrar persona\n3- Imprimir lista ordenada por nombre\n4- Imprimir grafico de edades\n5- Salir\n",1,5))
        {
            case 1:

            for(i=0;i<ITEMS;i++)
            {
                if(miPersona.estado[i]==0)
                {
                    if(agregarPersona(&miPersona.nombre[i],&miPersona.dni[i],&miPersona.edad[i])==0)
                    {
                        flag1=1;

                        break;

                    }
                    else
                    {
                        miPersona.estado[i]=1;
                        flag1=1;

                        break;
                    }

                }

            }

            if(flag1==0)
            {
                printf("No hay campos vacios para el ingreso.");
            }

            flag1=0;

            break;



            case 2:
                break;
            case 3:

                printf("NOMBRE----------DNI----------EDAD\n");
                    for(i=0;i<ITEMS;i++)
                    {
                        if(miPersona.estado[i]!=0)
                        {
                            printf("%s----------%s----------%d\n",miPersona.nombre[i],miPersona.dni[i],miPersona.edad[i]);
                        }


                    }

                break;
            case 4:
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
