#include <stdio.h>
#include <stdlib.h>
// Declaración de la función para evitar un warning implícito
void CambiarNum (int * n);
void CambiarNumVector (int v[], int tam);
int main()
{
    printf("Hello\n");
    int numero;
    int * num_Ptr;
    num_Ptr=&numero;
    numero=55;
    printf("El numero es: %d\n",numero);
    CambiarNum(num_Ptr);
    printf("El numero cambiado es: %d\n",numero);
    printf("Ahora cambiamos al vector: \n");
    int vector[6]= {6,5,1,8,9,7};
    printf("Vector en posicion 2 : %d\n", vector[2]);
    printf("Luego de pasar por la funcion: \n");
    CambiarNumVector(vector,6);
    printf("Vector en posicion 2 : %d\n", vector[2]);

    return 0;
}
void CambiarNum (int * n) {
    int nuevoNum;
    printf("Ingrese el nuevo numeo a mostrar: \n");
    scanf("%d",&nuevoNum);
    *n=nuevoNum;
}
void CambiarNumVector (int v[], int tam){
    v[2]=500;
}
