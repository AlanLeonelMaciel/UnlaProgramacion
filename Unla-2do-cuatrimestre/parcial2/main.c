#include <stdio.h>
#include <stdlib.h>
#include "canal.h"
int main()
{

    CanalPtr canales;

    int cantCanales;
    int cantRatingMenor5;
    CanalPtr canalesMenor5;

    cantCanales=contarLineasArchivo("canales.txt");
    canales=crearArrayCanales(cantCanales);
    llenarStructDesdeArchivo("canales.txt", canales);
    printf("----------------Canales------------------");
    mostrarCanales(canales,cantCanales);
    cantRatingMenor5=contarCanalesRatingMenor5(canales,cantCanales);
    //printf("%d",cantRatingMenor5);
    canalesMenor5=guardarCanalesRatingMenor5(canales,cantCanales,cantRatingMenor5);
    printf("\n-------Canales menor 5----------\n");
    mostrarCanales(canalesMenor5,cantRatingMenor5);
    guardarCanalesEliminados(canalesMenor5,cantRatingMenor5);







    return 0;
}
