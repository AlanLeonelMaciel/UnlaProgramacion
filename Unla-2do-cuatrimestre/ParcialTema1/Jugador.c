#include "Jugador.h"

JugadorPtr CrearJugador(){
    JugadorPtr nuevoJugador;
    nuevoJugador=(JugadorPtr)malloc(sizeof(struct Jugador));
    return nuevoJugador;
}

JugadorPtr CrearJugadores(int tam){
    JugadorPtr jugadores;
    jugadores=(JugadorPtr)malloc(sizeof(struct Jugador)*tam);
    return jugadores;
}

void MostrarJugadores(int TAM, JugadorPtr jugadores){
    for(int i=0;i<TAM;i++){
        printf("\nJugador %d: \n Nombre: %s\tApellido: %s\tNumero de Camiseta: %d\tPromedio gol: %f\tClub: %s\n",i+1,jugadores[i].nombre,jugadores[i].apellido,jugadores[i].numCamiseta,jugadores[i].promGol,jugadores[i].club);
    }
}

struct Jugador  LLenarJugador(char nombre[40],char apellido[40],int numCamiseta, float promedioGol,char club[40]){
    struct Jugador Jugador;
    Jugador.numCamiseta =numCamiseta;
    strcpy(Jugador.nombre,nombre);
    strcpy(Jugador.apellido,apellido);
    Jugador.promGol=promedioGol;
    strcpy(Jugador.club,club);
    return Jugador;
}
int ContarLineasArchivo(char nombreArchivo[40]){
    int cont=0;
        /////////////////////////////////////////////////////////////////
    FILE *archivo = fopen(nombreArchivo, "r"); //Apertura del archivo modo lectura
    if (archivo == NULL) {    //En caso de que no exista el archivo
        perror("Error al abrir el archivo");
        return;
    }

    char linea[200]; // Asumiendo que una línea no superará los 200 caracteres

    while (fgets(linea, sizeof(linea), archivo) != NULL) {


        cont++;
    }
    return cont;
}
