#include <stdio.h>

#include <stdlib.h>

/*Ejercicio 2: Mostrar todos los números divisibles por 2, por 6 y por 7 que

no sean divisibles por 4

y sean menores a 10000.

*/

int main()

{

int numeros;

int contador;



numeros=9999;

//En este caso incluimos todos los numeros menores que 10000 incluyendo los negativos;

printf("Mostrar todos los numeros divisibles por 2, por 6 y por 7 que no sean divisibles por 4 y sean menores a 10000:\n\n\n");

while (numeros<10000) {

/* este if se podria utilizar para cortar el bucle cuando numero sea igual a cero

if (numeros==0) {

//break;

}*/

if (numeros % 2 == 0 && numeros % 6 == 0 && numeros % 7 == 0 && numeros % 4 != 0) {

printf("%d \n",numeros);

system("pause");

}



numeros--;

}

return 0;

}

