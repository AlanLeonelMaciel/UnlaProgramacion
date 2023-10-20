#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Juego.h"
#include "jugador.h"
#include "ListaJugadores.h"
#include "ListaPreguntas.h"
#include "ManejoDinamico.h"
#include "Juego.h"
int main()
{
    int cantJugadores;
    int **ranking;
    int filas;
    int columnas;
    int *dnisJugadores;
    //Obtener ranking
    filas=contarFilasArchivo("ranking.txt");
    if(!filas){
    filas=1;
    columnas=2;
    int** jugadorEjemplo=crearMatrizEnteros(filas,columnas);
    InicializarMatrizCeros(jugadorEjemplo,filas,columnas);
    escribirMatrizEnArchivo("ranking.txt",jugadorEjemplo,filas,columnas);
    ranking=crearMatrizEnteros(filas,columnas);
    recuperarNumerosPorLineaArchivo("ranking.txt",ranking,filas);
    liberarMemoriaMatriz(jugadorEjemplo,filas);
    }else{
        asignarFilasColumnasArchivo("ranking.txt",&filas,&columnas,";");
        ranking=crearMatrizEnteros(filas,columnas);
        InicializarMatrizCeros(ranking,filas,columnas);
        recuperarNumerosPorLineaArchivo("ranking.txt",ranking,filas);
    };
   //respuestas
    listaRespuestasPtr respuestas;
    respuestas=crearListaRespuestas();
    llenarListaRespuestaDedeTxt(respuestas,"respuestas.txt");
    //preguntas
    ListaPreguntasPtr preguntas=crearListaPreguntas();
    llenarListaPreguntasDedeTxt(preguntas,respuestas,"preguntas.txt");
    //Jugadores
    cantJugadores=seleccionJugadores();
    listaJugadoresPtr listaJugadores=crearListaJugadores();
    llenarListaJugadores(cantJugadores,listaJugadores,preguntas,ranking,filas);
    //Datos de jugadores
    dnisJugadores=obtenerDNIsDeJugadores(listaJugadores,cantJugadores);
    menuPrincipal(ranking,filas,columnas,listaJugadores,cantJugadores,dnisJugadores);
    liberarListaRespuestas(respuestas);
    liberarListaPreguntas(preguntas);
    liberarListaJugadoresMain(listaJugadores);
    liberarMemoriaMatriz(ranking, filas);
    free(dnisJugadores);
    return 0;
}
