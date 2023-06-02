#include <stdio.h>
#include <stdlib.h>
/*Ejercicio 6: Definir dos vectores de 3 elementos flotantes. Los números son ingresados por el usuario en ambos vectores.
Una vez creado los dos vectores mostrarlos y realizar:

A:   V1 + V2   Suma de vectores
B:    V1 – V2   Resta de vectores
C:   V1.V2      Producto escalar de vectores
D:    3.V1       Producto por un escalar de vectores

Mostrar por consola todos los resultados.
*/
int main()
{
float vec1[3];
float vec2[3];
float vec1SumaVec2[3];
float vec1RestaVec2[3];
float vec1ProductVec2;
float vec1ProductEscalar[3];
vec1ProductVec2=0;

for (int i=0;i<3;i++) {
printf("Ingrese un numero para el vector1: \n");
scanf("%f",&vec1[i]);
printf("Ingrese un numero para el vector2: \n");
scanf("%f",&vec2[i]);
}
//suma de vec1+vec2:
for(int i=0;i<3;i++){
vec1SumaVec2[i]=vec1[i]+vec2[i];
}
//resta vec1-vec2:
for(int i=0;i<3;i++){
vec1RestaVec2[i]=vec1[i]-vec2[i];
}
//multiplicacion vec1*vect2:
for(int i=0;i<3;i++){
vec1ProductVec2+=(vec1[i]*vec2[i]);
}
// Producto por un escalar de vectores:
for(int i=0;i<3;i++){
vec1ProductEscalar[i]=vec1[i]*3;
}
//Se imprimen los vectores:
printf("Vector1:\n");

for(int i=0;i<3;i++){
printf("%.2f\t",vec1[i]);
}

printf("\nVector2:\n");

for(int i=0;i<3;i++){
printf("%.2f\t",vec2[i]);}


printf("\nv1+v2: \n");
for(int i=0;i<3;i++){
printf("%.2f\t",vec1SumaVec2[i]);
}

printf("\nv1-v2: \n");
for(int i=0;i<3;i++){
printf("%.2f\t",vec1RestaVec2[i]);
}

printf("\nv1*v2: \n");

printf("%.2f\t",vec1ProductVec2);

printf("\n3*v1: \n");
for(int i=0;i<3;i++){
printf("%.2f\t",vec1ProductEscalar[i]);
}
return 0;
}
