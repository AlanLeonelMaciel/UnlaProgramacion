#include "num.h"



int ContarLineasArchivoPositivo(char nombreArchivo[40]){
    int cont=0;
        /////////////////////////////////////////////////////////////////
    FILE *archivo = fopen(nombreArchivo, "r"); //Apertura del archivo modo lectura
    if (archivo == NULL) {    //En caso de que no exista el archivo
        perror("Error al abrir el archivo");
        return cont;
    }
    char linea[200]; // Asumiendo que una línea no superará los 200 caracteres
    while (fgets(linea, sizeof(linea), archivo) != NULL) {
        if(atoi(linea)>0){
            cont++;
        }

    }
    return cont;
}
/////
int *crearVectorEnteros(int tam) {
    int *ptr = (int *) malloc(tam * sizeof(int));
    return ptr;
}
///
void recuperaNumerosPorLineaPositivos(char nombreArchivo[], int *vectorNumeros, int cantNumeros){

    FILE *archivo = fopen(nombreArchivo, "r");
    if(archivo == NULL){

        printf("ERROR AL ABRIR EL ARCHIVO");
        exit(1);
    }

    int cont=0;
    char info[40];
    while (fgets(info, 40, archivo)!=NULL){
        if(atoi(info)>0){
        vectorNumeros[cont] = atoi(info);
        cont++;
        }

    }

    fclose(archivo);
}
void mostrarVectorEnteros(int *ptrVec, int tam) {
    for(int i=0; i<tam; i++) {
        printf("[%d]", ptrVec[i]);
    }
    printf("\n");
}
void guardarVectorEntero(char nombreArchivo[], int *vectorNumeros, int cantNumeros){

    FILE *archivo = fopen(nombreArchivo, "w");

    if(archivo == NULL){

        printf("NO SE PUDO ABRIR EL ARCHIVO");
        exit(1);
    }

    for (int i=0; i<cantNumeros; i++){

        if(cantNumeros -1 != i){
            fprintf(archivo, "%d\n", vectorNumeros[i]);
        }else{
            //si es el ultimo, lo guardo sin salto de linea.
            fprintf(archivo, "%d", vectorNumeros[i]);
        }
    }
    fclose(archivo);
}
///
void fusionarVectoresEnteros(int* vectorResultado,int tamVectorResultado,int* vector1,int tamVector1, int* vector2  ){
        int cont=0;
        for(int i=0;i<tamVectorResultado;i++){
        if(i<tamVector1){
            vectorResultado[i]=vector1[i];
        }else{
            vectorResultado[i]=vector2[cont];
            cont++;
        }
    }

}
