#ifndef PREGUNTA_H_INCLUDED
#define PREGUNTA_H_INCLUDED
#include "Respuesta.h"
#include "ListaRespuestas.h"

struct Pregunta {
    int nroPregunta;
    char pregunta[100];
    listaRespuestasPtr respuestasPosibles;
};
// puntero a datos
typedef struct Pregunta* PreguntaPtr;

// Primitivas
//metodos
PreguntaPtr crearPregunta(int numeroPregunta, char pregunta[100],listaRespuestasPtr respuestasPosibles);
void destruirPregunta(PreguntaPtr p);
void mostrarPregunta (PreguntaPtr p);
listaRespuestasPtr obtenerRespuestasPosibles(listaRespuestasPtr respuestas,int nroPregunta);
//getters
char* getPregunta(PreguntaPtr p);
int getNumeroPregunta(PreguntaPtr p);
listaRespuestasPtr getRespuestasPosibles(PreguntaPtr p);
//setters
void setPregunta(PreguntaPtr p, char nuevaPregunta[100]);
void setNumeroPregunta(PreguntaPtr p, int numeroPregunta);
void setRespuestasPosibles(PreguntaPtr p, listaRespuestasPtr listaRespuestasPosibles);

#endif // PREGUNTA_H_INCLUDED
