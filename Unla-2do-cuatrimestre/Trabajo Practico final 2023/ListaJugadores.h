#ifndef LISTAJUGADORES_H_INCLUDED
#define LISTAJUGADORES_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "jugador.h"
#include "ManejoDinamico.h"

struct nodoJugador{
    JugadorPtr jugador;
    struct nodoJugador *siguiente;
};
typedef struct nodoJugador *nodoJugadorPtr;

struct ListaJugadores {
    nodoJugadorPtr inicio;
};
typedef struct ListaJugadores *listaJugadoresPtr;
//constructores
nodoJugadorPtr crearNodoJugador(JugadorPtr jugador);
listaJugadoresPtr crearListaJugadores();
//algunos metodos
void mostrarListaJugadores(listaJugadoresPtr lista);
void insertarNodoJugadorPrincipio(nodoJugadorPtr nuevoNodo, listaJugadoresPtr lista);
void llenarListaJugadores(int cantJugadores, listaJugadoresPtr listaJugadores,ListaPreguntasPtr preguntas,int **ranking,int filas);
JugadorPtr buscarJugadorPorDNI(listaJugadoresPtr listaJugadores, int dni);
int* obtenerDNIsDeJugadores(listaJugadoresPtr listaJugadores, int cantidadJugadores);
void liberarListaJugadoresMain(listaJugadoresPtr listaJugadores);
void eliminarListaJugadoresTemporales(listaJugadoresPtr listaJugadores);
int** recuperarRankingListaJugadores(listaJugadoresPtr listaJugadores,int cantJugadores);
// Función para intercambiar dos nodos en la lista
void intercambiarNodos(nodoJugadorPtr nodoA, nodoJugadorPtr nodoB);
// Función para ordenar una lista de jugadores por puntaje actual más alto
void ordenarListaJugadoresPorPuntaje(listaJugadoresPtr lista);
#endif // LISTAJUGADORES_H_INCLUDED
