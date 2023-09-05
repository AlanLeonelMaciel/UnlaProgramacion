#include <stdio.h>
#include <stdlib.h>
#include "ListaPreguntas.h"
#include <conio.h>
#include <windows.h>
int main()
{
    listaPtr nuevalista=crearLista();
    llenarListaArchivo(nuevalista);
    mostrarLista(nuevalista);
    printf("\n-------------Parte2-----------\n");
    printf("\n%s\n",nuevalista->inicio->pregunta->pregunta);
    printf("\nSeleccione: \n");
    char opcionUsuario[2]; // Se crea una cadena de caracteres, es decir un string.
    opcionUsuario[1]='\0';//en el ultimo elemento se le asigna el fin de cadena es decir el caracter nulo.
    int correcta;
    for(int i=0;i<4;i++){
       // char* cadenaDinamica=crearCadenaDinamica(100);
        printf("\n%d %s\n",i+1,nuevalista->inicio->pregunta->posibles[i]->respuesta);
        if(nuevalista->inicio->pregunta->posibles[i]->nroRespuesta==
           nuevalista->inicio->pregunta->posibles[i]->correcta){
                 correcta=i+1;
           }


        //free(cadenaDinamica);

    }
        printf("\nTenes 5 segundos pa\n");
        Sleep(5000);
        if (kbhit()) {

        opcionUsuario[0] = getch(); //al primer elelento de mi cadena de caracteres se le asigna el primer caracter obtenido del getch
        printf("Tecla presionada: %s\n", opcionUsuario);
    } else {
        printf("No se presiono ninguna tecla dentro del tiempo limite.\n");
    }

    int numero=atoi(opcionUsuario);// Se crea la variable numero y se asigna la transformacion de opcionUsuario que era un string pero con atoi se pasa a entero

            if(numero==correcta){

                printf("\nAcertaste pa\n");
            }else {
                printf("no da");
            }

    //MostrarArchivo();
    return 0;
}
