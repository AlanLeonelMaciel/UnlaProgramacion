#include <stdio.h>
#include <string.h>

// Definición de estructura para los registros
struct Registro {
    int id;
    char nombre[50];
    int edad;
};

// Declaración de funciones
void alta(struct Registro registros[], int* total_registros);
void baja(struct Registro registros[], int* total_registros);
void modificacion(struct Registro registros[], int total_registros);
void mostrarRegistros(struct Registro registros[], int total_registros);

int main() {
    struct Registro registros[100]; // Arreglo para almacenar los registros
    int total_registros = 0; // Variable para llevar cuenta del total de registros

    int opcion;
    while (1) {
        printf("\n");
        printf("1. Alta\n");
        printf("2. Baja\n");
        printf("3. Modificación\n");
        printf("4. Mostrar registros\n");
        printf("5. Salir\n");
        printf("Selecciona una opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                alta(registros, &total_registros);
                break;
            case 2:
                baja(registros, &total_registros);
                break;
            case 3:
                modificacion(registros, total_registros);
                break;
            case 4:
                mostrarRegistros(registros, total_registros);
                break;
            case 5:
                printf("Saliendo...\n");
                return 0;
            default:
                printf("Opción inválida. Inténtalo de nuevo.\n");
        }
    }
}

void alta(struct Registro registros[], int* total_registros) {
    if (*total_registros < 100) {
        struct Registro nuevoRegistro;
        printf("Ingrese el ID: ");
        scanf("%d", &nuevoRegistro.id);
        printf("Ingrese el nombre: ");
        scanf("%s", nuevoRegistro.nombre);
        printf("Ingrese la edad: ");
        scanf("%d", &nuevoRegistro.edad);

        registros[*total_registros] = nuevoRegistro;
        (*total_registros)++;
        printf("Registro agregado exitosamente.\n");
    } else {
        printf("No se pueden agregar más registros. Límite alcanzado.\n");
    }
}

void baja(struct Registro registros[], int* total_registros) {
    int id;
    printf("Ingrese el ID del registro a eliminar: ");
    scanf("%d", &id);

    int indice = -1; // Inicializar el índice en -1 para indicar que no se encontró el registro
    for (int i = 0; i < *total_registros; i++) {
        if (registros[i].id == id) {
            indice = i;
            break;
        }
    }

    if (indice != -1) {
        // Desplazar los registros a la izquierda para eliminar el registro
        for (int i = indice; i < *total_registros - 1; i++) {
            registros[i] = registros[i + 1];
        }
        (*total_registros)--;
        printf("Registro eliminado exitosamente.\n");
    } else {
        printf("Registro no encontrado.\n");
    }
}

void modificacion(struct Registro registros[], int total_registros) {
    int id;
    printf("Ingrese el ID del registro a modificar: ");
    scanf("%d", &id);

    int indice = -1; // Inicializar el índice en -1 para indicar que no se encontró el registro
    for (int i = 0; i < total_registros; i++) {
        if (registros[i].id == id) {
            indice = i;
            break;
        }
    }

    if (indice != -1) {
        printf("Registro encontrado. Ingrese los nuevos datos:\n");
        printf("Ingrese el nuevo ID: ");
        scanf("%d", &registros[indice].id);
        printf("Ingrese el nuevo nombre: ");
        getchar(); // Consumir el salto de línea pendiente en el buffer
        fgets(registros[indice].nombre, 50, stdin);
        //scanf("%s", registros[indice].nombre);
        printf("Ingrese la nueva edad: ");
        scanf("%d", &registros[indice].edad);
        printf("Registro modificado exitosamente.\n");
    } else {
        printf("Registro no encontrado.\n");
    }
}
void mostrarRegistros(struct Registro registros[], int total_registros) {
    if (total_registros > 0) {
        printf("Registros almacenados:\n");
        for (int i = 0; i < total_registros; i++) {
            printf("ID: %d\n", registros[i].id);
            printf("Nombre: %s\n", registros[i].nombre);
            printf("Edad: %d\n", registros[i].edad);
            printf("--------------------------\n");
        }
    } else {
        printf("No hay registros almacenados.\n");
    }
}
