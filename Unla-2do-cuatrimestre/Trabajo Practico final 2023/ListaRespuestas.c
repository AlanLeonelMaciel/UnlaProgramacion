#include "ListaRespuestas.h"
nodoRespuestaPtr crearNodoRespuesta(respuestaPtr respuesta) {
    nodoRespuestaPtr nuevoNodo;
    nuevoNodo=(nodoRespuestaPtr)malloc(sizeof(struct nodoRespuesta));
    nuevoNodo->respuesta=respuesta;
    nuevoNodo->siguiente=NULL;

    return nuevoNodo;
};

void insertarNodoRespuestaPrincipio(nodoRespuestaPtr nuevoNodo, listaRespuestasPtr lista){

    if(lista->inicio==NULL){
        nuevoNodo->siguiente=NULL;
    }
    else{
        nuevoNodo->siguiente=lista->inicio;
    }
    lista->inicio=nuevoNodo;
};

listaRespuestasPtr crearListaRespuestas(){
    listaRespuestasPtr nuevaLista=(listaRespuestasPtr)malloc(sizeof(struct ListaRespuestas));
    nuevaLista->inicio=NULL;
    return nuevaLista;
};

void mostrarListaRespuestas(listaRespuestasPtr lista){
if (lista->inicio != NULL) {
        nodoRespuestaPtr actual = lista->inicio;
        while (actual != NULL) {
            mostrarRespuesta(actual->respuesta);
            actual = actual->siguiente;
        }
    } else {
        printf("\nLa lista esta vacia.\n");
    }
};
void llenarListaRespuestaDedeTxt(listaRespuestasPtr listaRespuestas, char nombreArchivo[100]){
        char *token;
        char linea[100];
     FILE *archivo = fopen(nombreArchivo, "r");
         if (archivo == NULL) {
        printf("Error al abrir el archivo %s\n",nombreArchivo);
        exit(1);
    }
        // Lee cada línea del archivo
    while (fgets(linea, 100, archivo) != NULL) {
            // Divide la línea en tokens usando la coma como delimitador
            token = strtok(linea, ",");
            // Haz algo con el token (por ejemplo, imprimirlo)
           respuestaPtr respuesta=crearRespuesta(atoi(token),"0",0,0);
            token = strtok(NULL, ","); // Obtén el siguiente token
            setRespuesta(respuesta,token);
            token = strtok(NULL, ","); // Obtén el siguiente token
            setNroPreguntaAsociada(respuesta,atoi(token));
            token = strtok(NULL, ","); // Obtén el siguiente token
            setCorrecta(respuesta,atoi(token));
            nodoRespuestaPtr nodoRespuesta=crearNodoRespuesta(respuesta);
            insertarNodoRespuestaPrincipio(nodoRespuesta,listaRespuestas);
    }
    // Cierra el archivo
    fclose(archivo);
};
void liberarListaRespuestas(listaRespuestasPtr listaRespuestas) {
    nodoRespuestaPtr actual = listaRespuestas->inicio;
    while (actual != NULL) {
        nodoRespuestaPtr siguiente = actual->siguiente;
        free(actual->respuesta); // Libera la respuesta actual
        free(actual); // Libera el nodo actual
        actual = siguiente;
    }
    free(listaRespuestas); // Libera la estructura de la lista de respuestas
};
