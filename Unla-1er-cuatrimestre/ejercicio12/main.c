#include <stdio.h>
#include <stdlib.h>
 /*Ejercicio 12: Pedir por pantalla 3 números flotantes, calcular el promedio de estos tres números. */

int main()
{
    float numero;
    float acumNum;
    float promedio;
    int i;
    int cont;

    acumNum=0;
    cont=0;

    printf("A continuacion debera ingresar los numeros correspondientes: \n\n");
    for(i=1;i<=3;i++) {
    printf("Por favor ingrese numero%d: ", i);
    scanf("%f",&numero);
    acumNum+=numero;
    cont++;
    }
    system("cls");
    promedio=acumNum/cont;
    printf("El promedio resultante es: %.2f\n\n\n\n",promedio);
    return 0;
}
