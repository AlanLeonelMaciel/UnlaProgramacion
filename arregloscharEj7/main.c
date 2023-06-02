#include <stdio.h>
#include <stdlib.h>
/*Ejercicio 7: Escribir un programa que pida tres cadenas al usuario y
muestre el resultado de concatenar las dos primeras letras de las cadenas
introducidas y que indique si las dos primeras cadenas son iguales.
Ejemplo: el usuario introduce como cadenas perro, vaca y cocodrilo.
El programa mostrará por pantalla: “El resultado de concatenar las dos
primeras letras de las cadenas es: pevaco. La primera cadena, perro,
no es igual a la segunda cadena, vaca.”
Si el usuario introdujera perro, perro, mulo, el programa debería mostrar:
“El resultado de concatenar las dos primeras letras de las cadenas es pepemu.
La primera cadena, perro, es igual a la segunda cadena, perro.”*/
int main()
{
char concatenacion[5]= "";
// Inicializar concatenacion como cadena vacia
char cadena1[50];
char cadena2[50];
char cadena3[50];

printf("Inserte cadena1: ");
fflush(stdin);
gets(cadena1);
printf("Inserte cadena2: ");
gets(cadena2);
printf("Inserte cadena3: ");
gets(cadena3);

strncat(concatenacion, cadena1, 2);  // Concatenar los dos primeros caracteres de cadena1
strncat(concatenacion, cadena2, 2);  // Concatenar los dos primeros caracteres de cadena2
strncat(concatenacion, cadena3, 2);// Concatenar los dos primeros caracteres de cadena3
printf("El resultado de concatenar las dos primeras letras de las cadenas es: %s.\n", concatenacion);
if (strcmp(cadena1, cadena2) == 0) {
printf("La primera cadena, %s, es igual a la segunda cadena, %s.\n", cadena1, cadena2);
} else {
printf("La primera cadena, %s, no es igual a la segunda cadena, %s.\n", cadena1, cadena2);
}
return 0;
}
