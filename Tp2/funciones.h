#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#define ITEMS 20
void ordenarListar(char *nombre[],char *dni[],int *edad[],int items);
int agregarPersona(char *nombre[],char *dni[],int *edad[]);

typedef struct {

    char nombre[ITEMS][50];
    int edad[ITEMS];
    int estado[ITEMS];
    int dni[ITEMS][20];

}EPersona;

/**
 * Obtiene el primer indice libre del array.
 * @param lista el array se pasa como parametro.
 * @return el primer indice disponible
 */
int obtenerEspacioLibre(EPersona lista[]);

/**
 * Obtiene el indice que coincide con el dni pasado por parametro.
 * @param lista el array se pasa como parametro.
 * @param dni el dni a ser buscado en el array.
 * @return el indice en donde se encuentra el elemento que coincide con el parametro dni
 */
int buscarPorDni(EPersona lista[], int dni);

#endif // FUNCIONES_H_INCLUDED
