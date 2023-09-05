#include <stdio.h>
#include <stdlib.h>

int main()
{
   //FILE * archivo= fopen("nombres.txt","at");
    // ESCRITURA
   // fprintf(archivo,"leonel.\n");
    //fclose(archivo);
    //LECTURA
    FILE *archivo=fopen("nombres.txt","r");
    char informacionNombres[100]="";
    while(!feof(archivo)) {
        fgets(informacionNombres,100,archivo);
        printf("\nrecupere la info: %s",informacionNombres);
    }
    fclose(archivo);


    return 0;
}
