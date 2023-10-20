#ifndef PUNTOS_H_INCLUDED
#define PUNTOS_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ManejoDinamico.h"

struct Puntos {
    int codPuntuacion;
    int actuales;
    int puntuacionMax;
};
// Puntero a datos
typedef struct Puntos* PuntosPtr;
//constructor
PuntosPtr crearPuntos(int cod, int actuales, int puntuacionMax);
// metodos
int recuperarPuntosMaxDni(int dni, int **rankingMatriz, int filas);

//getters
int getActuales(PuntosPtr puntos);
int getCodPuntuacion(PuntosPtr puntos);
int getPuntuacionMaxima(PuntosPtr puntos);

//setters

void setActuales(PuntosPtr puntos, int actuales);
void setCodPuntuacion(PuntosPtr puntos, int cod);
void setPuntuacionMaxima(PuntosPtr puntos, int maxima);
#endif // PUNTOS_H_INCLUDED
