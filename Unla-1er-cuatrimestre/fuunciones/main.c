#include <stdio.h>
#include <stdlib.h>
/*Crear las siguientes funciones y procedimientos, probándolos desde el main.

int calcularEdad(int nacimiento, int anioHoy);
float calcularIndiceDeMasaCorporal(float altura, float peso);
Void dibujarTriangulo(int base, int altura);
Void calcularHipotenusa(float cateto1, float catero2);*/
int calcularEdad(int nacimiento, int anioHoy);
float calcularIndiceDeMasaCorporal(float alturaPersona, float peso);
void dibujarTriangulo(int base, int altura);
void calcularHipotenusa(float cateto1, float catero2);
int main()
{
int base, altura;
int anioNacimiento, anioActual,edad;
float imc,cateto1,cateto2,alturaPersona,peso;
printf("Introduce el anio de nacimiento: ");
scanf("%d", &anioNacimiento);
printf("Introduce el anio actual: ");
scanf("%d", &anioActual);

edad= calcularEdad(anioNacimiento, anioActual);
printf("La edad calculada es: %d\n", edad);

printf("Introduce la altura en metros: ");
scanf("%f", &altura);
printf("Introduce el peso en kilogramos: ");
scanf("%f", &peso);

 imc = calcularIndiceDeMasaCorporal(alturaPersona, peso);
printf("El indice de masa corporal (IMC) calculado es: %.2f\n", imc);


    printf("Introduce la base del triángulo: ");
    scanf("%d", &base);
    printf("Introduce la altura del triangulo: ");
    scanf("%d", &altura);

    dibujarTriangulo(base, altura);

    printf("Introduce el valor del primer cateto: ");
    scanf("%f", &cateto1);
    printf("Introduce el valor del segundo cateto: ");
    scanf("%f", &cateto2);

    calcularHipotenusa(cateto1, cateto2);
return 0;//fin main
}
int calcularEdad(int nacimiento, int anioHoy){
int edad;
edad = anioHoy - nacimiento;
return edad;

}
float calcularIndiceDeMasaCorporal(float alturaPersona, float peso){
float imc = peso / (alturaPersona * alturaPersona);
return imc;
}
void dibujarTriangulo(int base, int altura){
    int i, j;

    for (i = 1; i <= altura; i++) {
        for (j = 1; j <= base; j++) {
            if (j <= i) {
                printf("* ");
            }
        }
        printf("\n");
    }
}
void calcularHipotenusa(float cateto1, float cateto2){
    float hipotenusa;
    hipotenusa = sqrt(cateto1 * cateto1 + cateto2 * cateto2);
    printf("La hipotenusa calculada es: %.2f\n", hipotenusa);
}
