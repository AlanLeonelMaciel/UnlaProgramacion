#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*Ejercicio 1: Crear una matriz de 12 columnas y 4 renglones, de números decimales,
cada valor explica las ganancias de 4 empresas distintas mes a mes.
A- Encontrar el total ganado por cada empresa al año.
B- Encontrar cuanto se gano por mes contando a todas las empresas
C- Calcular el total ganado por todas las empresas juntas.
D- Encontrar que empresa gano mas y en qué mes.
E- Que empresa gano menos y cuándo.
F- Calcular el promedio de ganancias de cada empresa por bimestres. ¿Cuál gano mas en cada bimestre?*/

int main()
{
float empresaMeses [4][12];
float acumEmpresa1,acumEmpresa2,acumEmpresa3,acumEmpresa4,acumB,acumBimestral;
float gananciaCadaMes[12];
float totalEmpresas,plataMejorMes,plataPeorMes;
int empresaMasGano, empresaMenosGano,mejorMes,peorMes;
float promedioBimestral[4][6] = {0};
int empresaMejorBimestre,mesMejorBimestre;
float plataMejorBimestre;
acumEmpresa1=0;
acumEmpresa2=0;
acumEmpresa3=0;
acumEmpresa4=0;
acumB=0;
acumBimestral=0;
int cont;
cont=0;
const int RANG = 100;
srand(time(NULL));

//Se rellena la matriz
for (int i=0;i<4;i++) {
for (int j=0;j<12;j++) {
empresaMeses[i][j]= rand()%RANG;
}
}
//Se muestra la matriz:
printf("Se muestra la matriz: \n");
for (int i=0;i<4;i++) {
printf("\n");
for (int j=0;j<12;j++) {
printf("[%.2f]",empresaMeses[i][j]);
}
}
printf("\n\n");

//Se desarrolla el punto A:
for (int i=0;i<4;i++) {
for (int j=0;j<12;j++) {
if (i==0) {
acumEmpresa1+=empresaMeses[i][j];
}
else {
if (i==1) {
acumEmpresa2+=empresaMeses[i][j];
}
else {
if (i==2){
acumEmpresa3+=empresaMeses[i][j];
}
else {
if (i==3) {
acumEmpresa4+=empresaMeses[i][j];
}
}
}
}
}
} //Fin for punto A

//Se realiza punto B
for(int j=0;j<12;j++){
for (int i=0;i<4;i++){
acumB+=empresaMeses[i][j];
}
gananciaCadaMes[j]=acumB;
acumB=0;
}
//se realiza punto C
totalEmpresas=acumEmpresa1+acumEmpresa2+acumEmpresa3+acumEmpresa4;

// D- Encontrar que empresa gano mas y en qué mes. Tambien se hace el punto E aqui mismo.
for(int i=0;i<4;i++){
for (int j=0;j<12;j++){
if (i==0) {
empresaMasGano=i+1;
empresaMenosGano=i+1;
mejorMes=j+1;
peorMes=j+1;
plataMejorMes=empresaMeses[i][j];
plataPeorMes=empresaMeses[i][j];
}
else{
// mejor ganancia entre todos los meses
if(plataMejorMes<empresaMeses[i][j]) {
empresaMasGano=i+1;
mejorMes=j+1;
plataMejorMes=empresaMeses[i][j];

}
//peor ganancia entre todos los meses
if(plataPeorMes>empresaMeses[i][j]) {
empresaMenosGano=i+1;
peorMes=j+1;
plataPeorMes=empresaMeses[i][j];
}
}

}
}//_Fin for de ejercicio D y E.

//Calcular el promedio de ganancias de cada empresa por bimestres. ¿Cuál gano mas en cada bimestre?
for(int i=0;i<4;i++){
for (int j=0;j<12;j++){
int bimestral;
bimestral=j/2;
promedioBimestral[i][bimestral]+=empresaMeses[i][j];
}
}
//Se reccorre la matriz bimestral:
for(int i=0;i<4;i++){
for (int j=0;j<6;j++){

promedioBimestral[i][j];
if (i==0) {
empresaMejorBimestre=i+1;
mesMejorBimestre=j+1;
plataMejorBimestre= promedioBimestral[i][j];

}
else {
if (plataMejorBimestre<promedioBimestral[i][j]) {
empresaMejorBimestre=i+1;
mesMejorBimestre=j+1;
plataMejorBimestre= promedioBimestral[i][j];
}
}
}
}
printf("El total ganado por cada empresa al anio es: Empresa1-%.2f Empresa2-%.2f Empresa3-%.2f Empresa4-%.2f \n",acumEmpresa1,acumEmpresa2,acumEmpresa3,acumEmpresa4);
for (int i=0;i<12;i++){
printf("Ganancia mensual teniendo en cuenta a todas las empresas: mes%d: %.2f\n",i+1,gananciaCadaMes[i]);
}
printf("Calcular el total ganado por todas las empresas juntas: %.2f\n",totalEmpresas); //c
printf("Encontrar que empresa gano mas y en qué mes: Empresa: %d en el mes: %d\n",empresaMasGano,mejorMes);//d
printf("Encontrar que empresa gano menos y cuando(mes): Empresa: %d en el mes: %d\n",empresaMenosGano,peorMes);//E
printf("Calcular el promedio de ganancias de cada empresa por bimestres. ¿Cuál gano mas en cada bimestre?\n");
for(int i=0;i<4;i++){
printf("\n");
for (int j=0;j<6;j++){
printf( "[%.2f]",promedioBimestral[i][j]);
}
}
return 0;
}

