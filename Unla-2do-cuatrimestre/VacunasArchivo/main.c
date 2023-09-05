#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define DOSIS 5
#define LONG_LOTE 10
struct Vacuna{
char nombre[50];
char lote[LONG_LOTE];
};
struct Persona {
char nombre[50];
int edad;
int documento;
struct Vacuna vacunas[DOSIS];
};

struct Persona CrearPersona();
void MostrarPersona(struct Persona p1);
char * generarAlfaNumericoAleatorio();
void LeerPersonasArchivo();
////////////////////////////////////////////
int main()
{
    char respuesta;
    int cantPersonas;
    srand(time(0));
    printf("Cuantas personas desea ingresar? \n");
    scanf("%d",&cantPersonas);
    fflush(stdin);
    for(int i=0;i<cantPersonas;i++){

        struct Persona persona3 = CrearPersona();
        GuardarPersonaArchivo(persona3);
        //free(&persona3);
    }

    //MostrarPersona(persona3);

    printf("\nDesea abrir el archivo de personas vacunadas? S/N \n");
    scanf("%c",&respuesta);
    fflush(stdin);
    if(respuesta == 'S' || respuesta == 's'){
        LeerPersonasArchivo();
    }




    return 0;
}
//////////////////////////////////////
char * generarAlfaNumericoAleatorio(){
    char caracteres[]={"ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789"};
    int longitud = LONG_LOTE - 1; // Para dejar espacio para el carácter nulo
    char* lote = (char*)malloc(longitud + 1); // +1 para el carácter nulo
    for (int i = 0; i < longitud; i++) {
        int indice = rand() % (sizeof(caracteres) - 1);
        lote[i] = caracteres[indice];
    }
    lote[0]='#';
    lote[longitud] = '\0'; // Agregar el carácter nulo al final
    return lote;

}
struct Persona CrearPersona(){
    struct Persona persona1;
    printf("\nIngrese el nombre de la persona: \n");
    gets(persona1.nombre);
    printf("\nIngrese la edad: \n");
    scanf("%d",&persona1.edad);
    printf("\nIngrese el documento: \n");
    scanf("%d",&persona1.documento);
    fflush(stdin);
    for(int i=0;i<DOSIS;i++){
    printf("\nIngrese nombre de vacuna: \n");
    gets(persona1.vacunas[i].nombre);
    strcpy(persona1.vacunas[i].lote, generarAlfaNumericoAleatorio());
    }

    return persona1;
}
void MostrarPersona(struct Persona p1){
    printf("\nNombre: \n");
    printf("%s",p1.nombre);
    printf("\nEdad: \n");
    printf("%d",p1.edad);
    printf("\nDocumento: \n");
    printf("%d",p1.documento);
    printf("\nVacunas dadas: \n");

    for(int i=0;i<DOSIS;i++){
    printf("\n%s\n",p1.vacunas[i].nombre);
    printf("Lote: %s\n",p1.vacunas[i].lote);
    }

}
void GuardarPersonaArchivo(struct Persona p1) {
    char str [50];
    FILE * archivo= fopen("personasVacunadas.txt","at");
    fprintf(archivo,"\nNombre: \n");
    fprintf(archivo,p1.nombre);
    fprintf(archivo,"\nEdad: \n");
    snprintf(str, sizeof(str), "%d", p1.edad);
    fprintf(archivo,str);
    fprintf(archivo,"\nDocumento: \n");
    snprintf(str, sizeof(str), "%d", p1.documento);
    fprintf(archivo,str);
    fprintf(archivo,"\nVacunas dadas: \n");

    for(int i=0;i<DOSIS;i++){
    fprintf(archivo,p1.vacunas[i].nombre);
    fprintf(archivo," ");

    fprintf(archivo," Lote: %s",p1.vacunas[i].lote);
    fprintf(archivo,"\n");

    }
    fclose(archivo);
}
void LeerPersonasArchivo() {
    FILE *archivo=fopen("personasVacunadas.txt","r");
    char informacionNombres[200]="";
    while(!feof(archivo)) {
        fgets(informacionNombres,sizeof(informacionNombres),archivo);
        printf("%s",informacionNombres);
    }
    fclose(archivo);
}
