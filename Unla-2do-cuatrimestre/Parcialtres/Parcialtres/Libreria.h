#ifndef LIBRERIA_H_INCLUDED
#define LIBRERIA_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
//#include <time.h>
#include <string.h>
///////////////////Struc de ejemplo///////////
typedef struct {
    char nombre[50];
    char apellido[50];
    int codigo;
} Registro;
/////////////
struct Respuesta{
    int nroRespuesta;
    char respuesta[100];
    int nroPreguntaAsociada;
    int correcta;
};
typedef struct Respuesta* RespuestaPtr;

struct Jugador {
    char nombre[15];
    char apellido[15];
    int nroCamiseta;
    float promedioGoles;
    char club[30];
};
typedef struct Jugador* JugadorPtr;

/////////////////////////////////////////////

///-------Manejo de Archivos-------///
int contarLineasDeArchivo(char *nombreArchivo);//Version1
int ContarLineasArchivo(char nombreArchivo[40]);//Version2
void recuperaNumerosPorLinea(char nombreArchivo[], int *vectorNumeros, int cantNumeros);
void guardarVectorEntero(char nombreArchivo[], int *vectorNumeros, int cantNumeros);
//////////////////////
void MostrarArchivo();//A modificar!
/////////////////////
void leerArchivoCompleto(char *nombreArchivo);
void agregarLineaAlFinal(char *nombreArchivo, char *nuevaLinea);
void recuperarLineas(char *nombreArchivo, char **cadenas, int cantLetras);
void sobrescribirLinea(char *nombreArchivo,int cantLetras,int nroLineaBuscada,char *nuevaLinea);
void insertarLineaEn(char *nombreArchivo,int posicionLinea,int cantLetras,char *nuevaLinea);

///-------Manejo de Array de una dimension-------///

int *crearVectorEnteros(int tam) ;
void mostrarVectorEnteros(int *ptrVec, int tam);
void ordenamientoBurbujaAsc(int *v, int tam);
void ordenamientoBurbujaDesc(int *v, int tam);
void llenarVectorEnterosRandom(int *ptrVec, int tam);

///-------Manejo de Array de Dos dimensiones-------///
int **crearMatrizEnteros(int filas, int columnas);
void llenarMatrizEnteros(int **ptrMatriz, int filas, int columnas);
void liberarMemoriaMatriz(int **ptrMatriz, int filas);

///-------Strings-------///
char *crearStringUnaLinea(int cantLetras);
char** CrearArrayDinamicoDeStringsDinamicos(int lineas, int caracteres);
void LiberarArrayDinamicoDeStringsDinamicos(char** arrayStrings, int lineas);
void mostrarArrayStrings(char **cadenas, int cantLineas);
void eliminarSaltoDeLinea(char *cadena);

///------Structs-----///
RespuestaPtr CrearRespuesta();
Registro *leerArchivo(const char *nombreArchivo, int *numRegistros); //leer Archivo devuelve un puntero a una estructura
///Con jugadores///
void mostrarJugadores(int cantJugadores, JugadorPtr);
void ordenamientoJugadoresDesc(int cantJugadores, JugadorPtr);
#endif // LIBRERIA_H_INCLUDED
