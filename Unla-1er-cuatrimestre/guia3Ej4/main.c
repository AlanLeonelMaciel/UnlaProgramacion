#include <stdio.h>
#include <stdlib.h>
/*Ejercicio 4: Pedir que se ingrese un numero por teclado.
Calcular el factorial del numero. POSITIVOS
*/
int main()
{
/*Factorial de n = n! = 1.2.3.4…..(n-1).n
Factorial de 0 es = 1
Factorial de números negativos es 1
*/
int numero;
int factorial;
int acumFactorial;
int i,j;
acumFactorial=1;
printf("Ingresar numero: ");
scanf("%d",&numero);
if (numero>1){
for (i=1;i<numero;i=i+2) {
for (j=i+1;j<=numero;j=j+2) {
   // printf("i:%d...J:%d",i,j);
factorial=i*j;
acumFactorial=acumFactorial*factorial;
break;


}


}
}
else {
printf("El factorial de %d es : 1",numero);
}
printf("El factorial de %d es : %d",numero,acumFactorial);
return 0;
}
