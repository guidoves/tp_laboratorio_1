/********************************************************
*Programa: Trabajo practico 1
*
*Objetivo: Hacer una calculadora segun las indicaciones.
*
*Versión: 0.1 27 de agosto del 2016.
*Autor: Guido Vespignani.
*
********************************************************/


#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"


int main()
{
    char seguir='s';
    float numero1=0;
    float numero2=0;
    printf("Bienvenido!\n");

    while(seguir=='s')
    {

        switch(menu())
        {
            case 1:
            printf("Ingrese el 1er operando: ");
            scanf("%f",&numero1);

                break;

            case 2:
            printf("Ingrese el 2do operando: ");
            scanf("%f",&numero2);

                break;
            case 3:
            printf("Resultado: %f\n",sumarNumeros(numero1,numero2));

                break;

            case 4:
            printf("Resultado: %d\n",restarNumeros(numero1,numero2));

                break;

            case 5:
            printf("Resultado: %f\n",dividirNumeros(numero1,numero2));

                break;

            case 6:
            printf("Resultado: %f\n",multiplicarNumeros(numero1,numero2));

                break;

            case 7:
            printf("Resultado: %d\n",calcularFactorial(numero1));

                break;

            case 8:

                if(numero2!=0)
                {
                    printf("Suma: %f\n",sumarNumeros(numero1,numero2));
                    printf("Resta: %f\n",restarNumeros(numero1,numero2));
                    printf("Division: %f\n",dividirNumeros(numero1,numero2));
                    printf("Producto: %f\n",multiplicarNumeros(numero1,numero2));
                    printf("Factorial: %d\n",calcularFactorial(numero1));
                }
                else
                {
                    printf("Suma: %f\n",sumarNumeros(numero1,numero2));
                    printf("Resta: %f\n",restarNumeros(numero1,numero2));
                    printf("Producto: %f\n",multiplicarNumeros(numero1,numero2));
                    printf("Factorial: %d\n",calcularFactorial(numero1));
                    printf("No existe la division por 0.\n\n");

                }

                break;

            case 9:
                seguir = 'n';
                break;

            default:
                printf("Opcion invalida.");


        }

        if(opcion != 9)
        {
            printf("Pulse enter para continuar");
            getchar();
            while(getchar() != '\n');
            system("cls");

        }
        else
        {

            printf("Hasta luego!");
            getchar();
            while(getchar() != '\n');

        }



    } //fin while(seguir=='s')
    return 0;
} // fin main
