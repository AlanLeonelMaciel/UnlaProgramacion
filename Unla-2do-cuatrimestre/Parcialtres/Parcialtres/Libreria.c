#include "Libreria.h"

typedef struct Jugador* JugadorPtr;
///-------Manejo de Archivos-------///

int contarLineasDeArchivo(char *nombreArchivo) {
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
///
void recuperaNumerosPorLinea(char nombreArchivo[], int *vectorNumeros, int cantNumeros){

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
////
void guardarVectorEntero(char nombreArchivo[], int *vectorNumeros, int cantNumeros){

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
///-------Manejo de Array de una dimension-------///

int *crearVectorEnteros(int tam) {
    int *ptr = (int *) malloc(tam * sizeof(int));
    return ptr;
}
///
void mostrarVectorEnteros(int *ptrVec, int tam) {
    for(int i=0; i<tam; i++) {
        printf("[%d]", ptrVec[i]);
    }
    printf("\n");
}
////
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
////
void llenarVectorEnterosRandom(int *ptrVec, int tam) {
    for(int i=0; i<tam; i++) {
        ptrVec[i] = 10+rand()%90;
    }
}
char *crearStringUnaLinea(int cantLetras) {
    char *cadena = (char *) malloc(cantLetras * sizeof(char));
    return cadena;
}
////
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
////
void mostrarArrayStrings(char **cadenas, int cantLineas) {
    for(int i=0; i<cantLineas; i++) {
        printf("%s\n", cadenas[i]);
    }
}
////
char** CrearArrayDinamicoDeStringsDinamicos(int lineas, int caracteres){

    char** arrayStrings;
    arrayStrings = (char**)malloc(sizeof(char*) * lineas);
    for (int i = 0; i < lineas; i++) {
        arrayStrings[i] = (char*)malloc(sizeof(char) * caracteres); // Asignar espacio para una cadena de 100 caracteres
        if (arrayStrings[i] == NULL) {
            perror("Error en la asignación de memoria");
            exit(EXIT_FAILURE);
        }
        }
    return arrayStrings;
}
////
void LiberarArrayDinamicoDeStringsDinamicos(char** arrayStrings, int lineas) {
    if (arrayStrings == NULL) {
        return; // Si el puntero es NULL, no hay nada que liberar
    }

    for (int i = 0; i < lineas; i++) {
        if (arrayStrings[i] != NULL) {
            free(arrayStrings[i]); // Liberar la memoria de cada cadena
        }
    }

    free(arrayStrings); // Liberar la memoria del array de punteros
}
////
int ContarLineasArchivo(char nombreArchivo[40]){
    int cont=0;
        /////////////////////////////////////////////////////////////////
    FILE *archivo = fopen(nombreArchivo, "r"); //Apertura del archivo modo lectura
    if (archivo == NULL) {    //En caso de que no exista el archivo
        perror("Error al abrir el archivo");
        return cont;
    }
    char linea[200]; // Asumiendo que una línea no superará los 200 caracteres
    while (fgets(linea, sizeof(linea), archivo) != NULL) {
        cont++;
    }
    return cont;
}
////
RespuestaPtr CrearRespuesta(){
    RespuestaPtr Respuesta;
    Respuesta=(RespuestaPtr)malloc(sizeof(struct Respuesta));
    return Respuesta;
}
////
void MostrarArchivo() {

    FILE *archivo = fopen("preguntass.txt", "r");
    if (archivo == NULL) {    //En caso de que no exista el archivo
        perror("Error al abrir el archivo");
        return;
    }
    char linea[200]; // Asumiendo que una línea no superará los 200 caracteres
    while (fgets(linea, sizeof(linea), archivo) != NULL) { //fgets devuelve un puntero, cuando llegue a la ultima linea
        char *pregunta;                                      // arrojara un null
        int numeroPregunta;
        char *numeroPreguntaStr;
        char *respuesta;
        char *respuesta2;
        char *respuesta3;
        char *respuesta4;

        pregunta = strtok(linea, ";");// esta funcion devuelve un "token" es decir un texto delimitado por ;
        if (pregunta == NULL) {
            printf("Error al leer la pregunta\n");
            continue;
        }

        numeroPreguntaStr = strtok(NULL, ";");
        if (numeroPreguntaStr == NULL) {
            printf("Error al leer numero de pregunta\n");
            continue;
        }
        numeroPregunta = atoi(numeroPreguntaStr); //como strtok arroja un string necesitamos convertir con atoi numeropregunta a un numero int

        respuesta = strtok(NULL, ";"); //yo se que respuesta es mi ultimo elemento en la linea de texto por eso lo delimito con un salto
        if (respuesta == NULL) {
            printf("Error al leer respuesta\n");
            continue;
        }
        respuesta2 = strtok(NULL, ";"); //yo se que respuesta es mi ultimo elemento en la linea de texto por eso lo delimito con un salto
        if (respuesta2 == NULL) {
            printf("Error al leer respuesta2\n");
            continue;
        }

        respuesta3 = strtok(NULL, ";"); //yo se que respuesta es mi ultimo elemento en la linea de texto por eso lo delimito con un salto
        if (respuesta3 == NULL) {
            printf("Error al leer respuesta3\n");
            continue;
        }

        respuesta4 = strtok(NULL, ";"); //yo se que respuesta es mi ultimo elemento en la linea de texto por eso lo delimito con un salto
        if (respuesta4 == NULL) {
            printf("Error al leer respuesta4\n");
            continue;
        }
        printf("\nPregunta: %s\nNumero de pregunta: %d\nRespuesta: %s\nRespuesta2: %s\nRespuesta3: %s\nRespuesta4: %s\n", pregunta, numeroPregunta, respuesta,respuesta2,respuesta3,respuesta4);

    }
    fclose(archivo);

}
//////
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
////
void agregarLineaAlFinal(char *nombreArchivo, char *nuevaLinea) {
    FILE *archivo = fopen(nombreArchivo, "a");

    if(archivo == NULL) {
        printf("Error al abrir el archivo.\n");
        exit(1);
    }

    fprintf(archivo, "\n%s", nuevaLinea);
    fclose(archivo);
}
///
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
///
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
///
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
///
void eliminarSaltoDeLinea(char *cadena) {
    int longitud = strlen(cadena);
    if(longitud > 0 && cadena[longitud - 1] == '\n') {
        cadena[longitud - 1] = '\0'; // Reemplaza el salto de línea con el carácter nulo
    }
}
///Struc con jugadores///
void mostrarJugadores(int cantJugadores, Jugador *jugadores) {
    for(int i=0; i<cantJugadores; i++) {
        printf("Nombre: %s\n", jugadores[i].nombre);
        printf("Apellido: %s\n", jugadores[i].apellido);
        printf("Nro camiseta: %d\n", jugadores[i].nroCamiseta);
        printf("Promedio goles: %.2f\n", jugadores[i].promedioGoles);
        printf("Club: %s\n\n", jugadores[i].club);
    }
}

void ordenamientoJugadoresDesc(int cantJugadores, JugadorPtr) {

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
/////////////////
Registro *leerArchivo(const char *nombreArchivo, int *numRegistros) {
    int numLineas = contarLineasDeArchivo(nombreArchivo);
    if (numLineas <= 0) {
        *numRegistros = 0;
        return NULL;
    }

    FILE *archivo = fopen(nombreArchivo, "r");
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo.\n");
        return NULL;
    }

    Registro *datos = (Registro *)malloc(numLineas * sizeof(Registro));
    if (datos == NULL) {
        printf("Error de asignación de memoria.\n");
        fclose(archivo);
        return NULL;
    }

    for (int i = 0; i < numLineas; i++) {
        fscanf(archivo, "%[^;];%[^;];%d\n", datos[i].nombre, datos[i].apellido, &datos[i].codigo);
    }

    fclose(archivo);
    *numRegistros = numLineas;
    return datos;
}
////
