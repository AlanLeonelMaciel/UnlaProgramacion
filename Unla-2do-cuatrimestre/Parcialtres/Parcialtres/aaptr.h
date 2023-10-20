#ifndef AAPTR_H_INCLUDED
#define AAPTR_H_INCLUDED

/// ARRAYS CON PUNTEROS

// Unidimensionales
int *crearVectorEnteros(int tam);
void llenarVectorEnteros(int *ptrVec, int tam);
void mostrarVectorEnteros(int *ptrVec, int tam);
char *asignarMemoriaCadena(int cantLetras);

// Bidimensionales
int **crearMatrizEnteros(int filas, int columnas);
void llenarMatrizEnteros(int **ptrMatriz, int filas, int columnas);
void liberarMemoriaMatriz(int **ptrMatriz, int filas);

// Strings
char **crearArrayStrings(int cantLineas, int cantLetras);
void mostrarArrayStrings(char **cadenas, int cantLineas);


/// MANIPULACION DE ARCHIVOS
int contarLineasArchivo(char *nombreArchivo);
void leerArchivoCompleto(char *nombreArchivo);
void agregarLineaAlFinal(char *nombreArchivo, char *nuevaLinea);
void recuperarLineas(char *nombreArchivo, char **cadenas, int cantLetras);
void sobrescribirLinea(
    char *nombreArchivo,
    int cantLetras,
    int nroLineaBuscada,
    char *nuevaLinea
);
void insertarLineaEn(
    char *nombreArchivo,
    int posicionLinea,
    int cantLetras,
    char *nuevaLinea
);


/// ALEATORIOS
void eliminarSaltoDeLinea(char *cadena);

// Estructura de ejemplo
typedef struct {
    char nombre[15];
    char apellido[15];
    int nroCamiseta;
    float promedioGoles;
    char club[30];
} Jugador;

void txtAEstructura(int cantMaxLetras, char *nombreArchivo, Jugador *jugadores);
void ordenamientoBurbujaAsc(int *v, int tam);
void ordenamientoBurbujaDesc(int *v, int tam);

void mostrarJugadores(int cantJugadores, Jugador *jugadores);

void guardarTxtOrdenado(int cantJugadores, Jugador *jugadores);

void ordenamientoJugadoresDesc(int cantJugadores, Jugador *jugadores);
///-------------------------------------------------------------------
void recuperaNumeros(char nombreArchivo[], int *vectorNumeros, int cantNumeros);
void guardarNumOrdenado(char nombreArchivo[], int *vectorNumeros, int cantNumeros);
///-------------------------------------------------------------------
#endif // AAPTR_H_INCLUDED
