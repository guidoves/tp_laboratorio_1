#include "funciones.h"

float ingresarNumero(char mensaje[])
{
    float numero;
    printf("%s",mensaje);
    scanf("%f",&numero);

    return numero;


}

/**
* \brief Pide un numero al usuario y lo devuelve
* \param Recibe un mensaje para ser mostrado.
* \return Devuelve le numero ingresado por el usuario.
*
*/



int menu(char texto[],int opcionMin,int opcionMax)
{
    int opcion;
    printf("%s",texto);
    scanf("%d",&opcion);
    while(opcion < opcionMin || opcion > opcionMax)
    {
        printf("Opcion inválida.\nIngrese: ");
        scanf("%d",&opcion);
    }

    return opcion;
}

/**
* \brief Cumple la funcion de menu. devuelve una opcion.
* \param texto. Pide el cuerpo del menu
* \param opcionMin. Es el rango minimo de opcion del menu.
* \param opcionMax. Es el rango maximo de opcion del menu.
* \return Devuelve la opcion elegida por el usuario.
*
*/


float sumarNumeros(float numero1,float numero2)
{
   float resultado;

   resultado=numero1+numero2;

    return resultado;
}

/**
* \brief Realiza la suma de dos numeros.
* \param Son los dos operandos.
* \return Devuelve el resultado de la suma.
*
*/


float restarNumeros(float numero1,float numero2)
{
    float resultado;

    resultado=numero1-numero2;

    return resultado;

}

/**
* \brief Realiza la resta de dos numeros.
* \param Son los dos operandos.
* \return Devuelve el resultado de la resta.
*
*/


float dividirNumeros(float numero1,float numero2)
{

    float resultado=0;

    if(numero2==0)
    {
        printf("No se puede realizar una division por 0.");

    }
    else
    {
        resultado=numero1/numero2;
    }

    return resultado;

}

/**
* \brief Realiza una division entre dos numeros
* \param Son los operandos ( el segundo no debe ser 0.)
* \return Devuelve el resultado de la division.
*
*/


float multiplicarNumeros(float numero1,float numero2)
{
    int resultado;

    resultado=numero1*numero2;

    return resultado;
}

/**
* \brief Realiza la multiplicacion de dos numeros.
* \param Son los dos operandos.
* \return Devuelve el resultado de la multiplicacion.
*
*/


int calcularFactorial(int numero1, float aux)
{
    if(numero1 != aux)
    {
        return -1;
    }

    if(numero1 == 0)
    {
        return 1;
    }

    int resultado=1;
    int factorial;
    factorial=numero1;

    while(factorial>1)
    {
        resultado=resultado*factorial;
        factorial--;
    }

    return resultado;

    /**
* \brief Realiza el factorial de un numero
* \param Es el operando
* \param Es un parametro auxiliar para verificar que el numero ingresado es o no de punto flotante
* \return Devuelve el factorial del numero.
*
*/


}
