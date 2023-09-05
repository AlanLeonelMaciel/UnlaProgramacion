#ifndef MILISTA_H_INCLUDED
#define MILISTA_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

struct Lista {
    struct nodo *inicio;
};
typedef struct Lista *listaPtr;

listaPtr crearLista();
void mostrarLista(listaPtr lista);
void agregarNumListaPrimero(listaPtr nuevaLista, int numero);

#endif // MILISTA_H_INCLUDED
