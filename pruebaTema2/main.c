#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "alaaan.h"
/*1- El usuario selecciona la cantidad de valores enteros con los que quiere trabajar, esa
cantidad debe ser mayor a 10, menor que 30 y que no sea divisible ni por 2 ni por
5.
2- Los elementos deben cargarse aleatoriamente con números de dos cifras pares.
3- Se debe mostrar el arreglo
4- Se debe mostrar solo las posiciones impares del array (1,3,5..etc)
5- Mostrar el mayor de los números menores a 50*/
int PedirEnteroCondicion2();
int main()
{
    srand(time(0));
    int tam;
    printf("----------Tema 2----------\n");
    printf("-----Alan, Maciel, DNI:38950011-----\n");
    tam=PedirEnteroCondicion2();
    int array[tam];
    CargarArregloAleatoriamenteIntPares(array,tam, 10, 99);
    MostrarArregloInt(array,tam);
    MostrarArregloIntPosImpares(array,tam);
    MostrarElMayorDeLosNumerosMenoresA(array,tam);
    return 0;
}
int PedirEnteroCondicion2(){
int cantidad;
do {
    printf("selecciona la cantidad de valores enteros con los que quiere trabajar, esa cantidad debe ser mayor a 10, menor que 30 y que no sea divisible ni por 2 ni por 5.\n");
    scanf("%d",&cantidad);

}while (cantidad<10||cantidad>30||cantidad%2==0||cantidad%5==0);
return cantidad;
}
