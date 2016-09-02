#include "funciones.h"
float ingresarNumero()
{
    float numero;
    printf("Ingrese un numero: ");
    scanf("%f",&numero);

    return numero;


}

int menu()
{
    int opcion;
        printf("1- Ingresar 1er operando (A=%s)\n","A");
        printf("2- Ingresar 2do operando (B=%s)\n","B");
        printf("3- Calcular la suma (A+B)\n");
        printf("4- Calcular la resta (A-B)\n");
        printf("5- Calcular la division (A/B)\n");
        printf("6- Calcular la multiplicacion (A*B)\n");
        printf("7- Calcular el factorial (A!)\n");
        printf("8- Calcular todas las operaciones\n");
        printf("9- Salir\n");
        printf("Opcion: ");
        scanf("%d",&opcion);

        return opcion;
}

float sumarNumeros(float numero1,float numero2)
{
   float resultado;

   resultado=numero1+numero2;

    return resultado;
}

float restarNumeros(float numero1,float numero2)
{
    float resultado;

    resultado=numero1-numero2;

    return resultado;

}

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

float multiplicarNumeros(float numero1,float numero2)
{
    int resultado;

    resultado=numero1*numero2;

    return resultado;
}

int calcularFactorial(int numero1)
{
    int resultado=1;
    int factorial;
    factorial=numero1;

    while(factorial>1)
    {
        resultado=resultado*factorial;
        factorial--;
    }

    return resultado;

}
