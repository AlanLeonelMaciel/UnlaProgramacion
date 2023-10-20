#ifndef LISTARESPUESTAS_H_INCLUDED
#define LISTARESPUESTAS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Respuesta.h"

struct nodoRespuesta{
    respuestaPtr respuesta;
    struct nodoRespuesta *siguiente;
};
typedef struct nodoRespuesta *nodoRespuestaPtr;

struct ListaRespuestas {
    nodoRespuestaPtr inicio;
};
typedef struct ListaRespuestas *listaRespuestasPtr;

nodoRespuestaPtr crearNodoRespuesta(respuestaPtr respuesta);
listaRespuestasPtr crearListaRespuestas();
void mostrarListaRespuestas(listaRespuestasPtr lista);
void insertarNodoRespuestaPrincipio(nodoRespuestaPtr nuevoNodo, listaRespuestasPtr lista);
void llenarListaRespuestaDedeTxt(listaRespuestasPtr listaRespuestas, char nombreArchivo[100]);
void liberarListaRespuestas(listaRespuestasPtr listaRespuestas);

#endif // LISTARESPUESTAS_H_INCLUDED
