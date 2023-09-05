#include <stdio.h>
#include <stdlib.h>
#include "nodo.h"
#include "time.h"
int main()
{
    srand(time(0));
    listaPtr nuevaLista= crearLista();

    agregarNumListaPrimero(nuevaLista,55);
    agregarNumListaPrimero(nuevaLista,rand() % 100);
    agregarNumListaPrimero(nuevaLista,rand() % 100);
    agregarNumListaPrimero(nuevaLista,rand() % 100);
    agregarNumListaPrimero(nuevaLista,rand() % 100);
    agregarNumListaPrimero(nuevaLista,rand() % 100);
    agregarNumListaPrimero(nuevaLista,rand() % 100);
    agregarNumListaPrimero(nuevaLista,rand() % 100);
    agregarNumListaPrimero(nuevaLista,2000325588);
    agregarNumListaPrimero(nuevaLista,rand() % 100);
    agregarNumListaPrimero(nuevaLista,rand() % 100);
    agregarNumListaPrimero(nuevaLista,rand() % 100);
    agregarNumListaPrimero(nuevaLista,rand() % 100);
    agregarNumListaPrimero(nuevaLista,70);
    agregarNumListaPrimero(nuevaLista,95);

    mostrarLista(nuevaLista);

    printf("/////////////////salio bien la lista///////////////////");

            // Liberar memoria de los nodos en la lista
    nodoPtr nodoActual = nuevaLista->inicio;
    while (nodoActual != NULL) {
        nodoPtr nodoSiguiente = nodoActual->siguiente;
        free(nodoActual);
        nodoActual = nodoSiguiente;
    }
    free(nuevaLista);

    listaPtr nuevaLista2=crearLista();
    agregarNumListaPrimero(nuevaLista2,70);
    mostrarLista(nuevaLista2);

    return 0;
}
