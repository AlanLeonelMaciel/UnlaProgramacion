#include <stdio.h>
#include <stdlib.h>
#include "Lista.h"
struct nodo{
    int dato;
    struct nodo *siguiente;
};

typedef struct nodo *nodoPtr;

nodoPtr crearNodo(int dato, listaPtr lista ) {
    nodoPtr nuevoNodo;
    nuevoNodo=(nodoPtr)malloc(sizeof(struct nodo));
    if(lista->inicio==NULL){
        nuevoNodo->dato=dato;
        nuevoNodo->siguiente=NULL;
    }
    else{
        nuevoNodo->dato=dato;
        nuevoNodo->siguiente=lista->inicio;
    }
    lista->inicio=nuevoNodo;
    return nuevoNodo;
};
