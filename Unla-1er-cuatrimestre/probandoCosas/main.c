#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOMBRES 100

int main() {
    char** nombres;
    int n;

    printf("Ingrese la cantidad de nombres: ");
    scanf("%d", &n);

    // Reservar memoria para el arreglo de nombres
    nombres = (char**) malloc(n * sizeof(char*));

    // Pedir los nombres
    for (int i = 0; i < n; i++) {
        nombres[i] = (char*) malloc(50 * sizeof(char));
        printf("Ingrese el nombre %d: ", i + 1);
        scanf("%s", nombres[i]);
    }

    // Imprimir los nombres
    printf("Los nombres ingresados son:\n");
    for (int i = 0; i < n; i++) {
        printf("%s\n", nombres[i]);
    }

    // Liberar memoria
    for (int i = 0; i < n; i++) {
        free(nombres[i]);
    }
    free(nombres);

    return 0;
}
