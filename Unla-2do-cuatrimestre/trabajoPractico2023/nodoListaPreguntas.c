#include <stdio.h>
#include <stdlib.h>
#include "nodoListaPreguntas.h"
nodoPtr crearNodo(PreguntaPtr pregunta1, listaPtr lista ) {
    nodoPtr nuevoNodo;
    nuevoNodo=(nodoPtr)malloc(sizeof(struct nodo));
    if(lista->inicio==NULL){
        nuevoNodo->pregunta=pregunta1;
        nuevoNodo->siguiente=NULL;
    }
    else{
        nuevoNodo->pregunta=pregunta1;
        nuevoNodo->siguiente=lista->inicio;
    }
    lista->inicio=nuevoNodo;
    return nuevoNodo;
};
