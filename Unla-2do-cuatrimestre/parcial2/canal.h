#ifndef CANAL_H_INCLUDED
#define CANAL_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Canal{
    char nombre[40];
    float rating;
    char tipo[40];

};
typedef struct Canal* CanalPtr;
void llenarStructDesdeArchivo(char nombreArchivo[40], CanalPtr nuevoCanal);
CanalPtr crearArrayCanales(int cantCanales);
int contarLineasArchivo(char nombreArchivo[40]);
void mostrarCanales(CanalPtr canales,int cantCanales);
int contarCanalesRatingMenor5(CanalPtr canales,int cantCanales);
//void modificarTxt(char** vectorStrings,int cantRatingMenor5);
CanalPtr guardarCanalesRatingMenor5(CanalPtr canales,int cantCanales,int cantRatingMenor5);
void guardarCanalesEliminados(CanalPtr canalesEliminados,int cantRatingMenor5);

#endif // CANAL_H_INCLUDED
