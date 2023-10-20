#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "aaptr.h"

/// ARRAYS CON PUNTEROS

// Unidimensionales
int *crearVectorEnteros(int tam) {
    int *ptr = (int *) malloc(tam * sizeof(int));
    return ptr;
}

void llenarVectorEnteros(int *ptrVec, int tam) {
    for(int i=0; i<tam; i++) {
        ptrVec[i] = 10+rand()%90;
    }
}

void mostrarVectorEnteros(int *ptrVec, int tam) {
    for(int i=0; i<tam; i++) {
        printf("[%d]", ptrVec[i]);
    }
    printf("\n");
}

char *asignarMemoriaCadena(int cantLetras) {
    char *cadena = (char *) malloc(cantLetras * sizeof(char));
    return cadena;
}

// Bidimensionales
int **crearMatrizEnteros(int filas, int columnas) {
    int **matriz = (int **) malloc(filas * sizeof(int *));

    for (int i=0; i<filas; i++) {
        matriz[i] = (int *) malloc(columnas * sizeof(int));
    }
    return matriz;
}

void llenarMatrizEnteros(int **ptrMatriz, int filas, int columnas) {
    for(int f=0; f<filas; f++) {
        for(int c=0; c<columnas; c++) {
            ptrMatriz[f][c] = 10+(rand()%90);
        }
    }
}

void mostrarMatrizEnteros(int **ptrMatriz, int filas, int columnas) {
    for(int f=0; f<filas; f++) {
        for(int c=0; c<columnas; c++) {
            printf("[%d]", ptrMatriz[f][c]);
        }
        printf("\n");
    }
}

void liberarMemoriaMatriz(int **ptrMatriz, int filas) {
    for(int f=0; f<filas; f++) {
        free(ptrMatriz[f]);
    }

    free(ptrMatriz);
}

// Strings
char **crearArrayStrings(int cantLineas, int cantLetras) {
    char **arrayStrings = (char **) malloc(cantLineas * sizeof(char *));

    for(int i=0; i<cantLineas; i++) {
        arrayStrings[i] = (char *) malloc(cantLetras * sizeof(char));
    }
    return arrayStrings;
}

void mostrarArrayStrings(char **cadenas, int cantLineas) {
    for(int i=0; i<cantLineas; i++) {
        printf("%s\n", cadenas[i]);
    }
}


/// MANIPULACION DE ARCHIVOS

void leerArchivoCompleto(char *nombreArchivo) {
    FILE *archivo = fopen(nombreArchivo, "r");

    if(archivo == NULL) {
        printf("Error al abrir el archivo.\n");
        exit(1);
    }

    char caracter;

    while(!feof(archivo)) {
        caracter = fgetc(archivo);
        printf("%c", caracter);
    }

    fclose(archivo);
}

void agregarLineaAlFinal(char *nombreArchivo, char *nuevaLinea) {
    FILE *archivo = fopen(nombreArchivo, "a");

    if(archivo == NULL) {
        printf("Error al abrir el archivo.\n");
        exit(1);
    }

    fprintf(archivo, "\n%s", nuevaLinea);
    fclose(archivo);
}

void recuperarLineas(char *nombreArchivo, char **cadenas, int cantLetras) {
    FILE *archivo = fopen(nombreArchivo, "r");

    if(archivo == NULL) {
        printf("Error al abrir el archivo.\n");
        exit(1);
    }

    int i = 0;
    while(fgets(cadenas[i], cantLetras, archivo)) {
        i++;
    }

    fclose(archivo);
}

