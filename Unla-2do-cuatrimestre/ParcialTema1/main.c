#include <stdio.h>
#include <stdlib.h>
#include "Jugador.h"
#define TAM 2

int main()
{
    printf("Hello world!\n");
    JugadorPtr jugadores=CrearJugadores(TAM);
    jugadores[0]=LLenarJugador("alan","maciel",22,10.5,"river");

    jugadores[1].numCamiseta=15;
    strcpy(jugadores[1].nombre,"Matias");
    strcpy(jugadores[1].apellido,"Cordoba");
    jugadores[1].promGol=7.4;
    strcpy(jugadores[1].club,"Boca");

    MostrarJugadores(TAM,jugadores);

    return 0;
}
