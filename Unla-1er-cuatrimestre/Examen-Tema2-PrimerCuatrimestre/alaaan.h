#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int PedirEnteroCondicion();
int GenerarAleatorioInt(int desde, int hasta);
int CargarArregloAleatoriamenteInt(int array[], int tam, int desde, int hasta);
void MostrarArregloInt(int arreglo[],int tam);
void MostrarArregloInvertido(int arreglo[],int tam);
void MostrarPromedioDivisiblesPor(int arreglo[], int tam, int numero);
int CargarArregloAleatoriamenteIntPares(int array[], int tam, int desde, int hasta);
void  MostrarArregloIntPosImpares(int arreglo[],int tam);
void MostrarElMayorDeLosNumerosMenoresA(int arreglo[],int tam);
void DibujarTriangunlo(int base, char letra);
//PRE: mini debe ser menor que maxi y el tama�o mayor a cero. Tam debe ser mayor a maxi - mini
//POST: se sobreescriben los valores del vector v con valores aleatorios entre mini y maxi, sin repetidos
void cargarVectorConAleatoriosSinRepetir(int v[], int tam, int mini,int maxi);
//PRE: El tama�o que ingresa el usuario debe ser mayor a cero en caso que se use este tama�o
//para un vector o figura
//POST: Se devulve un entero
int elegirTamanio();
