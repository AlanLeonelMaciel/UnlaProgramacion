#ifndef JUGADOR_H_INCLUDED
#define JUGADOR_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Pregunta.h"
#include "Puntos.h"
#include "ListaPreguntas.h"
// Estructuras
struct Jugador{
char alias[100];
int dni;
ListaPreguntasPtr preguntas;
PuntosPtr Puntos;
};
//Puntero a los  datos
typedef struct Jugador * JugadorPtr;

// Primitivas
JugadorPtr crearJugador(int dni, char alias[100],ListaPreguntasPtr preguntas,PuntosPtr puntos);
void destruirJugador(JugadorPtr j);
void mostrarJugador (JugadorPtr j);
// Función para encontrar un jugador por su DNI en una lista de jugadores

//Getters
char* getAlias(JugadorPtr j);
int getDni(JugadorPtr j);
ListaPreguntasPtr getPreguntas(JugadorPtr j);
PuntosPtr getPuntos(JugadorPtr j);
// Setters
void setAlias(JugadorPtr j, char nuevoNombre[100]);
void setEdad(JugadorPtr j, int nuevaEdad);
void setPreguntas (JugadorPtr j, ListaPreguntasPtr preguntas);
void setPuntos(JugadorPtr j, PuntosPtr puntos);
#endif // JUGADOR_H_INCLUDED
