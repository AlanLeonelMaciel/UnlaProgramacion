#include "canal.h"

void llenarStructDesdeArchivo(char nombreArchivo[40], CanalPtr canales){

    FILE *archivo = fopen(nombreArchivo, "r"); //Apertura del archivo modo lectura
    if (archivo == NULL) {    //En caso de que no exista el archivo
        perror("Error al abrir el archivo1");
    }
    char linea[200]; // Asumiendo que una línea no superará los 200 caracteres
    char *aux;
    int cont=0;
    //char *rating;
    //float ratingFloat;
    while (fgets(linea, sizeof(linea), archivo) != NULL) {
        aux = strtok(linea, ";");// esta funcion devuelve un "token" es decir un texto delimitado por ;
        if (aux == NULL) {
            printf("Error al leer la nombre\n");
            continue;
        }
        strcpy(canales[cont].nombre,aux);
        /////////////
        aux = strtok(NULL, ";");// esta funcion devuelve un "token" es decir un texto delimitado por ;
        if (aux == NULL) {
            printf("Error al leer la rating\n");
            continue;
        }
        canales[cont].rating=atof(aux);
        ///////////////////////////////
        aux = strtok(NULL, ";");// esta funcion devuelve un "token" es decir un texto delimitado por ;
        if (aux == NULL) {
            printf("Error al leer tipo\n");
            continue;
        }
        int longitud=strlen(aux);

             /////// donde estaba el salto de linea se pone caracter nulo.
        if(aux[longitud-1]=='\n'){
            aux[longitud-1]='\0';

        }
        strcpy(canales[cont].tipo,aux);
        ///////////////////// fin de carga a estruct.
        cont++;
    }//finWhile
}
//////////////////////////////////////////////
int contarLineasArchivo(char nombreArchivo[40]){
    int cont=0;
        /////////////////////////////////////////////////////////////////
    FILE *archivo = fopen(nombreArchivo, "r"); //Apertura del archivo modo lectura
    if (archivo == NULL) {    //En caso de que no exista el archivo
        perror("Error al abrir el archivo2");

    }
    char linea[200]; // Asumiendo que una línea no superará los 200 caracteres
    while (fgets(linea, sizeof(linea), archivo) != NULL) {
        cont++;
    }
    return cont;
}
//////////////////////////////////////////////////////////
CanalPtr crearArrayCanales(int cantCanales){

    CanalPtr canales=(CanalPtr)malloc(sizeof(struct Canal)*cantCanales);
    return canales;

}
//////////////////////////////////
void mostrarCanales(CanalPtr canales,int cantCanales){
    if(canales!=NULL){
            for(int i=0;i<cantCanales;i++){
        printf(
            "\nNombre: %s\nRating: %.2f\nTipo: %s\n",
            canales[i].nombre,
            canales[i].rating,
            canales[i].tipo
        );
    }
    }else{
        printf("No hay canales\n");
    }

}
char** CrearArrayDinamicoDeStringsDinamicos(int lineas, int caracteres){

    char** arrayStrings;
    arrayStrings = (char**)malloc(sizeof(char*) * lineas);
    for (int i = 0; i < lineas; i++) {
        arrayStrings[i] = (char*)malloc(sizeof(char) * caracteres); // Asignar espacio para una cadena de 100 caracteres
        if (arrayStrings[i] == NULL) {
            perror("Error en la asignación de memoria");
            exit(EXIT_FAILURE);
        }
        }
    return arrayStrings;
}
/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////

void LiberarArrayDinamicoDeStringsDinamicos(char** arrayStrings, int lineas) {
    if (arrayStrings == NULL) {
        return; // Si el puntero es NULL, no hay nada que liberar
    }

    for (int i = 0; i < lineas; i++) {
        if (arrayStrings[i] != NULL) {
            free(arrayStrings[i]); // Liberar la memoria de cada cadena
        }
    }

    free(arrayStrings); // Liberar la memoria del array de punteros
}
//////////////////////////////////////////////////////////////////////////////
int contarCanalesRatingMenor5(CanalPtr canales,int cantCanales){
    int cont=0;
    for(int i=0;i<cantCanales;i++){
        if(canales[i].rating<5){
            cont++;
        }
    }
    return cont;
}
//////////////////////////////////////////////////////////
CanalPtr guardarCanalesRatingMenor5(CanalPtr canales,int cantCanales,int cantRatingMenor5){
        int cont=0;
        CanalPtr nuevosCanales;
        if(cantRatingMenor5==0){
            nuevosCanales=NULL;
        }else{
           nuevosCanales =crearArrayCanales(cantRatingMenor5);
        }



        for(int i=0;i<cantCanales;i++){
        if(canales[i].rating<5){
            nuevosCanales[cont]=canales[i];
            cont++;
        }
    }
    return nuevosCanales;
}
//////////////////////////////////////////////////
void guardarCanalesEliminados(CanalPtr canalesEliminados,int cantRatingMenor5){

    FILE *archivo = fopen("eliminados.txt", "w"); //Apertura del archivo modo lectura
    if (archivo == NULL) {    //En caso de que no exista el archivo
        perror("Error al abrir el archivo2");

    }
    for(int i=0;i<cantRatingMenor5;i++){
        if(cantRatingMenor5-1!=i){
            fprintf( archivo,"%s;%.2f;%s\n",canalesEliminados[i].nombre,canalesEliminados[i].rating,canalesEliminados[i].tipo);

        } else{
        fprintf( archivo,"%s;%.2f;%s",canalesEliminados[i].nombre,canalesEliminados[i].rating,canalesEliminados[i].tipo);

        }

    }
    fclose(archivo);
}
