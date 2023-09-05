#include <stdio.h>
#include <stdlib.h>

int main()
{
    //Intentare guardar 10 numeros utilizando memoria dinamica, con punteros, luego usar la misma variable pero para guardar
    //15 numeros.
    int *numeros_Ptr;
    numeros_Ptr= (int *)malloc(10*sizeof(int));
    *numeros_Ptr=1;
    numeros_Ptr++;
    *numeros_Ptr=555;
    numeros_Ptr++;
    *numeros_Ptr=3;
    numeros_Ptr++;
    *numeros_Ptr=4;
    numeros_Ptr++;
    *numeros_Ptr=5;
    numeros_Ptr++;
    *numeros_Ptr=6;
    numeros_Ptr++;
    *numeros_Ptr=7;
    numeros_Ptr++;
    *numeros_Ptr=8;
    numeros_Ptr++;
    *numeros_Ptr=9;
    numeros_Ptr++;
    *numeros_Ptr=10;

    for(int i=10; i>0; i--) {
        printf("numero posicion %d: %d",i,*numeros_Ptr--);
        printf("\n");
    }
    // ahora utilizamos el mismo puntero, antes lo liberamos, para almacenar 15 numeros.
    printf("Segunda parte del programa..\n");
    free(numeros_Ptr);
    numeros_Ptr=(int *)malloc(15*sizeof(int));
    for(int i=1;i<16;i++){
        *numeros_Ptr=(30-i)+1;
        printf("a ver :%d\n",*numeros_Ptr);
        numeros_Ptr++; //se desplaza una vez de mas el puntero;

    }
    numeros_Ptr--; // aqui se corrige.
        for(int i=15;i>=1;i--){
       printf("numero posicion %d: %d",i,*numeros_Ptr--);
       printf("\n");
    }
    // ver una posicion especifica del puntero:
    printf("ver posicion especifica 9: %d",numeros_Ptr[9]);
    printf("\n");
    printf(" algo %p",(void *)numeros_Ptr);
    free(numeros_Ptr);
    printf("\n");
 printf(" algo %p",(void *)numeros_Ptr); // eesto esta mal, queria ver que salia
 /*Después de llamar a free(numeros_Ptr),
  no debes asumir que el puntero todavía apunta a
   una ubicación válida de memoria asignada.
    El puntero en sí sigue manteniendo el valor de
     la dirección que tenía antes de liberar la memoria,
      pero esa dirección ya no pertenece a tu programa y
      podría ser reciclada o reasignada por el sistema operativo*/
      numeros_Ptr=NULL;
      /*Esto te permite verificar si el puntero es NULL antes de intentar acceder o modificar la memoria liberada.*/
      if (numeros_Ptr == NULL) {
            printf("\n");
    printf("El puntero es NULL.\n");
} else {
    printf("El puntero no es NULL.\n");
}
int numeros[5] = {10, 20, 30, 40, 50};
int *numeros2_Ptr = numeros; // El puntero apunta al primer elemento del array

printf("Primer número: %d\n", numeros2_Ptr[0]); // Imprime 10
printf("Segundo número: %d\n", numeros2_Ptr[1]); // Imprime 20
    return 0;
}
