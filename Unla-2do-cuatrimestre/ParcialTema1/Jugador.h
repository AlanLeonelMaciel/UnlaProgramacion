#ifndef JUGADOR_H_INCLUDED
#define JUGADOR_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Jugador{
    char nombre[40];
    char apellido[40];
    int numCamiseta;
    float promGol;
    char club[40];
};
typedef struct Jugador* JugadorPtr;


JugadorPtr CrearJugador();
JugadorPtr CrearJugadores(int TAM);
struct Jugador LLenarJugador(char nombre[40],char apellido[40],int numCamiseta, float promedioGol,char club[40]);
void MostrarJugadores(int TAM, JugadorPtr);
int ContarLineasArchivo(char nombreArchivo[40]);
#endif // JUGADOR_H_INCLUDED
