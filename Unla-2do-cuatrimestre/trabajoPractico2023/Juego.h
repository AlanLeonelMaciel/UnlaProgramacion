#ifndef JUEGO_H_INCLUDED
#define JUEGO_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include "ListaPreguntas.h"
#include "nodoListaPreguntas.h"
#define TAM 2
#define RESP 4
struct Respuesta{
    int nroRespuesta;
    char respuesta[100];
    int nroPreguntaAsociada;
    int correcta;

};
typedef struct Respuesta* RespuestaPtr;////////////////

struct Puntos {
    int codPuntuacion;
    int actuales;
    int puntuacionMax;
};
typedef struct Puntos* PuntosPtr;///////////////////

struct Pregunta {
    int nroPregunta;
    char pregunta[100];
    RespuestaPtr posibles[RESP];
};
typedef struct Pregunta* PreguntaPtr;/////////////////

struct Jugador {
    char *alias;
    int dni;
    struct Pregunta preguntasJuego[TAM];
    struct Puntos puntos;
};
typedef struct Jugador* JugadorPtr;//////////////////

struct Juego {
    struct Jugador* jugadores;
};
typedef struct Juego* JuegoPtr;//////////////////

////////////////////////////
//Interfaces:
///////////////////////////

char* CrearTexto(int caracteres);
void llenarListaArchivo(listaPtr);
void MostrarArchivo();
RespuestaPtr CrearRespuesta();
char* crearCadenaDinamica(int caracteres);

#endif // JUEGO_H_INCLUDED
