#ifndef LISTAPREGUNTAS_H_INCLUDED
#define LISTAPREGUNTAS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Pregunta.h"
#include <time.h>

struct nodoPregunta{
    PreguntaPtr pregunta;
    struct nodoPregunta *siguiente;
};
typedef struct nodoPregunta *nodoPreguntaPtr;

struct ListaPreguntas {
    nodoPreguntaPtr inicio;
};
typedef struct ListaPreguntas *ListaPreguntasPtr;

nodoPreguntaPtr crearNodoPregunta(PreguntaPtr pregunta);
ListaPreguntasPtr crearListaPreguntas();
void mostrarListaPreguntas(ListaPreguntasPtr lista);
void insertarNodoPreguntaPrincipio(nodoPreguntaPtr nuevoNodo, ListaPreguntasPtr lista);
void llenarListaPreguntasDedeTxt(ListaPreguntasPtr listaPreguntas,listaRespuestasPtr respuestas,char nombreArchivo[100]);
// Función para barajar la lista de preguntas
void barajarListaPreguntas(ListaPreguntasPtr listaPreguntas);
void liberarListaPreguntas(ListaPreguntasPtr listaPreguntas);

#endif // LISTAPREGUNTAS_H_INCLUDED
