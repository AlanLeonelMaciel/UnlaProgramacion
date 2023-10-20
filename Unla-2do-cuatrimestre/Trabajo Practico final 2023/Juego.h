#ifndef JUEGO_H_INCLUDED
#define JUEGO_H_INCLUDED
#define TIEMPO 15
#include "jugador.h"
#include "ListaJugadores.h"
#include <time.h>
#include <conio.h>
#include <unistd.h>


//typedef struct Jugador* JugadorPtr;

struct Juego {
listaJugadoresPtr listajugadores;
};
//Puntero a los  datos
typedef struct Juego* JuegoPtr;
//constructor
JuegoPtr crearJuego(listaJugadoresPtr listaJugadores);
//algunos metodos

int seleccionJugadores();
void mostrarRanking(int **ranking,int filas, int columnas);
void menuPrincipal(int **ranking, int filas, int columnas, listaJugadoresPtr listaJugadores,int cantJugadores,int* dniJugadores);
void bienvenda();
void nombreApp();
void cartelPerdedor();
void cartelCampeon();
void cartelSinPreguntas(nodoPreguntaPtr preguntaActual,JugadorPtr jugadorActual);
int temporizador(int tiempoLimite, int *tiempoTranscurrido);
nodoJugadorPtr rondaDesempate(listaJugadoresPtr listaJugadores);
int buscarPuntajeActualMaximo(listaJugadoresPtr listaJugadores);
int jugadorEnLista(listaJugadoresPtr lista, JugadorPtr jugador);
JugadorPtr obtenerJugadorCampeon(listaJugadoresPtr lista);
int contarJugadores(listaJugadoresPtr lista);
//getter
listaJugadoresPtr getListaJugadores(JuegoPtr juego);
//setter
void setListaJugadores(JuegoPtr juego, listaJugadoresPtr lista);

#endif // JUEGO_H_INCLUDED
