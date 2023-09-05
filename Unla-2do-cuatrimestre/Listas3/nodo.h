#ifndef NODO_H_INCLUDED
#define NODO_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include "miLista.h"
struct nodo{
    int dato;
    struct nodo *siguiente;
};
struct Lista;
typedef struct Lista *listaPtr;
typedef struct nodo *nodoPtr;

nodoPtr crearNodo(int dato, listaPtr);

#endif // NODO_H_INCLUDED
