#ifndef NODOLISTAPREGUNTAS_H_INCLUDED
#define NODOLISTAPREGUNTAS_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include "ListaPreguntas.h"
#include "Juego.h"
typedef struct Pregunta *PreguntaPtr;
struct nodo{
    PreguntaPtr pregunta;
    struct nodo *siguiente;
};

struct Lista;
typedef struct Lista *listaPtr;
typedef struct nodo *nodoPtr;

nodoPtr crearNodo(PreguntaPtr,listaPtr);
#endif // NODOLISTAPREGUNTAS_H_INCLUDED
