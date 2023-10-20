#ifndef RESPUESTA_H_INCLUDED
#define RESPUESTA_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Respuesta{
    int nroRespuesta;
    char respuesta[100];
    int nroPreguntaAsociada;
    int correcta;
};
//puntero a los datos
typedef struct Respuesta *respuestaPtr;
// Primitivas
respuestaPtr crearRespuesta (int nroRespuesta, char respuesta[100],int nroPreguntaAsociada,int correcta);
void destruirRespuesta(respuestaPtr r);
void mostrarRespuesta (respuestaPtr r);

char* getRespuesta(respuestaPtr r);
int getNroRespuesta(respuestaPtr r);
int getNroPreguntaAsociada(respuestaPtr r);
int getCorrecta (respuestaPtr r);

void setRespuesta(respuestaPtr r, char respuesta[100]);
void setNroRespuesta(respuestaPtr r , int nro);
void setNroPreguntaAsociada(respuestaPtr r , int nro);
void setCorrecta(respuestaPtr r , int esCorrecta);
#endif // RESPUESTA_H_INCLUDED
