#include "Pregunta.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

PreguntaPtr crearPregunta (int numeroPregunta, char pregunta[100],listaRespuestasPtr respuestasPosibles){
    PreguntaPtr p;
    p=(PreguntaPtr)malloc(sizeof(struct Pregunta));
    p->nroPregunta=numeroPregunta;
    strcpy(p->pregunta,pregunta);
    p->respuestasPosibles=respuestasPosibles;
    return p;
};

void destruirPregunta(PreguntaPtr p){
    free(p);
};
void mostrarPregunta (PreguntaPtr p){
    //printf("\nNumero de pregunta: %d\n", p->nroPregunta);
    printf(" %20s \n", p->pregunta);
    printf("--------------------------------");
    printf("\n");
    mostrarListaRespuestas(p->respuestasPosibles);
};
char* getPregunta(PreguntaPtr p){
    return p->pregunta;
};
int getNumeroPregunta(PreguntaPtr p){
    return p->nroPregunta;
};
listaRespuestasPtr getRespuestasPosibles(PreguntaPtr p){
   return p->respuestasPosibles;
};
void setPregunta(PreguntaPtr p, char nuevaPregunta[100]){
    strcpy(p->pregunta,nuevaPregunta);
};
void setNumeroPregunta(PreguntaPtr p, int numeroPregunta){
    p->nroPregunta=numeroPregunta;
};
void setRespuestasPosibles(PreguntaPtr p, listaRespuestasPtr listaRespuestasPosibles){
    p->respuestasPosibles=listaRespuestasPosibles;
};

listaRespuestasPtr obtenerRespuestasPosibles(listaRespuestasPtr respuestas, int nroPregunta) {
    listaRespuestasPtr respuestasPosibles = crearListaRespuestas();

    if (respuestas->inicio != NULL) {
        nodoRespuestaPtr actual = respuestas->inicio;
        while (actual != NULL) {
            if (actual->respuesta->nroPreguntaAsociada == nroPregunta) {
                // Crea un nuevo nodo para la respuesta y luego inserta ese nodo
                //de otra manera siempre se estaria poniendo el mismo nodo
                nodoRespuestaPtr nuevoNodo = crearNodoRespuesta(actual->respuesta);
                insertarNodoRespuestaPrincipio(nuevoNodo, respuestasPosibles);
            }
            actual = actual->siguiente;
        }
    } else {
        printf("\nLa lista de respuestas está vacía.\n");
    }

    return respuestasPosibles;
};
