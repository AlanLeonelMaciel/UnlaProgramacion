#include <stdio.h>
#include <stdlib.h>

int main()
{
    char palabra[100];
    char reversePalabra[100];
    int cont=0;
    int tam;
    printf("Identificar si es capicua\n\n");
    printf("Ingrese una palabra: ");
    fflush(stdin);
    gets(palabra);
    tam=strlen(palabra);
    for(int i=0;i<tam;i++) {
        printf("%c",palabra[i]);

    }
    printf("\t\t");
        for(int i=tam-1;i>=0;i--) {


        reversePalabra[cont]=palabra[i];
        cont++;
    }
     reversePalabra[cont]='\0';
     if(strcmp(palabra, reversePalabra)==0){
        printf("[Es capicua]\n\n\n\n");
     }
     else {
        printf("[No es capicua]\n\n\n");
     }
    //printf("%d", strlen(palabra));
    return 0;
}
