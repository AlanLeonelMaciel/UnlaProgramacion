#include <stdio.h>
#include <stdlib.h>
/*En una empresa de software se ha registrado la siguiente informaci�n por cada tarea
realizada:
 Categor�aEmpleado �rea HorasTrabajadas

Las categor�as de los empleados est�n registradas seg�n los siguientes c�digos:

0. Jefe de Proyecto
1. Analista Funcional
2. Programador
Dentro de la empresa hay 10 �reas distintas. El fin de ingreso de datos se produce cuando
llega la categor�a 3.

Los datos ingresan respetando el formato establecido y pueden llegar en cualquier orden
(enti�ndase cualquier n�mero de fila y columna, dentro de los valores establecidos).
Hallar la cantidad de horas trabajadas en cada secci�n por cada categor�a, imprimir dicha
informaci�n. Adem�s, se necesita conocer el total de horas por cada categor�a*/
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
