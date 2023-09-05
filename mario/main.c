#include <stdio.h>

int main() {
    int marioX = 0; // Posici�n horizontal de Mario
    int marioY = 0; // Posici�n vertical de Mario

    int obstaculoX = 5; // Posici�n horizontal del obst�culo
    int obstaculoY = 0; // Posici�n vertical del obst�culo

    while (1) {
        // L�gica del juego
        if (marioX == obstaculoX && marioY == obstaculoY) {
            printf("�Mario ha chocado con el obst�culo!\n");
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

        // Actualizar la posici�n de Mario en funci�n del movimiento
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
                printf("Movimiento inv�lido\n");
        }
    }

    return 0;
}
