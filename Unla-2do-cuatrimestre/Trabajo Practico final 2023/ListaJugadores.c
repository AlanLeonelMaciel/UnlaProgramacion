#include "ListaJugadores.h"

nodoJugadorPtr crearNodoJugador(JugadorPtr jugador) {
    nodoJugadorPtr nuevoNodo;
    nuevoNodo=(nodoJugadorPtr)malloc(sizeof(struct nodoJugador));
    nuevoNodo->jugador=jugador;
    nuevoNodo->siguiente=NULL;

    return nuevoNodo;
};

void insertarNodoJugadorPrincipio(nodoJugadorPtr nuevoNodo, listaJugadoresPtr lista){

    if(lista->inicio==NULL){
        nuevoNodo->siguiente=NULL;
    }
    else{
        nuevoNodo->siguiente=lista->inicio;
    }
    lista->inicio=nuevoNodo;
};

listaJugadoresPtr crearListaJugadores(){
    listaJugadoresPtr nuevaLista=(listaJugadoresPtr)malloc(sizeof(struct ListaJugadores));
    nuevaLista->inicio=NULL;
    return nuevaLista;
};

void mostrarListaJugadores(listaJugadoresPtr lista){
if (lista->inicio != NULL) {
        nodoJugadorPtr actual = lista->inicio;
        while (actual != NULL) {
            mostrarJugador(actual->jugador);
            actual = actual->siguiente;
        }
    } else {
        printf("\nLa lista esta vacia.\n");
    }
};
void llenarListaJugadores(int cantJugadores, listaJugadoresPtr listaJugadores,ListaPreguntasPtr preguntas,int **ranking,int filas){
    int dni;
    int puntuacionMaxima;
    char alias[100];
    fflush(stdin);
    for(int i=0;i<cantJugadores;i++){
        system("cls");
        nombreApp();
        printf("Por favor jugador %d ingrese su alias: \n",i+1);
        gets(alias);
        printf("%s por ultimo, ingresa tu Dni: \n",alias);
        scanf("%d",&dni);
        fflush(stdin);
        puntuacionMaxima=recuperarPuntosMaxDni(dni,ranking,filas);
        PuntosPtr puntos=crearPuntos(dni,0,puntuacionMaxima);
        JugadorPtr jugador=crearJugador(dni,alias,preguntas,puntos);
        nodoJugadorPtr nodoJugador=crearNodoJugador(jugador);
        insertarNodoJugadorPrincipio(nodoJugador,listaJugadores);
    };
};
// Función para encontrar un jugador por su DNI en una lista de jugadores
JugadorPtr buscarJugadorPorDNI(listaJugadoresPtr listaJugadores, int dni) {
    JugadorPtr jugadorEncontrado=NULL;
    int encontro=0;
    if (listaJugadores == NULL || listaJugadores->inicio == NULL) {
        // La lista de jugadores está vacía o es nula, no se puede encontrar el jugador.
        printf("\nLa lista que usted selecciono para buscar por dni esta vacia...\n");
    }

    nodoJugadorPtr actual = listaJugadores->inicio;

    while (actual != NULL) {
        if (actual->jugador->dni == dni) {
            // Se encontró el jugador por su DNI
            jugadorEncontrado=actual->jugador;
            encontro++;
        }
        actual = actual->siguiente;
    }

    // El jugador con el DNI especificado no se encontró en la lista.
    return jugadorEncontrado;
};
// Función para obtener todos los DNIs de la lista de jugadores y guardarlos en un vector
int* obtenerDNIsDeJugadores(listaJugadoresPtr listaJugadores, int cantidadJugadores) {
    int* vectorDNIs = (int*)malloc(cantidadJugadores * sizeof(int));

    if (listaJugadores == NULL || listaJugadores->inicio == NULL) {
        // La lista de jugadores está vacía o es nula, no hay DNIs para obtener.
        cantidadJugadores = 0;
        printf("La lista para obtener los dni de los jugadores esta vacia..");
        exit(1);
    };
    nodoJugadorPtr actual;
    // Llenar el vector con los DNIs
    actual = listaJugadores->inicio;
    int indice = 0;
    while (actual != NULL) {
        vectorDNIs[indice] = actual->jugador->dni;
        indice++;
        actual = actual->siguiente;
    }
    return vectorDNIs;
};
void liberarListaJugadoresMain(listaJugadoresPtr listaJugadores){

    nodoJugadorPtr actual = listaJugadores->inicio;
    while (actual != NULL) {
        nodoJugadorPtr temp = actual;
        actual = actual->siguiente;
        // Liberar memoria del jugador
        free(temp->jugador);
        free(temp);
    };
    free(listaJugadores);
};
///////////////////////////////////////////////////////////////////
void eliminarListaJugadoresTemporales(listaJugadoresPtr listaJugadores){
nodoJugadorPtr actual = listaJugadores->inicio;
while (actual != NULL) {
    nodoJugadorPtr siguiente = actual->siguiente;
    //free(actual->jugador); // Liberar la memoria del jugador
    free(actual);          // Liberar la memoria del nodo
    actual = siguiente;
};
// Liberar la lista en sí
free(listaJugadores);
};
int** recuperarRankingListaJugadores(listaJugadoresPtr listaJugadores,int cantJugadores){
    nodoJugadorPtr actual=listaJugadores->inicio;
    int** rankingJugadores=crearMatrizEnteros(cantJugadores,2);
    int indice=0;
    while(actual!=NULL){
        rankingJugadores[indice][0]=actual->jugador->dni;
        rankingJugadores[indice][1]=actual->jugador->Puntos->puntuacionMax;
        actual=actual->siguiente;
        indice++;
    };
    return rankingJugadores;
};
// Función para intercambiar dos nodos en la lista
void intercambiarNodos(nodoJugadorPtr nodoA, nodoJugadorPtr nodoB) {
    JugadorPtr temp = nodoA->jugador;
    nodoA->jugador = nodoB->jugador;
    nodoB->jugador = temp;
};
// Función para ordenar una lista de jugadores por puntaje actual más alto
void ordenarListaJugadoresPorPuntaje(listaJugadoresPtr lista) {
    if (lista == NULL || lista->inicio == NULL) {
        return; // La lista está vacía o tiene un solo elemento, no es necesario ordenar.
    };
    nodoJugadorPtr actual = lista->inicio;

    while (actual != NULL) {
        nodoJugadorPtr maxPuntaje = actual;
        // Encuentra el nodo con el puntaje más alto en el resto de la lista
        nodoJugadorPtr siguiente = actual->siguiente;
        while (siguiente != NULL) {
            if (siguiente->jugador->Puntos->actuales > maxPuntaje->jugador->Puntos->actuales) {
                maxPuntaje = siguiente;
            };
            siguiente = siguiente->siguiente;
        };

        // Intercambia el nodo actual con el nodo con el puntaje más alto
        if (maxPuntaje != actual) {
            intercambiarNodos(actual, maxPuntaje);
        };

        actual = actual->siguiente;
    };
};
