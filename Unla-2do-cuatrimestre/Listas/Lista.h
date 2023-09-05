#include <stdio.h>
#include <stdlib.h>
#include "Lista.c"
struct Lista {
    struct nodo *inicio;
};
typedef struct Lista *listaPtr;

listaPtr crearLista();
void mostrarLista(listaPtr lista);
