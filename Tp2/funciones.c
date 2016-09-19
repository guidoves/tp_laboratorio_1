#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "funciones.h"
#include "util.h"
void ordenarListar(char *nombre[],char *dni[],int *edad[],int items)
{
    int i,j,auxInt;
    char auxChar[]={};

    for(i=0;i<items;i++)
    {
        for(j=i+1;j<items;j++)
        {
            if(strcasecmp(nombre[i],nombre[j])>0)
            {
                strcpy(auxChar,nombre[i]);
                strcpy(nombre[i],nombre[j]);
                strcpy(nombre[j],auxChar);

                strcpy(auxChar,dni[i]);
                strcpy(dni[i],dni[j]);
                strcpy(dni[j],auxChar);

                auxInt=edad[i];
                edad[i]=edad[j];
                edad[j]=auxInt;

            }
        }
    }
    printf("NOMBRE----------DNI----------EDAD");
    for(i=0;i<items;i++)
    {
        printf("%s----------%s----------%d",nombre[i],dni[i],edad[i]);

    }
}

int agregarPersona(char *nombre[],char *dni[],int *edad[])
{
    int auxEdad; // Auxiliar para almacenar temporalmente la edad
    char buffer[500]; // buffer para validar los datos que ingresa el usuario
    char auxNombre[500]; // auxialiar para almacenar temporalmente el nombre
    char auxDni[500]; // auxiliar para almacenar temporalmente el dni
    char respuesta; // variable para guardar la respuesta de confirmacion
    int ok; //  variable para validar el ingreso de la respuesta (doble validacion)


    printf("Ingrese el NOMBRE: "); // pide el nombre y lo guarda en el auxiliar
    gets(auxNombre);
    while(validarString(auxNombre,3,50)!=1) // verifica que sea un string entre 3 y 50 caracteres
    {
        printf("Ingreso invalido. Escriba el nombre (3 a 50 caracteres)\n");
        printf("Ingrese el NOMBRE: ");
        gets(auxNombre);

    }


    printf("Ingrese el DNI: "); // pide el dni
    gets(auxDni);
    while(validarString(auxDni,5,10)!=1) // verifica que sea un string entre 5 y 10 caracteres
    {
        printf("Ingreso invalido. Escriba el DNI (5 a 10 caracteres)\n");
        printf("Ingrese el DNI: ");
        gets(auxDni);
    }

    printf("Ingrese la EDAD: "); // ingresa la edad
    gets(buffer);

    while(validarInt(buffer)!= 1) // verifica que el usuario ingreso un entero
    {
        printf("Ingreso invalido. Escriba la EDAD (Solo numeros)\n");
        printf("Ingrese la edad: ");
        gets(buffer);
    }

    auxEdad=cadena_entero(buffer); //guarda los numeros del string en una variable tipo int
    printf("%d",auxEdad);



    printf("Usted esta por ingresar a: %s, con DNI nº %s y su edad es %d años.\n",auxNombre,auxDni,auxEdad);
    printf("¿Desea confirmar la operacion? s/n: ");
    gets(buffer);

    while(ok == 0) // Empieza la doble validacion de la respuesta.
    {
        while(validarChar(buffer)!=1) // valida que la entrada sea de un solo caracter
        {
            printf("Ingreso Invalido. (Escriba S o N)\n");
            printf("¿Desea confirmar la operacion? s/n: ");
            gets(buffer);
        }
        respuesta=buffer[0]; //guarda la respuesta en una variable char
        tolower(respuesta); // cambia el formato a minusculas
        if(respuesta == 's' || respuesta == 'n') // evalua si la respuesta es correcta
        {
            ok=1; // pasa la doble validacion.
        }
        else
        {
            strcpy(buffer,"123"); // cambia el valor del buffer pasa ser evualuado nuevamente
        }
    }


    if(respuesta == 's') // confirma la operacion . guarda los datos en los campos definitivos
    {
        strcpy(nombre,auxNombre);
        strcpy(dni,auxDni);
        *edad=auxEdad;

        return 1;

    }
    else
    {
        return 0;
    }


} // FIN agregarPErsona

/**
* \brief Funcion para agregar una persona con todos sus datos
* \param Recibe un puntero para guardar el nombre
* \param Recibe un puntero para guardar el dni
* \param Recibe un punturo para guardar la edad
* \return Devuele 1 si logro ingresar los datos y 0 si no los ingreso.
*
*/


