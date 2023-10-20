#include <stdio.h>
#include <stdlib.h>
#include "num.h"
/*Dados dos archivos .txt, crear un array (con manejo dinamico de la memoria),
donde se guarden los numeros de ambos archivos, pero en el array no pueden existir números negativos.

- Mostrar el arreglo resultante
- Guardar el arreglo resultando en un archivo llamado respuesta.txt, utilizando delimitadores.*/
int main()
{
    int cantLineas1;
    int cantLineas2;
    int* numeros1;
    int* numeros2;
    int* vectorTotal;
    int cantTotal;

    //Primero cuento las lineas de los positivos para tener un tam de cada texto.
    cantLineas1=ContarLineasArchivoPositivo("numeros1.txt");
    cantLineas2=ContarLineasArchivoPositivo("numeros2.txt");
    //Creo los vectores correspondientes a cada texto, con su correspondiente tam (cantLineas)
    numeros1=crearVectorEnteros(cantLineas1);
    numeros2=crearVectorEnteros(cantLineas2);
    //Recupero del texto, solo los positivos; un texto en un vector correspondiente con su tam correspondiente(cantLineas).
    recuperaNumerosPorLineaPositivos("numeros1.txt",numeros1,cantLineas1);
    recuperaNumerosPorLineaPositivos("numeros2.txt",numeros2,cantLineas2);
    //Asigno una cantidad total para crear un unico vector con el tamaño de los dos vectores anteriores sumados.
     cantTotal=cantLineas1+cantLineas2;
     //Creo el vector unico que va a contener la informacion de numeros1 y numeros2.
    vectorTotal=crearVectorEnteros(cantTotal);
    ///Se usa la funcion para fusionar vectores en uno solo:
    fusionarVectoresEnteros(vectorTotal,cantTotal,numeros1,cantLineas1,numeros2);

    //Se muestran los archivos.
    printf("\n---------------Archivo1------------------\n");
    mostrarVectorEnteros(numeros1,cantLineas1);
    printf("\n---------------Archivo2------------------\n");
    mostrarVectorEnteros(numeros2,cantLineas2);
    //Se guarda vector unico en el txt, en este caso un numero por linea.
    guardarVectorEntero("respuesta.txt",vectorTotal,cantTotal);

    //Se muestra el vector unificado.
    printf("\n---------------Vector resultado------------------\n");
    mostrarVectorEnteros(vectorTotal,cantTotal);
    return 0;
}
