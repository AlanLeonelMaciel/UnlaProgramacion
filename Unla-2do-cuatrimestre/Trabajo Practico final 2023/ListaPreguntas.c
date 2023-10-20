#include "ListaPreguntas.h"

nodoPreguntaPtr crearNodoPregunta(PreguntaPtr pregunta) {
    nodoPreguntaPtr nuevoNodo;
    nuevoNodo=(nodoPreguntaPtr)malloc(sizeof(struct nodoPregunta));
    nuevoNodo->pregunta=pregunta;
    nuevoNodo->siguiente=NULL;

    return nuevoNodo;
};

void insertarNodoPreguntaPrincipio(nodoPreguntaPtr nuevoNodo, ListaPreguntasPtr lista){

    if(lista->inicio==NULL){
        nuevoNodo->siguiente=NULL;
    }
    else{
        nuevoNodo->siguiente=lista->inicio;
    }
    lista->inicio=nuevoNodo;
};

ListaPreguntasPtr crearListaPreguntas(){
    ListaPreguntasPtr nuevaLista=(ListaPreguntasPtr)malloc(sizeof(struct ListaPreguntas));
    nuevaLista->inicio=NULL;
    return nuevaLista;
};

void mostrarListaPreguntas(ListaPreguntasPtr lista){
if (lista->inicio != NULL) {
        nodoPreguntaPtr actual = lista->inicio;
        while (actual != NULL) {
            mostrarPregunta(actual->pregunta);
            actual = actual->siguiente;
        }
    } else {
        printf("\nLa lista esta vacia.\n");
    }
};
void llenarListaPreguntasDedeTxt(ListaPreguntasPtr listaPreguntas,listaRespuestasPtr respuestas,char nombreArchivo[100]){
        char *token;
        char linea[100];
        int numeroPregunta;
        char *preguntaCadena;
        listaRespuestasPtr respuestasPosibles=crearListaRespuestas();

     FILE *archivo = fopen(nombreArchivo, "r");
         if (archivo == NULL) {
        printf("Error al abrir el archivo %s\n",nombreArchivo);
        exit(1);
    }
        // Lee cada línea del archivo
    while (fgets(linea, 100, archivo) != NULL) {
            // Divide la línea en tokens usando la coma como delimitador
            token = strtok(linea, ",");
            numeroPregunta=atoi(token);
            //
            token = strtok(NULL, ","); // Obtén el siguiente token
            preguntaCadena=token;
            respuestasPosibles=obtenerRespuestasPosibles(respuestas,numeroPregunta);
            PreguntaPtr p=crearPregunta(numeroPregunta,preguntaCadena,respuestasPosibles);
            nodoPreguntaPtr nodoPregunta=crearNodoPregunta(p);
            insertarNodoPreguntaPrincipio(nodoPregunta,listaPreguntas);
    }
    // Cierra el archivo
    fclose(archivo);
};
// Función para barajar la lista de preguntas
void barajarListaPreguntas(ListaPreguntasPtr listaPreguntas) {
    // Paso 1: Contar la cantidad de preguntas en la lista
    int numPreguntas = 0;
    nodoPreguntaPtr actual = listaPreguntas->inicio;
    while (actual != NULL) {
        numPreguntas++;
        actual = actual->siguiente;
    }

    // Paso 2: Crear un arreglo de punteros a preguntas
    PreguntaPtr* preguntasArray = (PreguntaPtr*)malloc(numPreguntas * sizeof(PreguntaPtr));

    // Copiar los punteros de las preguntas en el arreglo
    actual = listaPreguntas->inicio;
    int i = 0;
    while (actual != NULL) {
        preguntasArray[i] = actual->pregunta;
        i++;
        actual = actual->siguiente;
    }

    // Paso 3: Usar el algoritmo de Fisher-Yates para barajar el arreglo
    srand(time(NULL));
    for (i = numPreguntas - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        // Intercambiar preguntasArray[i] y preguntasArray[j]
        PreguntaPtr temp = preguntasArray[i];
        preguntasArray[i] = preguntasArray[j];
        preguntasArray[j] = temp;
    }

    // Paso 4: Reconstruir la lista enlazada con el arreglo barajado
    listaPreguntas->inicio = NULL;
    for (i = 0; i < numPreguntas; i++) {
        nodoPreguntaPtr nuevoNodo = (nodoPreguntaPtr)malloc(sizeof(struct nodoPregunta));
        nuevoNodo->pregunta = preguntasArray[i];
        nuevoNodo->siguiente = listaPreguntas->inicio;
        listaPreguntas->inicio = nuevoNodo;
    }

    // Liberar la memoria del arreglo temporal
    free(preguntasArray);
};
void liberarListaPreguntas(ListaPreguntasPtr listaPreguntas) {
    nodoPreguntaPtr actual = listaPreguntas->inicio;
    while (actual != NULL) {
        nodoPreguntaPtr siguiente = actual->siguiente;
        free(actual); // Liberar el nodo actual
        actual = siguiente;
    }
    free(listaPreguntas); // Liberar la estructura de la lista
};
