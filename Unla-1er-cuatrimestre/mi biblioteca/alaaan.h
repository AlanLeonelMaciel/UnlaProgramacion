#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int PedirEnteroCondicion();

int GenerarAleatorioInt(int desde, int hasta);

int CargarArregloAleatoriamenteInt(int array[], int tam, int desde, int hasta);

int CargarArregloAleatoriamenteIntPares(int array[], int tam, int desde, int hasta);

void MostrarArregloInt(int arreglo[],int tam);

void MostrarArregloInvertido(int arreglo[],int tam);

void MostrarPromedioDivisiblesPor(int arreglo[], int tam, int numero);

void MostrarArregloIntPosImpares(int arreglo[],int tam);

void MostrarElMayorDeLosNumerosMenoresA(int arreglo[],int tam);

void DibujarTriangunlo(int base, char letra);
//PRE: mini debe ser menor que maxi y el tama�o mayor a cero. Tam debe ser mayor a maxi - mini
//POST: se sobreescriben los valores del vector v con valores aleatorios entre mini y maxi, sin repetidos
void cargarVectorConAleatoriosSinRepetir(int v[], int tam, int mini,int maxi);
//PRE: El tama�o que ingresa el usuario debe ser mayor a cero en caso que se use este tama�o
//para un vector o figura
//POST: Se devulve un entero

//PRE: El tamanio que ingresa el usuario debe ser mayor a cero en caso que se use este tama�o
//para un vector o figura.
//POST: Se devulve un entero.
int elegirTamanio();

//PRE: El tamanio debe ser mayor a cero.
//POST: Se devuelve la posicion donde esta el valor minimo
//si el tamanio es menor a 1 se devuelve un -1
int posMin(int v[], int tam);

//PRE: El tamanio debe ser mayor a cero.
//POST: Se devuelve la posicion donde esta el valor maximo
//si el tamanio es menor a 1 se devuelve un -1
int posMax(int v[], int tam);

//PRE: El tamanio debe ser mayor a cero
//POST: Se devuelve  el valor minimo
//si el tamanio es menor a 1 se devuelve un -1 junto con un print
int minVector(int v[], int tam);

//PRE: El tamanio debe ser mayor a cero
//POST: Se devuelve  el valor maximo
//si el tamanio es menor a 1 se devuelve un -1 junto con un print
int MaxVector(int v[], int tam);

//PRE: El tamanio debe ser mayor a cero
//POST: Se devuelve el promedio del vector
//si el tamanio es menor a 1 se devuelve un -1 junto con un print
float promVector(int v[], int tam);

//PRE: El tama�o debe ser mayor a cero
//POST: Se sobreescribe el vector resultado con la suma vectorial
//si el tamanio es menor a 1 se printea error.
void sumaVectores(int v[], int w[], int resultado[], int tam);

//PRE: El tama�o debe ser mayor a cero
//POST: Se sobreescribe el vector resultado con la resta vectorial
//si el tamanio es menor a 1 se printea error.
void restaVectores(int v[], int w[], int resultado[], int tam);

//PRE: El tama�o debe ser mayor a cero
//POST: Se sobreescribe el vector v, con los mismos valores pero ordenados de menor a mayor.
//si el tamanio es menor a 1 se printea error.
void ordenamientoBurbujaMenorAMayor(int v[], int tam);

void esCapicuaPalabra(char palabra[], int tam);
