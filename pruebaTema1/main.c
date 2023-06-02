#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*Para aprobar es necesario entregar en formato de texto (copiar y pegar) el archivo
main.c en el campus virtual antes del horario pactado. No se pueden utilizar temas
aún no vistos. Es necesario que el programa compile, la consola debe verse lo
más parecida a lo siguiente:
1- El usuario selecciona la cantidad de valores enteros con los que quiere trabajar, esa
cantidad debe ser de 2 cifras e impar.
2- Los elementos deben cargarse aleatoriamente con números negativos de tres
cifras.
3- Se debe mostrar el arreglo
4- Se debe mostrar el arreglo de forma invertida
5- Mostrar el promedio de los divisibles por 7*/
int PedirEnteroCondicion();
int GenerarAleatorioInt(int desde, int hasta);
int CargarArregloAleatoriamente();
void MostrarArreglo(int arreglo[],int tam);
void MostrarArregloInvertido(int arreglo[],int tam);
void MostrarPromedioDivisiblesPor(int arreglo[], int tam, int numero);

int main()
{
    srand(time(0));
    int tam;
    int cargoArreglo;
    printf("----------Tema 1----------\n");
    printf("-----Alan, Maciel, DNI:38950011-----\n");
    tam=PedirEnteroCondicion();
    int array[tam];
    cargoArreglo=CargarArregloAleatoriamente(array,tam,-999,-100);
    MostrarArreglo(array,tam);
    MostrarArregloInvertido(array,tam);
    MostrarPromedioDivisiblesPor(array,tam,7);

    return 0;
}

int PedirEnteroCondicion(){
    int cantidad;
do {
    printf("Seleccione la cantidad de valores enteros con los que quiere trabajar,esa cantidad debe ser de 2 cifras e impar.\n");
    scanf("%d",&cantidad);

}while (cantidad/10==0||cantidad%2<1);
return cantidad;
}
int GenerarAleatorioInt(int desde, int hasta){
    int numero;
    int rango = hasta - desde + 1;
    numero = (rand() % rango) + desde;
    return numero;
}
int CargarArregloAleatoriamente(int array[], int tam, int desde, int hasta) {
    int retorno=1;

    for(int i=0;i<tam;i++) {
        array[i]=GenerarAleatorioInt(desde,hasta);
        retorno=0;
    }
    return retorno;
}
void MostrarArreglo(int arreglo[],int tam){
    for(int i=0;i<tam;i++) {
        printf("[%d]",arreglo[i]);

    }
    printf("\n");

}
  void MostrarArregloInvertido(int arreglo[],int tam) {
      printf("Arreglo invertido: \n");
          for(int i=tam-1;i>=0;i--) {
        printf("[%d]",arreglo[i]);

    }
    printf("\n");
  }
void MostrarPromedioDivisiblesPor(int arreglo[], int tam, int numero){
    float prom;
    int acumulador=0;
    int cont=0;
       printf("Los numeros del arreglo que son divisibles por %d son :\n",numero);
        for(int i=0;i<tam;i++) {
        if (arreglo[i]%numero==0) {
            printf("[%d] ",arreglo[i]);
            cont++;
            acumulador+=arreglo[i];
        }

    }
 if (cont > 0) {
        prom = (float) acumulador / cont;
        printf("\nEl promedio es: %.2f\n", prom);
    } else {
        printf("\nNo hay elementos divisibles por %d en el arreglo.\n", numero);
    }
}
