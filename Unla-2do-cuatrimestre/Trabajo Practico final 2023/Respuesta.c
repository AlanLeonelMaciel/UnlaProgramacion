#include "Respuesta.h"

respuestaPtr crearRespuesta (int nroRespuesta, char respuesta[100],int nroPreguntaAsociada,int correcta){
    respuestaPtr r;
    r=(respuestaPtr)malloc(sizeof(struct Respuesta));
    r->nroRespuesta=nroRespuesta;
     strcpy(r->respuesta,respuesta);
     r->nroPreguntaAsociada=nroPreguntaAsociada;
     r->correcta=correcta;
    return r;
};
void destruirRespuesta(respuestaPtr r){
    free(r);
};
void mostrarRespuesta (respuestaPtr r){

    printf("\n%d)", r->nroRespuesta);
    printf(" Respuesta: %s\n", r->respuesta);
   // printf("Numero de pregunta asociada: %d\n", r->nroPreguntaAsociada);
   /* if(r->correcta){
        printf("Es correcta\n");
    } else{
        printf("Es Falsa\n");
    }*/

};
char* getRespuesta(respuestaPtr r){
    return r->respuesta;
};
int getNroRespuesta(respuestaPtr r){
    return r->nroRespuesta;
};
int getNroPreguntaAsociada(respuestaPtr r){
    return r->nroPreguntaAsociada;
};
int getCorrecta (respuestaPtr r){
    return r->correcta;
};
//Setters
void setRespuesta(respuestaPtr r, char respuesta[100]){
     strcpy(r->respuesta,respuesta);
};
void setNroRespuesta(respuestaPtr r , int nro) {
    r->nroRespuesta = nro;
};
void setNroPreguntaAsociada(respuestaPtr r , int nro) {
    r->nroPreguntaAsociada = nro;
}
void setCorrecta(respuestaPtr r , int esCorrecta) {
    r->correcta = esCorrecta;
}
