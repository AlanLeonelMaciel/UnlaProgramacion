#ifndef LISTAPREGUNTAS_H_INCLUDED
#define LISTAPREGUNTAS_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include "Juego.h"
#include "nodoListaPreguntas.h"

struct Lista {
    struct nodo *inicio;
};
typedef struct Lista *listaPtr;

PreguntaPtr CrearPregunta();
listaPtr crearLista();
void mostrarLista(listaPtr lista);
void agregarPreguntListaPrimero(listaPtr nuevaLista, PreguntaPtr PreguntaAux);

#endif // LISTAPREGUNTAS_H_INCLUDED
