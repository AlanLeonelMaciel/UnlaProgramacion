#include "Puntos.h"

PuntosPtr crearPuntos(int cod, int actuales, int puntuacionMax) {
    PuntosPtr nuevoPuntos = (PuntosPtr)malloc(sizeof(struct Puntos));
    if (nuevoPuntos != NULL) {
        nuevoPuntos->codPuntuacion = cod;
        nuevoPuntos->actuales = actuales;
        nuevoPuntos->puntuacionMax = puntuacionMax;
    }
    return nuevoPuntos;
};

// Getter para obtener el valor de "actuales" de un objeto Puntos
int getActuales(PuntosPtr puntos) {
    return puntos->actuales;
};
int getCodPuntuacion(PuntosPtr puntos) {
    return puntos->codPuntuacion;
};
int getPuntuacionMaxima(PuntosPtr puntos) {
    return puntos->puntuacionMax;
};
// Setter para establecer el valor de "actuales" de un objeto Puntos
void setActuales(PuntosPtr puntos, int actuales) {
    puntos->actuales = actuales;
};
void setCodPuntuacion(PuntosPtr puntos, int cod) {
    puntos->codPuntuacion = cod;
};
void setPuntuacionMaxima(PuntosPtr puntos, int maxima) {
    puntos->puntuacionMax = maxima;
};
int recuperarPuntosMaxDni(int dni, int **rankingMatriz, int filas) {
    int puntuacionMaxima=0;
    for (int i = 0; i < filas; i++) {
        if (rankingMatriz[i][0] == dni) {
            // Si se encuentra el DNI, se devuelve el valor correspondiente
            puntuacionMaxima=rankingMatriz[i][1];
        }
    }
    return puntuacionMaxima;
}

