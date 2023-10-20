#include "estructuras.h"

void InicializarArregloNull(estudiantePtr estudiantes[] ,int tamanio ){
        for (int i = 0; i < tamanio; i++) {
        estudiantes[i] = NULL; // Establece cada elemento como NULL
    }
}

estudiantePtr CrearEstudiante(){
    estudiantePtr estudiante= (estudiantePtr)malloc(sizeof(struct Estudiante));
    return estudiante;
}
estudiantePtr CrearEstudiantes(int tam){
    estudiantePtr estudiantes= (estudiantePtr)malloc(sizeof(struct Estudiante)*tam);
    return estudiantes;
}
materiaPtr CrearMateria(){
    materiaPtr materia= (materiaPtr)malloc(sizeof(struct Materia));
    return materia;
}
void CargarEstudiantesArchivo(estudiantePtr estudiantesPtr, int tam){
   /* FILE *archivo = fopen("Estudiantes.txt", "r"); //Apertura del archivo modo lectura
    if (archivo == NULL) {    //En caso de que no exista el archivo
        perror("Error al abrir el archivo");
        return;
    }*/
    estudiantesPtr=CrearEstudiantes(tam);
    estudiantesPtr[0].primariKey=4;
    estudiantesPtr[1].primariKey=45;
    printf("%d %d",estudiantesPtr[0].primariKey,estudiantesPtr[1].primariKey );
    return;
    //InicializarArregloNull(estudiantesPtr,tam);
    char linea[100]; // Asumiendo que una línea no superará los 100 caracteres

   /* while (fgets(linea, sizeof(linea), archivo) != NULL) { //fgets devuelve un puntero, cuando llegue a la ultima linea
                                             // arrojara un null
        char primariKey[100];
        char nombre[100];
        char apellido[100];
        char promedio[100];
        char claveForanea[100];
        char *token;


        token = strtok(linea, ";");// esta funcion devuelve un "token" es decir un texto delimitado por ;
        // Copiar el primer token a primariKey
        if (token != NULL) {
        strncpy(primariKey, token, sizeof(primariKey) - 1);
        primariKey[sizeof(primariKey) - 1] = '\0'; // Asegurarse de que la cadena termina con '\0'
    }
        token = strtok(NULL, ";");

        if (token == NULL) {
            printf("Error al leer nombre\n");
            continue;
        }
        token = strtok(NULL, ";");

        if (token == NULL) {
            printf("Error al leer apellido\n");
            continue;
        }
        token = strtok(NULL, ";");

        if (token == NULL) {
            printf("Error al leer promedio\n");
            continue;
        }
        token = strtok(NULL, ";");

        if (token == NULL) {
            printf("Error al leer claveForanea\n");
            continue;
        }



        //numeroPreguntaCorrecta = atoi(numeroPreguntaCorrectaStr); //como strtok arroja un string necesitamos convertir con atoi numeropregunta a un numero int


        /*PreguntaAux->nroPregunta=numeroPreguntaCorrecta;
        strcpy(PreguntaAux->pregunta,pregunta);*/



    //}
    //fclose(archivo);

}
