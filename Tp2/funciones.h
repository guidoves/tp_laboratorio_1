 #ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#define ITEMS 20

typedef struct {

    char nombre[50];
    int edad;
    int estado;
    int dni;

}EPersona;

void ordenarListar(EPersona miPersona[],int largo);
int agregarPersona(EPersona miPersona[],int valor);
int setArray(EPersona miPersona[],int largo,int valor);
int borrarPersona(EPersona miPersona[],int largo);
void graficoEdades (EPersona miPersona [], int largo);
int obtenerEspacioLibre(EPersona lista[],int largo);
int chequearActivos(EPersona lista[],int largo);

#endif // FUNCIONES_H_INCLUDED
