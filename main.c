/********************************************************
*Programa: Trabajo practico 1
*
*Objetivo: Hacer una calculadora.
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

        switch(menu("1- Ingresar 1er operando (A=x)\n2- Ingresar 2do operando (B=y)\n3- Calcular la suma (A+B)\n4- Calcular la resta (A-B)\n5- Calcular la division (A/B)\n6- Calcular la multiplicacion (A*B)\n7- Calcular el factorial (A!)\n8- Calcular todas las operaciones\n9- Salir\nOpcion: ",1,9))
        {
            case 1:
            numero1=ingresarNumero("Ingrese el 1er operando: ");

                break;

            case 2:
            numero2=ingresarNumero("Ingrese el 2do operando: ");

                break;

            case 3:
            printf("Resultado: %f\n",sumarNumeros(numero1,numero2));

                break;

            case 4:
            printf("Resultado: %f\n",restarNumeros(numero1,numero2));

                break;

            case 5:
            printf("Resultado: %f\n",dividirNumeros(numero1,numero2));

                break;

            case 6:
            printf("Resultado: %f\n",multiplicarNumeros(numero1,numero2));

                break;

            case 7:

            if(calcularFactorial(numero1,numero1)==-1)
            {
                printf("El factorial se debe calcular sobre un entero positivo.\n");

                break;
            }

            printf("Resultado: %d\n",calcularFactorial(numero1,numero1));

                break;

            case 8:

                if(numero2!=0 && calcularFactorial(numero1,numero1) != -1)
                {
                    printf("Suma: %f\n",sumarNumeros(numero1,numero2));
                    printf("Resta: %f\n",restarNumeros(numero1,numero2));
                    printf("Division: %f\n",dividirNumeros(numero1,numero2));
                    printf("Producto: %f\n",multiplicarNumeros(numero1,numero2));
                    printf("Factorial: %d\n",calcularFactorial(numero1,numero1));
                }
                else
                {
                    printf("Suma: %f\n",sumarNumeros(numero1,numero2));
                    printf("Resta: %f\n",restarNumeros(numero1,numero2));
                    printf("Producto: %f\n",multiplicarNumeros(numero1,numero2));
                    printf("El factorial se debe calcular sobre un entero positivo.\n");
                    printf("No existe la division por 0.\n\n");

                }

                break;

            case 9:
                seguir = 'n';
                break;
        }
        printf("Presione una tecla para continuar...");
        getchar();
        getchar();
        system("clear");
        printf("1er operando: %.2f\n",numero1);
        printf("2do operando: %.2f\n",numero2);

    } //fin while(seguir=='s')
    return 0;
} // fin main
