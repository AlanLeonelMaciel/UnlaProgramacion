#include <stdio.h>
#include <stdlib.h>
void esCapicuaPalabra(char palabra[], int tam);
int main()
{
    char palabrr[]="reconzcer";
    esCapicuaPalabra(palabrr,9);
    return 0;
}//fin main
void esCapicuaPalabra(char palabra[], int tam){
    int bandera=0;
    int cont= tam-1;

    for(int i=0;i<tam;i++){

                if (i-cont!=-1&&i-cont!=0){
                if(palabra[i]!=palabra[cont]){
                    bandera=1;
                    break;
                }
        }
        else{
            break;
        }
        cont--;
    }
    if(bandera==1){
        printf("la palabra: %s no es capicua.",palabra);
    }
    else{
        printf("la palabra: %s  es capicua.",palabra);
    }
}
