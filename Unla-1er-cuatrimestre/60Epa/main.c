#include <stdio.h>
#include <stdlib.h>
/*En una empresa de software se ha registrado la siguiente información por cada tarea
realizada:
 CategoríaEmpleado Área HorasTrabajadas

Las categorías de los empleados están registradas según los siguientes códigos:

0. Jefe de Proyecto
1. Analista Funcional
2. Programador
Dentro de la empresa hay 10 áreas distintas. El fin de ingreso de datos se produce cuando
llega la categoría 3.

Los datos ingresan respetando el formato establecido y pueden llegar en cualquier orden
(entiéndase cualquier número de fila y columna, dentro de los valores establecidos).
Hallar la cantidad de horas trabajadas en cada sección por cada categoría, imprimir dicha
información. Además, se necesita conocer el total de horas por cada categoría*/
int main()
{
    int horasTabajadas;
    int categoria;
    int area;
    int empresa[11][4];
    printf("ingrese categoria: ");
    scanf("%d",&categoria);

    while(categoria!=3){

        printf("ingrese categoria: ");
        scanf("%d",&categoria);
    }
    return 0;
}
