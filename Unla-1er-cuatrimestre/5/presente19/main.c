#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int elegirTamanio();
void cargarVectorConAleatoriosSinRepetir(int v[], int tam, int mini, int maxi);
void MostrarArregloInvertido(int arreglo[],int tam);
void MostrarArregloInt(int arreglo[],int tam);
int CargarArregloAleatoriamenteInt(int array[], int tam, int desde, int hasta);
int GenerarAleatorioInt(int desde, int hasta);
int main()
{
    int tam=elegirTamanio();
    int vector[tam];
    cargarVectorConAleatoriosSinRepetir(vector, tam, 10,2000);
    MostrarArregloInt(vector,tam);
    printf("\n");
    return 0;
}
int elegirTamanio(){
int numero;
do{
printf("Elegir tam: \n");
scanf("%d",&numero);
}while(numero<1);

return numero;
}
void cargarVectorConAleatoriosSinRepetir(int v[], int tam, int mini, int maxi) {
if(mini<maxi&&tam>0&&((maxi-mini)+1)>=tam){
int hayCopias = 0;  // Flag
for (int i = 0; i < tam; i++) {
do {
v[i] = GenerarAleatorioInt(mini, maxi);
hayCopias = 0;


for (int j = 0; j < i; j++) {
if (v[i] == v[j]) {
hayCopias = 1;  // pongo la bandera en 1 porque encontro copia
break;  // Salgo porque encontro copia
}
}
} while (hayCopias > 0);
}
}
else{
printf("El tamanio debe ser menor o igual a: %d",maxi-mini+1);
}

}
void MostrarArregloInvertido(int arreglo[],int tam) {
printf("Arreglo invertido: \n");
for(int i=tam-1;i>=0;i--) {
printf("[%d]",arreglo[i]);

}
printf("\n");
}
void MostrarArregloInt(int arreglo[],int tam){

if(tam>0){
for(int i=0;i<tam;i++) {
printf("[%d]",arreglo[i]);

}
printf("\n");
}

}
int CargarArregloAleatoriamenteInt(int array[], int tam, int desde, int hasta) {
int retorno=1;

for(int i=0;i<tam;i++) {
array[i]=GenerarAleatorioInt(desde,hasta);
retorno=0;
}
return retorno;
}
int GenerarAleatorioInt(int desde, int hasta){
int numero;
int rango = hasta - desde + 1;
numero = (rand() % rango) + desde;
return numero;
}