void sobrescribirLinea(
    char *nombreArchivo,
    int cantLetras,
    int nroLineaBuscada,
    char *nuevaLinea
) {
    FILE *archivo = fopen(nombreArchivo, "r");

    if(archivo == NULL) {
        printf("Error al abrir el archivo.\n");
        exit(1);
    }

    int cantLineas = contarLineasArchivo(nombreArchivo);
    char **cadenas = crearArrayStrings(cantLineas, cantLetras);

    if(nroLineaBuscada <= 0 || nroLineaBuscada > cantLineas) {
        free(cadenas);
        printf("No existe la linea indicada.\n");
        printf("No se pudo modificar el archivo.\n");
        fclose(archivo);
        exit(1);
    }

    int i = 0;
    while(fgets(cadenas[i], cantLetras, archivo)) {
        if(nroLineaBuscada-1 == i) {
            strcpy(cadenas[i], nuevaLinea);
        }
        i++;
    }

    fclose(archivo);

    archivo = fopen(nombreArchivo, "w");

    for(int j=0; j<cantLineas; j++) {
        if(j != nroLineaBuscada-1) {
            fprintf(archivo, "%s", cadenas[j]);
        } else {
            fprintf(archivo, "%s\n", cadenas[j]);
        }
    }

    fclose(archivo);
    free(cadenas);
}

int contarLineasArchivo(char *nombreArchivo) {
    FILE *archivo = fopen(nombreArchivo, "r");

    if(archivo == NULL) {
        printf("Error al abrir el archivo.\n");
        exit(1);
    }

    char caracter;
    int i = 1;
    while(!feof(archivo)) {
        caracter = fgetc(archivo);
        if(caracter == '\n') {
            i++;
        }
    }

    return i;
}

void insertarLineaEn(
    char *nombreArchivo,
    int posicionLinea,
    int cantLetras,
    char *nuevaLinea
) {
    FILE *archivo = fopen(nombreArchivo, "r");

    if(archivo == NULL) {
        printf("Error al abrir el archivo.\n");
        exit(1);
    }

    int cantLineas = contarLineasArchivo(nombreArchivo);
    char **cadenas = crearArrayStrings(cantLineas+1, cantLetras);

    if(posicionLinea <= 0 || posicionLinea > cantLineas) {
        free(cadenas);
        printf("No existe la linea indicada.\n");
        printf("No se pudo modificar el archivo.\n");
        fclose(archivo);
        exit(1);
    }

    int i = 0;
    while(fgets(cadenas[i], cantLetras, archivo)) {
        if(posicionLinea-1 == i) {
            strcpy(cadenas[i+1], cadenas[i]);
            strcpy(cadenas[i], nuevaLinea);
            i++;
        }
        i++;
    }

    fclose(archivo);

    archivo = fopen(nombreArchivo, "w");

    for(int j=0; j<cantLineas+1; j++) {
        if(j != posicionLinea-1) {
            fprintf(archivo, "%s", cadenas[j]);
        } else {
            fprintf(archivo, "%s\n", cadenas[j]);
        }
    }

    fclose(archivo);
    free(cadenas);
}

/// ALEATORIOS

void eliminarSaltoDeLinea(char *cadena) {
    int longitud = strlen(cadena);
    if(longitud > 0 && cadena[longitud - 1] == '\n') {
        cadena[longitud - 1] = '\0'; // Reemplaza el salto de línea con el carácter nulo
    }
}

void txtAEstructura(int cantMaxLetras, char *nombreArchivo, Jugador *jugadores) {

    char *linea = asignarMemoriaCadena(cantMaxLetras);
    char *fragmento = asignarMemoriaCadena(cantMaxLetras/3);

    FILE *archivo = fopen(nombreArchivo, "r");

    if(archivo == NULL) {
        printf("Error al abrir el archivo.\n");
        exit(1);
    }

    int contLineas = 0;

    while(fgets(linea, cantMaxLetras, archivo)) {
        eliminarSaltoDeLinea(linea);
        fragmento = strtok(linea, ";");
        int contFragmentos = 0;

        while(fragmento != NULL) {
            // printf("Fragmento: %s\n", fragmento); Generico

            switch(contFragmentos) {
                case 0:
                    strcpy(jugadores[contLineas].nombre, fragmento);
                    break;
                case 1:
                    strcpy(jugadores[contLineas].apellido, fragmento);
                    break;
                case 2:
                    jugadores[contLineas].nroCamiseta = atoi(fragmento);
                    break;
                case 3:
                    jugadores[contLineas].promedioGoles = atof(fragmento);
                    break;
                case 4:
                    strcpy(jugadores[contLineas].club, fragmento);
                    break;
                default:
                    printf("Fragmento invalido.\n");
                    break;
            }
            fragmento = strtok(NULL, ";");
            contFragmentos++;
        }
        contLineas++;
    }
    fclose(archivo);

    free(linea);
    free(fragmento);
}

