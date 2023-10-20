#ifndef NUMEROS_H_INCLUDED
#define NUMEROS_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ContarLineasArchivoPositivo(char nombreArchivo[40]);
int *crearVectorEnteros(int tam);
void recuperaNumerosPorLineaPositivos(char nombreArchivo[], int *vectorNumeros, int cantNumeros);
void mostrarVectorEnteros(int *ptrVec, int tam);
void mostrarVectorEnteros(int *ptrVec, int tam);
void guardarVectorEntero(char nombreArchivo[], int *vectorNumeros, int cantNumeros);
void guardarVectorEnteroADD(char nombreArchivo[], int *vectorNumeros, int cantNumeros);
#endif // NUMEROS_H_INCLUDED
