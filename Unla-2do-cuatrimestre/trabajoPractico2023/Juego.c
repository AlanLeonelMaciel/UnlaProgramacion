#include "juego.h"
#include "ListaPreguntas.h"
#include <string.h>
#define RESP 4
char* CrearTexto(int caracteres){
    char* fraseDevuelta;
    fraseDevuelta=(char*)malloc((caracteres + 1) * sizeof(char)); // El +1 es por el caracter nulo de fin de cadena.
    return fraseDevuelta;
};


void llenarListaArchivo(listaPtr nuevaLista) {
    //////////////////////////////////////////////////////////////////
    char respuesta[100];
    char *respuestaStr[4];  // Array de punteros a cadenas

    // Asignar memoria para cada cadena
    for (int i = 0; i < 4; i++) {
        respuestaStr[i] = malloc(sizeof(char) * 100); // Asignar espacio para una cadena de 100 caracteres
        if (respuestaStr[i] == NULL) {
            perror("Error en la asignaci�n de memoria");
            exit(EXIT_FAILURE);
        }
        }
        /////////////////////////////////////////////////////////////////
    FILE *archivo = fopen("preguntass.txt", "r");
    if (archivo == NULL) {    //En caso de que no exista el archivo
        perror("Error al abrir el archivo");
        return;
    }
    char linea[200]; // Asumiendo que una l�nea no superar� los 200 caracteres

    while (fgets(linea, sizeof(linea), archivo) != NULL) { //fgets devuelve un puntero, cuando llegue a la ultima linea
        char *pregunta;                                      // arrojara un null
        int numeroPreguntaCorrecta;
        char *numeroPreguntaCorrectaStr;
        PreguntaPtr PreguntaAux;
        PreguntaAux=CrearPregunta();

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

        respuestaStr[0] = strtok(NULL, ";"); //yo se que respuesta es mi ultimo elemento en la linea de texto por eso lo delimito con un salto
        if (respuestaStr[0] == NULL) {
            printf("Error al leer respuesta\n");
            continue;
        }
        respuestaStr[1] = strtok(NULL, ";"); //yo se que respuesta es mi ultimo elemento en la linea de texto por eso lo delimito con un salto
        if (respuestaStr[1] == NULL) {
            printf("Error al leer respuesta2\n");
            continue;
        }
        respuestaStr[2] = strtok(NULL, ";"); //yo se que respuesta es mi ultimo elemento en la linea de texto por eso lo delimito con un salto
        if (respuestaStr[2] == NULL) {
            printf("Error al leer respuesta3\n");
            continue;
        }
        respuestaStr[3] = strtok(NULL, ";"); //yo se que respuesta es mi ultimo elemento en la linea de texto por eso lo delimito con un salto
        if (respuestaStr[3] == NULL) {
            printf("Error al leer respuesta4\n");
            continue;
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




        agregarPreguntListaPrimero(nuevaLista,PreguntaAux);
    }
    fclose(archivo);
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
    char linea[200]; // Asumiendo que una l�nea no superar� los 200 caracteres
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
        char *cadena;  // Puntero a char para almacenar la cadena din�mica

    // Asignar memoria para la cadena din�mica
    cadena = (char *)malloc(sizeof(char) * caracteres);  // Asigna espacio para * caracteres

    if (cadena == NULL) {
        perror("Error en la asignaci�n de memoria");
        exit(EXIT_FAILURE);
    }

}

