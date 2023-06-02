#include <stdio.h>
#include <stdlib.h>
/* Ejercicio 9: Pedir el peso y la altura de una persona, calcular el
índice de masa corporal y en base el resultado mostrar:
inferior al normal 18.5
normal 18.5 a 24.9
superior 25.0 a 29.9
obesidad mas de 30
*/

int main()
{
float peso;
float altura;
float indiceMasaCorporal;
//Peso en kilogramos, estatura en centimetros.

printf("Ingrese su peso en kilos: ");
scanf("%f",&peso);
printf("Ingrese su altura en centimetros: ");
scanf("%f",&altura);
altura=altura/100;
indiceMasaCorporal=peso/(altura*altura);

if (indiceMasaCorporal<=18.5) {
printf("Su IMC es inferior al normal. IMC: %.1f", indiceMasaCorporal);
}else {
if (indiceMasaCorporal>=18.5 && indiceMasaCorporal<=24.9 ) {
printf("Su IMC es normal. IMC: %.1f", indiceMasaCorporal);
}else {
if (indiceMasaCorporal>=25.00 && indiceMasaCorporal<=29.9 ) {
printf("Su IMC es superior al normal. IMC: %.1f", indiceMasaCorporal);
}else {
printf("Su IMC esta en la categoria obesidad. IMC: %.1f", indiceMasaCorporal);
}
}
}
return 0;
}
