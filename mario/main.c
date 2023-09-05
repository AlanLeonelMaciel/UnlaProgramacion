#include <stdio.h>

int main() {
    int marioX = 0; // Posición horizontal de Mario
    int marioY = 0; // Posición vertical de Mario

    int obstaculoX = 5; // Posición horizontal del obstáculo
    int obstaculoY = 0; // Posición vertical del obstáculo

    while (1) {
        // Lógica del juego
        if (marioX == obstaculoX && marioY == obstaculoY) {
            printf("¡Mario ha chocado con el obstáculo!\n");
            break;
        }

        // Mostrar el estado del juego
        for (int y = 0; y < 10; y++) {
            for (int x = 0; x < 10; x++) {
                if (x == marioX && y == marioY) {
                    printf("M");
                } else if (x == obstaculoX && y == obstaculoY) {
                    printf("X");
                } else {
                    printf("-");
                }
            }
            printf("\n");
        }

        // Leer la entrada del jugador
        char movimiento;
        printf("Ingrese un movimiento (w/a/s/d): ");
        scanf(" %c", &movimiento);

        // Actualizar la posición de Mario en función del movimiento
        switch (movimiento) {
            case 'w':
                marioY--;
                break;
            case 'a':
                marioX--;
                break;
            case 's':
                marioY++;
                break;
            case 'd':
                marioX++;
                break;
            default:
                printf("Movimiento inválido\n");
        }
    }

    return 0;
}
