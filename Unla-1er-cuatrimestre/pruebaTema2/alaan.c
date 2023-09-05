#include "alaaan.h"

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
int CargarArregloAleatoriamenteInt(int array[], int tam, int desde, int hasta) {
int retorno=1;

for(int i=0;i<tam;i++) {
array[i]=GenerarAleatorioInt(desde,hasta);
retorno=0;
}
return retorno;
}
void MostrarArregloInt(int arreglo[],int tam){

if(tam>0){
for(int i=0;i<tam;i++) {
printf("[%d]",arreglo[i]);

}
printf("\n");
}

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
int CargarArregloAleatoriamenteIntPares(int array[], int tam, int desde, int hasta) {
int retorno=1;

for(int i=0;i<tam;i++) {

array[i]=GenerarAleatorioInt(desde,hasta);
while(!(array[i]%2==0)) {
array[i]=GenerarAleatorioInt(desde,hasta);
}
retorno=0;
}
return retorno;
}
void  MostrarArregloIntPosImpares(int arreglo[],int tam){
printf("Se muestra el arreglo en sus posiciones impares: \n");
for(int i=0;i<tam;i++) {

if (!(i%2==0)) {
printf("[%d]",arreglo[i]);
}



}
printf("\n");
}
void MostrarElMayorDeLosNumerosMenoresA(int arreglo[],int tam){
int contador=0;
int mayor;
printf("Se muestra El Mayor De Los Numeros Menores A 50: \n");
for(int i=0;i<tam;i++) {

if (arreglo[i]<50) {
contador++;
if(contador==1){
mayor=arreglo[i];
}
else {
if (mayor<arreglo[i]) {
mayor=arreglo[i];
}
}
}



}
printf("%d",mayor);
printf("\n");
}
void cargarVectorConAleatoriosSinRepetir(int v[], int tam, int mini, int maxi) {
if(mini<maxi&&tam>0&&((maxi-mini)+1)>=tam){
int hayCopias = 0;  // Flag
for (int i = 0; i < tam; i++) {
do {
v[i] = GenerarAleatorioInt(mini, maxi);
hayCopias = 0;  // Reset the flag before checking for duplicates

// Check for duplicates with previous elements
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
int elegirTamanio(){
int numero;
do{
printf("Elegir tam: \n");
scanf("%d",&numero);
}while(numero<1);

return numero;
}
/////////////////////////////////////////////////////Dibujar Triangulo///////////////////////////////////////
void DibujarTriangunlo(int base, char letra){
    letra=tolower(letra);
    if (letra>'z'||letra<'a') {
        printf("Error, no es una letra del abecedario.");
    }
    else {
        for(int i=0;i<base;i++) {
        for(int j=0;j<=i;j++){
            printf("%c\t",letra);
            letra++;
            if(letra>'z'){
                letra='a';
            }
        }
        printf("\n");
    }
    }


}
