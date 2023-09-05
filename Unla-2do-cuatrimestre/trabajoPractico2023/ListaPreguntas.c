#include <stdio.h>
#include <stdlib.h>
#include "ListaPreguntas.h"
#include "nodoListaPreguntas.h"
listaPtr crearLista(){
    listaPtr nuevaLista=(listaPtr)malloc(sizeof(struct Lista));
    nuevaLista->inicio=NULL;
    return nuevaLista;
};
PreguntaPtr CrearPregunta(){
   PreguntaPtr pregunta1=(PreguntaPtr)malloc(sizeof(struct Pregunta));
   return pregunta1;
}

void mostrarLista(listaPtr lista){
    if (lista->inicio != NULL) {
        nodoPtr actual = lista->inicio;
        while (actual != NULL) {
            printf("\nEl numero de pregunta es: %d\nLa pregunta es: %s\n", actual->pregunta->nroPregunta,actual->pregunta->pregunta);
                        printf("\n Respuestas: \n");
            for(int i=0;i<4;i++){
                printf("\nRespuesta %d: %s\n",i+1,actual->pregunta->posibles[i]->respuesta);
            }
            actual = actual->siguiente;

        }
    } else {
        printf("\nLa lista esta vacia.\n");
    }

};

void agregarPreguntListaPrimero(listaPtr nuevaLista, PreguntaPtr PreguntaAux){

    nuevaLista->inicio=crearNodo(PreguntaAux,nuevaLista);
}
