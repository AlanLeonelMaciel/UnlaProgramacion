#ifndef ESTRUCTURAS_H_INCLUDED
#define ESTRUCTURAS_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Estudiante{
    int primariKey;
    char nombre[100];
    char apellido[100];
    float promedio;
    int claveForanea;
};
typedef struct Estudiante *estudiantePtr;

struct Materia{
    char nombre[100];
    char turno;
    int primariKey;
    estudiantePtr estudiantes;
};
typedef struct Materia *materiaPtr;

estudiantePtr CrearEstudiante();
materiaPtr CrearMateria();
void CargarEstudiantesArchivo(estudiantePtr, int tam);
void InicializarArregloNull(estudiantePtr estudiantes[] , int tamanio);
estudiantePtr CrearEstudiantes(int tam);
#endif // ESTRUCTURAS_H_INCLUDED
