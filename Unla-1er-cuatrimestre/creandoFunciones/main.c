#include <stdio.h>
#include <stdlib.h>

int posMin(int v[], int tam);
void MostrarPromedioDivisiblesPor(int arreglo[], int tam, int numero);
float PromVector(int arreglo[], int tam);
void sumaVectores(int v[], int w[], int resultado[], int tam);
void MostrarArregloInt(int arreglo[],int tam);
void restaVectores(int v[], int w[], int resultado[], int tam);
void ordenamientoBurbujaMenorAMayor(int v[], int tam);
void esCapicuaPalabra(char palabra[], int tam);
int main()
{
    int tam=3;
   int vector2[3]={1,10,7};
   int vector[3]={12,15,66};
   int vectorR[3]={0,0,0};
   char palabra[6]="rallar";
   esCapicuaPalabra(palabra,6);
   restaVectores(vector,vector2,vectorR,tam);
   MostrarArregloInt(vectorR,tam);
   ordenamientoBurbujaMenorAMayor(vectorR,tam);
   MostrarArregloInt(vectorR,tam);
   int posiMin,posimax;
   float promedo;
   promedo=PromVector(vector,tam);
   posiMin=posMin(vector,tam);
   posimax=posMax(vector,tam);
   int minimo=minVector(vector,tam);
      int maximo=MaxVector(vector,tam);
    printf("%f", promedo);
    MostrarPromedioDivisiblesPor(vector,tam,2);


    return 0;
}//Fin main
int posMin(int v[], int tam){
    int posicionMin;
    int numeroMin;
    posicionMin=0;
    numeroMin=v[0];
    if (tam>0){

    for(int i=0;i<tam;i++){
        if(numeroMin>v[i]){
            numeroMin=v[i];
            posicionMin=i;
        }
    }
    }
    else {
        printf("Error de tamanio, debe ser mayor a cero.");
        posicionMin=-1;
    }
    return posicionMin;
}
int posMax(int v[], int tam){
    int posicionMax;
    int numeroMax;
    posicionMax=0;
    numeroMax=v[0];
    if (tam>0){

    for(int i=0;i<tam;i++){
        if(numeroMax<v[i]){
            numeroMax=v[i];
            posicionMax=i;
        }
    }
    }
    else {
        printf("Error de tamanio, debe ser mayor a cero.");
        posicionMax=-1;
    }
    return posicionMax;
}
int minVector(int v[], int tam){

    int numeroMin;

    numeroMin=v[0];
    if (tam>0){

    for(int i=0;i<tam;i++){
        if(numeroMin>v[i]){
            numeroMin=v[i];

        }
    }
    }
    else {
        printf("Error de tamanio, debe ser mayor a cero.");
      numeroMin=-1;
    }
    return numeroMin;
}
int MaxVector(int v[], int tam){

    int numeroMax;

    numeroMax=v[0];
    if (tam>0){

    for(int i=0;i<tam;i++){
        if(numeroMax<v[i]){
            numeroMax=v[i];

        }
    }
    }
    else {
        printf("Error de tamanio, debe ser mayor a cero.");
       numeroMax =-1;
    }
    return numeroMax ;
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
float PromVector(int arreglo[], int tam){
    float acumulador=0;
    int cont=0;
    float promeVector;
        if (tam>0){
    for(int i=0;i<tam;i++) {
    cont++;
    acumulador+=arreglo[i];

    }
    promeVector = (float) acumulador / cont;
    }
    else {
        printf("Error de tamanio, debe ser mayor a cero.");
       promeVector =-1;
    }
    return promeVector;
}
void sumaVectores(int v[], int w[], int resultado[], int tam){
    if (tam>0){
        for(int i=0;i<tam;i++) {
            resultado[i]=v[i]+w[i];

        }

    }
    else {
        printf("Error de tamanio, debe ser mayor a cero.");
    }
}
void MostrarArregloInt(int arreglo[],int tam){

if(tam>0){
for(int i=0;i<tam;i++) {
printf("[%d]",arreglo[i]);

}
printf("\n");
}

}
void restaVectores(int v[], int w[], int resultado[], int tam){
    if (tam>0){
        for(int i=0;i<tam;i++) {
            resultado[i]=v[i]-w[i];
        }
    }
    else {
        printf("Error de tamanio, debe ser mayor a cero.");
    }
}
void ordenamientoBurbujaMenorAMayor(int v[], int tam){
    int aux;
    for(int i=0;i<tam-1;i++){
        for(int j=i+1;j<tam;j++) {
            if(v[i]>v[j]){
                aux=v[i];
                v[i]=v[j];
                v[j]=aux;
            }
        }
    }

}
void esCapicuaPalabra(char palabra[], int tam){
    int bandera=0;

    for(int i=0;i<tam;i++){
        for(int j=tam-1;j>=0;j--){
            while(i!=j){
                if(palabra[i]!=palabra[j]){
                    bandera=1;
                    break;
                }

            }
        }
    }
    if(bandera==1){
        printf("la palabra: %s no es capicua.",palabra);
    }
    else{
        printf("la palabra: %s  es capicua.",palabra);
    }
}
