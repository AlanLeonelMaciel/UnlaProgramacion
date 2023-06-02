#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*Ejercicio 4: Crear un vector de 30 números enteros aleatorios.
Para eso agregar la librería #include <time.h> y utilizar los comandos:
srand(time(NULL));
int numeroAleatorio = rand();
*/
int main()
{
srand(time(NULL));
int tam=30;
int numeroAleatorio[tam];
for(int i=0;i<tam;i++){
numeroAleatorio[i]=rand();
}
/* Se imprime el vector
for(int i=0;i<tam;i++){
printf("%d\t",numeroAleatorio[i]);
}
*/
return 0;
}
