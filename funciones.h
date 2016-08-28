#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED



#endif // FUNCIONES_H_INCLUDED


int sumarNumeros(int numero1,int numero2)
{
   int resultado;

   resultado=numero1+numero2;

    return resultado;
}

int restarNumeros(int numero1,int numero2)
{
    int resultado;

    resultado=numero1-numero2;

    return resultado;

}

float dividirNumeros(float numero1,int numero2)
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

int multiplicarNumeros(int numero1,int numero2)
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

