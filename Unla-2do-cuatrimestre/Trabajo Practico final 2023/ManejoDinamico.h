#ifndef MANEJODINAMICO_H_INCLUDED
#define MANEJODINAMICO_H_INCLUDED
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int **crearMatrizEnteros(int filas, int columnas);
void InicializarMatrizCeros(int **ptrMatriz, int filas, int columnas);
void liberarMemoriaMatriz(int **ptrMatriz, int filas);
//Archivos
int contarFilasArchivo(char *nombreArchivo); //Si devuelve -1 es porque hubo error al abrir archivo
void escribirMatrizRankingEnArchivo(int** matriz, int filas, int columnas, const char* nombreArchivo);
// los numeros de filas y columnas se actualizaran solos.
void asignarFilasColumnasArchivo(char *nombreArchivo,int *filas, int *columnas,char *delimitador);

void recuperarNumerosPorLineaArchivo(char *nombreArchivo, int **numerosLinea, int filas);
void escribirMatrizEnArchivo(char *nombreArchivo, int **matriz, int filas, int columnas);
void mostrarMatrizEnteros(int **matriz, int filas, int columnas);
int** unirMatricesVert(int** matriz1, int filas1, int columnas, int** matriz2, int filas2);
void eliminarDnisMatriz(int*** matriz, int* filas, int columnas, int* dnis, int cantJugadores);
int GenerarAleatorioInt(int desde, int hasta);
void intercambiarFilas(int** ranking, int fila1, int fila2);
void ordenarPorPuntajeMasAlto(int** ranking, int filas);

#endif // MANEJODINAMICO_H_INCLUDED
