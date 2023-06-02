#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*Generar un programa que permita dibujar un tri�ngulo, el procedimiento que lo dibuja recibe
como par�metros la base del triangulo y una letra del abecedario, el tri�ngulo deber� ser
completado por las letras que contin�an en el abecedario. Si se ingresa algo que no es una
letra del abecedario se deber� mostrar un mensaje de error.*/
void DibujarTriangunlo(int base, char letra);
int main()
{
    int base;
    char letra;

    printf("Inserte base: ");
    scanf("%d",&base);
    printf("Inserte letra: ");
    fflush(stdin);
    scanf("%c",&letra);
    DibujarTriangunlo(base,letra);

    return 0;
}//Fin main

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
