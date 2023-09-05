#include <stdio.h>
#include <stdlib.h>
#include "Lista.h"
#include "nodo.h"

listaPtr crearLista(){
    listaPtr nuevaLista=(listaPtr)malloc(sizeof(struct Lista));
    return nuevaLista;
}
void mostrarLista(listaPtr lista){
    if(lista->inicio!=NULL){
        while(lista->inicio->siguiente!=NULL){
            printf("%d",lista->inicio->dato);

        }
    }else{
        printf("La lista esta vacia..");
    }

}
