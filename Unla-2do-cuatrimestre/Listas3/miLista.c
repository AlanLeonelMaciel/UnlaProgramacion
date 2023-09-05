#include <stdio.h>
#include <stdlib.h>
#include "miLista.h"
#include "nodo.h"
listaPtr crearLista(){
    listaPtr nuevaLista=(listaPtr)malloc(sizeof(struct Lista));
    nuevaLista->inicio=NULL;
    return nuevaLista;
};
void mostrarLista(listaPtr lista){
    if (lista->inicio != NULL) {
        nodoPtr actual = lista->inicio;
        while (actual != NULL) {
            printf("\n%d\n", actual->dato);
            actual = actual->siguiente;
        }
    } else {
        printf("\nLa lista está vacía.\n");
    }

};

void agregarNumListaPrimero(listaPtr nuevaLista, int numero){
nuevaLista->inicio=crearNodo(numero,nuevaLista);
}
