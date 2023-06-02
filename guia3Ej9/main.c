#include <stdio.h>
#include <stdlib.h>

int main()
{
    /*Ejercicio 9: Crear un programa que pida números positivos al usuario,
     y vaya calculando la suma de todos ellos
     (terminará cuando se teclea un número negativo o cero o cuando la suma supere los 1500).
*/
float numero;
float acumNumero;

acumNumero=0;
do {
printf("Ingrese un numero: ");
scanf("%f",&numero);
acumNumero+=numero;
printf("\nLa suma de los numeros hasta el momento es: %.2f \n",acumNumero);
}while(numero>0&&acumNumero<=1500);

    return 0;
}
