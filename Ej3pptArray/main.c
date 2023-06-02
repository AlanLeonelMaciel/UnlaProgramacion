#include <stdio.h>
#include <stdlib.h>
/*Ejercicio 3: El usuario elige cuantas posiciones tiene el vector.
Una vez definido el tamaño del vector (por el usuario),
el usuario tipea tantos números enteros como sean necesarios para completar el array.
Una vez completo el array, mostrar la suma de los números pares,
el promedio de los impares, el máximo valor y la posición donde estaba el máximo y el mínimo
y su posición. Mostrar el arreglo de derecha a izquierda y de izquierda a derecha. */

int main()
{
int tam;
int sumaPares;
int sumaImares;
int contImpares;
int numeroMin;
int posMin;
int numeroMax;
int posMax;
float promImpares;

sumaImares=0;
contImpares=0;
sumaPares=0;

printf("Ingrese cantidad de numeros deseada: \n");
scanf("%d",&tam);
int numeros[tam];
//completar el array
for (int i=0;i<tam;i++) {
printf("Ingrese un numero: \n");
scanf("%d",&numeros[i]);
}
for (int i=0;i<tam;i++) {
if (i==0){
numeroMax=numeros[0];
posMax=i;
numeroMin=numeros[0];
posMin=i;
}
else {
if (numeroMax<numeros[i]){
numeroMax=numeros[i];
posMax=i;
}
if (numeroMin>numeros[i]){
numeroMin=numeros[i];
posMin=i;
}
}
if (numeros[i]%2==0) {
sumaPares+=numeros[i];
}
else {
sumaImares+=numeros[i];
contImpares++;
}
}//Fin de for

printf("Suma de los pares: %d\n",sumaPares);

if (contImpares!=0) {
promImpares=sumaImares/contImpares;
printf("Promedio de los impares: %.2f\n",promImpares);
}
else {
printf("No hay numeros impares. No se puede calcular el promedio.\n");
}
printf("El numero maximo es: %d y su posicion en el array es: %d\n",numeroMax,posMax);
printf("El numero minimo es: %d y su posicion en el array es: %d\n",numeroMin,posMin);
//mostrar array izquierda a derecha
printf("Mostrar array izquierda a derecha: \n");
for (int i=0;i<tam;i++) {
printf("%d\t",numeros[i]);
}
//mostrar array derecha a izquierda
printf("\nMostrar array derecha a izquierda: \n");
for (int i=tam-1;i>=0;i--) {
printf("%d\t",numeros[i]);
}
return 0;
}
