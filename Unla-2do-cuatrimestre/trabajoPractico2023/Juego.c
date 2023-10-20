#include "juego.h"
#include "ListaPreguntas.h"
#include <string.h>
#define RESP 4
char* CrearTexto(int caracteres){
    char* fraseDevuelta;
    fraseDevuelta=(char*)malloc((caracteres + 1) * sizeof(char)); // El +1 es por el caracter nulo de fin de cadena.
    return fraseDevuelta;
};
/////////////////////////////////////////////////////////////////////
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
/////////////////////////////////////////////////////////////////////

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
//////////////////////////////////////////////////////////////////////////////

void llenarListaArchivo(listaPtr nuevaLista) {
    //////////////////////////////////////////////////////////////////
    //Se crea un array dinamico de strings dinamicos donde RESP es la cantidad de respuestas admitidas
    //y 200 es la cantidad de caracteres admitidos por cada respuesta.
    char **respuestaStr=CrearArrayDinamicoDeStringsDinamicos(RESP,200);
    /////////////////////////////////////////////////////////////////
    FILE *archivo = fopen("preguntass.txt", "r"); //Apertura del archivo modo lectura
    if (archivo == NULL) {    //En caso de que no exista el archivo
        perror("Error al abrir el archivo");
        return;
    }

    char linea[200]; // Asumiendo que una línea no superará los 200 caracteres

    while (fgets(linea, sizeof(linea), archivo) != NULL) { //fgets devuelve un puntero, cuando llegue a la ultima linea
        char *pregunta; //hace falta reservar memoria aca                                     // arrojara un null
        int numeroPreguntaCorrecta;
        char *numeroPreguntaCorrectaStr;

        PreguntaPtr PreguntaAux=CrearPregunta();//se instancia una struct pregunta (reservando memoria).

        pregunta = strtok(linea, ";");// esta funcion devuelve un "token" es decir un texto delimitado por ;
        if (pregunta == NULL) {
            printf("Error al leer la pregunta\n");
            continue;
        }
        numeroPreguntaCorrectaStr = strtok(NULL, ";");

        if (numeroPreguntaCorrectaStr == NULL) {
            printf("Error al leer numero de pregunta\n");
            continue;
        }
        numeroPreguntaCorrecta = atoi(numeroPreguntaCorrectaStr); //como strtok arroja un string necesitamos convertir con atoi numeropregunta a un numero int

        for(int i=0;i<RESP;i++) {
            respuestaStr[i] = strtok(NULL, ";");
            if (respuestaStr[i] == NULL) {
                printf("Error al leer respuesta\nRevisar la linea %d del archivo de texto, puede estar corrompida o faltante\n",i+1);
                continue;
            }
        }

        PreguntaAux->nroPregunta=numeroPreguntaCorrecta;
        strcpy(PreguntaAux->pregunta,pregunta);

        for(int i=0;i<RESP;i++){
            PreguntaAux->posibles[i]=CrearRespuesta();
            PreguntaAux->posibles[i]->nroRespuesta=i+1;
            PreguntaAux->posibles[i]->correcta=numeroPreguntaCorrecta;
            PreguntaAux->posibles[i]->nroPreguntaAsociada=numeroPreguntaCorrecta;
           strcpy(PreguntaAux->posibles[i]->respuesta,respuestaStr[i]);

        }
        agregarPreguntListaPrimero(nuevaLista,PreguntaAux);//Se agrega la estructura pregunta (adentro tiene respuestas) a la lista
    }
    fclose(archivo);
    LiberarArrayDinamicoDeStringsDinamicos(respuestaStr,RESP);// Se libera la memoria del array de cadenas asignada manualmente
}
///////////////////////////////////////
RespuestaPtr CrearRespuesta(){
    RespuestaPtr Respuesta;
    Respuesta=(RespuestaPtr)malloc(sizeof(struct Respuesta));
    return Respuesta;
}



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
//////////////////////////////////////////////////
char* crearCadenaDinamica(int caracteres){
        char *cadena;  // Puntero a char para almacenar la cadena dinámica

    // Asignar memoria para la cadena dinámica
    cadena = (char *)malloc(sizeof(char) * caracteres);  // Asigna espacio para * caracteres

    if (cadena == NULL) {
        perror("Error en la asignación de memoria");
        exit(EXIT_FAILURE);
    }
    return cadena;
}
int ContarLineasArchivo(char nombreArchivo[40]){
    int cont=0;
        /////////////////////////////////////////////////////////////////
    FILE *archivo = fopen(nombreArchivo, "r"); //Apertura del archivo modo lectura
    if (archivo == NULL) {    //En caso de que no exista el archivo
        perror("Error al abrir el archivo");
        return;
    }
    char linea[200]; // Asumiendo que una línea no superará los 200 caracteres
    while (fgets(linea, sizeof(linea), archivo) != NULL) {
        cont++;
    }
    return cont;
}

