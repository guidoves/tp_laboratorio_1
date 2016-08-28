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
    int opcion=0;
    int numero1=0;
    int numero2=0;
    printf("Bienvenido!\n");

    while(seguir=='s')
    {
        printf("1- Ingresar 1er operando (A=%d)\n",numero1);
        printf("2- Ingresar 2do operando (B=%d)\n",numero2);
        printf("3- Calcular la suma (A+B)\n");
        printf("4- Calcular la resta (A-B)\n");
        printf("5- Calcular la division (A/B)\n");
        printf("6- Calcular la multiplicacion (A*B)\n");
        printf("7- Calcular el factorial (A!)\n");
        printf("8- Calcular todas las operaciones\n");
        printf("9- Salir\n");
        printf("Opcion: ");
        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
            printf("Ingrese el 1er operando: ");
            scanf("%d",&numero1);

                break;

            case 2:
            printf("Ingrese el 2do operando: ");
            scanf("%d",&numero2);

                break;
            case 3:
            printf("Resultado: %d\n",sumarNumeros(numero1,numero2));

                break;

            case 4:
            printf("Resultado: %d\n",restarNumeros(numero1,numero2));

                break;

            case 5:
            printf("Resultado: %f\n",dividirNumeros((float)numero1,numero2));

                break;

            case 6:
            printf("Resultado: %d\n",multiplicarNumeros(numero1,numero2));

                break;

            case 7:
            printf("Resultado: %d\n",calcularFactorial(numero1));

                break;

            case 8:

                if(numero2!=0)
                {
                    printf("Suma: %d\n",sumarNumeros(numero1,numero2));
                    printf("Resta: %d\n",restarNumeros(numero1,numero2));
                    printf("Division: %f\n",dividirNumeros((float)numero1,numero2));
                    printf("Producto: %d\n",multiplicarNumeros(numero1,numero2));
                    printf("Factorial: %d\n",calcularFactorial(numero1));
                }
                else
                {
                    printf("Suma: %d\n",sumarNumeros(numero1,numero2));
                    printf("Resta: %d\n",restarNumeros(numero1,numero2));
                    printf("Producto: %d\n",multiplicarNumeros(numero1,numero2));
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
            system("clear");

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
