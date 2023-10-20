#ifndef NUM_H_INCLUDED
#define NUM_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ContarLineasArchivoPositivo(char nombreArchivo[40]);
int *crearVectorEnteros(int tam);
void recuperaNumerosPorLineaPositivos(char nombreArchivo[], int *vectorNumeros, int cantNumeros);
void mostrarVectorEnteros(int *ptrVec, int tam);
void guardarVectorEntero(char nombreArchivo[], int *vectorNumeros, int cantNumeros);
////Se agrega fusionar vectores
void fusionarVectoresEnteros(int* vectorResultado,int tamVectorResultado,int* vector1,int tamVector1, int* vector2  );


#endif // NUM_H_INCLUDED
