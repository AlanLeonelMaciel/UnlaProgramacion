#include "ManejoDinamico.h"

int **crearMatrizEnteros(int filas, int columnas) {
    int **matriz = (int **) malloc(filas * sizeof(int *));

    for (int i=0; i<filas; i++) {
        matriz[i] = (int *) malloc(columnas * sizeof(int));
    }
    return matriz;
};
void liberarMemoriaMatriz(int **ptrMatriz, int filas) {
    for(int f=0; f<filas; f++) {
        free(ptrMatriz[f]);
    }

    free(ptrMatriz);
};
void InicializarMatrizCeros(int **ptrMatriz, int filas, int columnas) {
    if(ptrMatriz!=NULL){
        for(int f=0; f<filas; f++) {
        for(int c=0; c<columnas; c++) {
            ptrMatriz[f][c] = 0;
            }
        }
    }else{
        printf("Error al asignar ceros en la matriz..");
    }
};
int contarFilasArchivo(char *nombreArchivo){
    int cont=0;
    char linea[200];// Asumiendo que una línea no superará los 200 caracteres
    FILE *archivo = fopen(nombreArchivo, "r"); //Apertura del archivo modo lectura

    if (archivo == NULL) {    //En caso de que no exista el archivo
            cont=-1;
        printf("Error al abrir el archivo. Error: %d",cont);

    }else{
        while (fgets(linea, sizeof(linea), archivo) != NULL) {
            cont++;
        }
    };
    fclose(archivo);
    return cont;
};
void recuperarNumerosPorLineaArchivo(char *nombreArchivo, int **numerosLinea, int filas) {
    int j;
    FILE *archivo = fopen(nombreArchivo, "r");

    if (archivo == NULL) {
        printf("Error al abrir el archivo.\n");
        exit(1);
    }

    char linea[100]; // Asumiendo una longitud máxima de línea de 100 caracteres

    for (int i = 0; i < filas; i++) {
        if (fgets(linea, sizeof(linea), archivo) != NULL) {
            char *token = strtok(linea, ";");
             j = 0;

            while (token != NULL) {
                numerosLinea[i][j] = atoi(token);
                j++;
                token = strtok(NULL, ";");
            }
        } else {
            printf("Error al leer la línea %d del archivo.\n", i + 1);
            exit(1);
        }
    }
    fclose(archivo);
};
void escribirMatrizEnArchivo(char *nombreArchivo, int **matriz, int filas, int columnas) {
    FILE *archivo = fopen(nombreArchivo, "w");

    if (archivo == NULL) {
        printf("Error al abrir el archivo para escritura.\n");
        exit(1);
    }

    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            fprintf(archivo, "%d", matriz[i][j]);

            // Si no es el último elemento de la fila, añadir un ;
            if (j < columnas - 1) {
                fprintf(archivo, ";");
            }
        }

        // Nueva línea después de cada fila
        if(i!=filas-1){
            fprintf(archivo, "\n");
        }
    }

    fclose(archivo);
};
void asignarFilasColumnasArchivo(char *nombreArchivo, int *filas, int *columnas, char *delimitador) {
    *filas = 0;
    *columnas = 0;

    FILE *archivo = fopen(nombreArchivo, "r");

    if (archivo == NULL) {
        printf("Error al abrir el archivo.\n");
        exit(1);
    }

    char linea[100]; // Asumiendo una longitud máxima de línea de 100 caracteres

    while (fgets(linea, sizeof(linea), archivo) != NULL) {
        (*filas)++;

        // Para la primera fila, contar el número de columnas
        if (*filas == 1) {
            char *token = strtok(linea, delimitador);
            while (token != NULL) {
                (*columnas)++;
                token = strtok(NULL, delimitador);
            }
        }
    }

    fclose(archivo);
};
void mostrarMatrizEnteros(int **matriz, int filas, int columnas) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            printf("%d\t ", matriz[i][j]);
        }
        printf("\n");
    }
};
int** unirMatricesVert(int** matriz1, int filas1, int columnas, int** matriz2, int filas2) {

    // Crear una nueva matriz para almacenar la unión de las dos matrices
    int** matrizUnion = crearMatrizEnteros((filas1+filas2),columnas);

    // Copiar la primera matriz a la matriz de unión
    for (int i = 0; i < filas1; i++) {
        matrizUnion[i][0] = matriz1[i][0];
        matrizUnion[i][1] = matriz1[i][1];
    }

    // Copiar la segunda matriz a la matriz de unión
    for (int i = 0; i < filas2; i++) {
        matrizUnion[filas1 + i][0] = matriz2[i][0];
        matrizUnion[filas1 + i][1] = matriz2[i][1];
    }

    return matrizUnion;
};
void escribirMatrizRankingEnArchivo(int** matriz, int filas, int columnas, const char* nombreArchivo) {
    FILE* archivo = fopen(nombreArchivo, "w");

    if (archivo == NULL) {
        printf("No se pudo abrir el archivo para escritura.\n");
        exit(1);
    }

    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            if(columnas!=1){
                fprintf(archivo, "%d;", matriz[i][j]);
            }else{
            fprintf(archivo, "%d", matriz[i][j]);
            };
        };
        if(i<(filas-1)){
            fprintf(archivo, "\n"); // Nueva línea al final de cada fila
        };
    };

    fclose(archivo);
};
void eliminarDnisMatriz(int*** matriz, int* filas, int columnas, int* dnis, int cantJugadores) {
    int contador = 0;

    // Marcar las filas a eliminar
    for (int i = 0; i < *filas; i++) {
        for (int j = 0; j < cantJugadores; j++) {
            if ((*matriz)[i][0] == dnis[j]) {
                (*matriz)[i][0] = -1; // Marcar la fila para eliminar
                contador++; // Incrementar el contador de eliminaciones
            }
        }
    }

    // Crear una nueva matriz sin las filas marcadas
    int** nuevaMatriz = crearMatrizEnteros(*filas - contador, columnas);

    int nuevaFila = 0;
    for (int i = 0; i < *filas; i++) {
        if ((*matriz)[i][0] != -1) {
            // Copiar la fila a la nueva matriz (excepto las marcadas con -1)
            for (int j = 0; j < columnas; j++) {
                nuevaMatriz[nuevaFila][j] = (*matriz)[i][j];
            }
            nuevaFila++;
        }
    }

    // Liberar la memoria de la matriz original
    liberarMemoriaMatriz(*matriz, *filas);

    // Actualizar la matriz original con la nueva matriz
    *matriz = nuevaMatriz;
    *filas -= contador;

    return;
};
int GenerarAleatorioInt(int desde, int hasta){
int numero;
int rango = hasta - desde + 1;
numero = (rand() % rango) + desde;
return numero;
};
void intercambiarFilas(int** ranking, int fila1, int fila2) {
    int temp1 = ranking[fila1][0];
    int temp2 = ranking[fila1][1];
    ranking[fila1][0] = ranking[fila2][0];
    ranking[fila1][1] = ranking[fila2][1];
    ranking[fila2][0] = temp1;
    ranking[fila2][1] = temp2;
};
void ordenarPorPuntajeMasAlto(int** ranking, int filas) {

    for (int i = 0; i < filas - 1; i++) {
        int indiceMaximo = i;
        for (int j = i + 1; j < filas; j++) {
            if (ranking[j][1] > ranking[indiceMaximo][1]) {
                indiceMaximo = j;
            };
        };
        if (indiceMaximo != i) {
            intercambiarFilas(ranking, i, indiceMaximo);
        };
    };
};
