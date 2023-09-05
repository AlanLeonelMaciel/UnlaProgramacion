#include <stdio.h>
#include <stdlib.h>

int main()
{
    int aux;
    int numeros[2][4] ={1,2,3,5,8,6,4,4};

    for (int i=0;i<2;i++){
            for(int j =0;j<4;j++){
                printf("- %d -",numeros[i][j]);
            }
            printf("\n");

    }
        for (int i=0;i<1;i++){

            if(numeros[i][3]>numeros[i+1][3]){
                for(int j=3;j>=0;j--){
                aux=numeros[i][j];
                numeros[i][j]=numeros[i+1][j];
                numeros[i+1][j]=aux;
                }

            }

    }
    printf("\n");
    for (int i=0;i<2;i++){
            for(int j =0;j<4;j++){
                printf("- %d -",numeros[i][j]);
            }
            printf("\n");

    }
   /* for(int i=0;i<3;i++) {
        for(int j=i+1;j<4;j++){
            if(numeros[i]<numeros[j]){
                 aux=numeros[i];
                numeros[i]=numeros[j];
                numeros[j]=aux;
            }
        }
    }*/


    return 0;
}
