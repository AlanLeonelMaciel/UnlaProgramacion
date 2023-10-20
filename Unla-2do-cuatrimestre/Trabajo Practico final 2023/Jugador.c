#include "jugador.h"

JugadorPtr crearJugador(int dni, char alias[100],ListaPreguntasPtr preguntas, PuntosPtr puntos){
    JugadorPtr j;
    j=(JugadorPtr)malloc(sizeof(struct Jugador));
    strcpy(j->alias,alias);
    j->dni=dni;
    j->preguntas=preguntas;
    j->Puntos=puntos;
    return j;
};
void destruirJugador(JugadorPtr j){
    free(j);
};
void mostrarJugador (JugadorPtr j){
    //printf("\nAlias del jugador: %s Dni: %d Puntuacion actual: %d Puntuacion maxima historica: %d\n",j->alias,j->dni,j->Puntos->actuales,j->Puntos->puntuacionMax);
    printf("\n***************************************\n");
    printf("*  Alias del jugador: %-16s*\n", j->alias);
    printf("*  DNI: %10d                    *\n", j->dni);
    printf("*  Puntuacion actual: %5d           *\n", j->Puntos->actuales);
    printf("*  Puntuacion maxima historica: %5d *\n", j->Puntos->puntuacionMax);
    printf("***************************************\n");
};
char* getAlias(JugadorPtr j){
    return j->alias;
}
int getDni(JugadorPtr j){
    return j->dni;
}
ListaPreguntasPtr getPreguntas(JugadorPtr j){
    return j->preguntas;
}
PuntosPtr getPuntos(JugadorPtr j){
    return j->Puntos;
};
void setAlias(JugadorPtr j, char nuevoNombre[100]){
    strcpy(j->alias,nuevoNombre);
};
void setEdad(JugadorPtr j, int nuevaEdad){
    j->dni=nuevaEdad;
};
void setPreguntas (JugadorPtr j, ListaPreguntasPtr preguntas){
    j->preguntas=preguntas;
};
void setPuntos(JugadorPtr j, PuntosPtr puntos){
    j->Puntos=puntos;
};