void ordenamientoBurbujaAsc(int *v, int tam){
    int aux;
    for(int i=0; i<tam; i++){
        for(int j=0; j<tam-1; j++){
            if(v[j] > v[j+1]){
                aux = v[j];
                v[j] = v[j+1];
                v[j+1] = aux;
            }
        }
    }
}

void ordenamientoBurbujaDesc(int *v, int tam) {
    int aux;
    for(int i=0; i<tam; i++){
        for(int j=0; j<tam-1; j++){
            if(v[j] < v[j+1]){
                aux = v[j];
                v[j] = v[j+1];
                v[j+1] = aux;
            }
        }
    }
}


void mostrarJugadores(int cantJugadores, JugadorPtr Jugadores) {
    for(int i=0; i<cantJugadores; i++) {
        printf("Nombre: %s\n", jugadores[i].nombre);
        printf("Apellido: %s\n", jugadores[i].apellido);
        printf("Nro camiseta: %d\n", jugadores[i].nroCamiseta);
        printf("Promedio goles: %.2f\n", jugadores[i].promedioGoles);
        printf("Club: %s\n\n", jugadores[i].club);
    }
}

void ordenamientoJugadoresDesc(int cantJugadores, JugadorPtr Jugadores) {

    Jugador jugadorAux;
    for(int i=0; i<cantJugadores; i++){
        for(int j=0; j<cantJugadores-1; j++){
            if(jugadores[j].promedioGoles < jugadores[j+1].promedioGoles){
                jugadorAux = jugadores[j];
                jugadores[j] = jugadores[j+1];
                jugadores[j+1] = jugadorAux;
            }
        }
    }

}

void guardarTxtOrdenado(int cantJugadores, Jugador *jugadores) {

    FILE *archivo = fopen("ordenados.txt", "w");

    if(archivo == NULL) {
        printf("Error al abrir archivo.\n");
        exit(1);
    }

    for(int i=0; i<cantJugadores; i++) {
        if(i != cantJugadores-1) {
            fprintf(
                archivo,
                "%s;%s;%d;%.2f;%s\n",
                jugadores[i].nombre,
                jugadores[i].apellido,
                jugadores[i].nroCamiseta,
                jugadores[i].promedioGoles,
                jugadores[i].club
            );
        } else {
            fprintf(
                archivo,
                "%s;%s;%d;%.2f;%s",
                jugadores[i].nombre,
                jugadores[i].apellido,
                jugadores[i].nroCamiseta,
                jugadores[i].promedioGoles,
                jugadores[i].club
            );
        }


    }

    fclose(archivo);

}


///-----------------------------------------------------------------
void recuperaNumeros(char nombreArchivo[], int *vectorNumeros, int cantNumeros){

    FILE *archivo = fopen(nombreArchivo, "r");
    if(archivo == NULL){

        printf("ERROR AL ABRIR EL ARCHIVO");
        exit(1);
    }

    int cont=0;
    char info[40];
    while (fgets(info, 40, archivo)!=NULL){

        vectorNumeros[cont] = atoi(info);
        cont++;
    }

    fclose(archivo);
}


void guardarNumOrdenado(char nombreArchivo[], int *vectorNumeros, int cantNumeros){

    FILE *archivo = fopen(nombreArchivo, "w");

    if(archivo == NULL){

        printf("NO SE PUDO ABRIR EL ARCHIVO");
        exit(1);
    }

    for (int i=0; i<cantNumeros; i++){

        if(cantNumeros -1 != i){
            fprintf(archivo, "%d\n", vectorNumeros[i]);
        }else{
             fprintf(archivo, "%d", vectorNumeros[i]);
        }


    }
    fclose(archivo);



}
///----------------------------------------------------------------
