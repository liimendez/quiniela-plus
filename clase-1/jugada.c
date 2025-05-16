#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "jugada.h"

struct jugadaE {
    int numeros[20];
};

jugadaPtr crearJugada() {
    jugadaPtr j = malloc(sizeof(struct jugadaE));
    if (j == NULL) {
        printf("Error al asignar memoria para la jugada.\n");
        exit(1);
    }

    for (int i = 0; i < 20; i++) {
        j->numeros[i] = rand() % 100;
    }

    return j;
}

void mostrarJugada(jugadaPtr j) {
    printf("\n\t*** NUMEROS JUGADOS ***\n");
    printf("\n\t+++++++++++++++++\n");
    for (int i = 0; i < 4; i++) {
        printf("\t| ");
        for (int k = 0; k < 5; k++) {
            int idx = i * 5 + k;
            printf("%2d ", j->numeros[idx]);
        }
        printf("|\n");
    }
    printf("\t+++++++++++++++++\n");
}

int getAciertos(jugadaPtr j, int *carton) {
    int aciertos = 0;

    for (int i = 0; i < 8; i++) {
        for (int k = 0; k < 20; k++) {
            if (carton[i] == j->numeros[k]) {
                aciertos++;
                break;
            }
        }
    }

    return aciertos;
}

int* getNumerosJugada(jugadaPtr j) {
    return j->numeros;
}

void liberarJugada(jugadaPtr j) {
    free(j);
}
