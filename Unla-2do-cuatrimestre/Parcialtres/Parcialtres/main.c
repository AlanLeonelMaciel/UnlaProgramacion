#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "aaptr.h"



int main()
{

    int cantLineas = contarLineasArchivo("numeros.txt");

    int *vectorEntero;
    vectorEntero = crearVectorEnteros(cantLineas);

    recuperaNumeros("numeros.txt", vectorEntero, cantLineas);
    mostrarVectorEnteros(vectorEntero, cantLineas);

    printf("\nORDENADO:\n\n");

    ordenamientoBurbujaAsc(vectorEntero, cantLineas);
    mostrarVectorEnteros(vectorEntero, cantLineas);

    guardarNumOrdenado("ordenado.txt", vectorEntero, cantLineas);

    free(vectorEntero);







}
