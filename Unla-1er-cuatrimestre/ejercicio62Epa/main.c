#include <stdio.h>
#include <stdlib.h>
/*Ejercicio 62
En un curso donde previamente se debe de cargar la cantidad límites de alumnos(n)
Generar un algoritmo que permita el ingreso del Nombre y Apellido del Alumno, su DNI, la
Nota 1, la Nota 2 y la Nota 3.
A partir de ahí, generar un listado donde deben aparecer ordenados de forma decreciente
según su promedio.*/
int main()
{
    char nombres[4][50];
    for (int i=0;i<4;i++) {
        printf("Ingrese nombre: ");
        fflush(stdin);
        scanf("&s",nombres[i]);
    }
    for (int i=0;i<4;i++){
        printf("%s\n",nombres[i]);
    }




    return 0;
}
