#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "jugador.h"
#include "carton.h"  // Necesario para usar cartonPtr

struct jugadorE {
    char nombre[30];
    int dni;
    cartonPtr cartonDeLaPersona; // Cartón asociado
};

// Crear un jugador y asignar cartón manual
jugadorPtr crearJugador() {
    jugadorPtr j = malloc(sizeof(struct jugadorE));
    if (j == NULL) {
        printf("Error al asignar memoria para jugador.\n");
        exit(1);
    }

    printf("Ingrese nombre del jugador: ");
    fflush(stdin);
    gets(j->nombre);

    printf("Ingrese DNI del jugador: ");
    scanf("%d", &j->dni);
    getchar(); // Limpia buffer del ENTER

    j->cartonDeLaPersona = crearCartonPorTeclado();

    return j;
}

// Crear jugador con cartón automático
jugadorPtr crearJugadorCartonAuto() {
    jugadorPtr j = malloc(sizeof(struct jugadorE));
    if (j == NULL) {
        printf("Error al asignar memoria para jugador.\n");
        exit(1);
    }

    char dire[20];

    printf("Ingrese nombre del jugador: ");
    fflush(stdin);
    gets(j->nombre);

    printf("Ingrese DNI del jugador: ");
    scanf("%d", &j->dni);
    getchar();

    printf("Ingrese la direccion de la agencia:\n");
    gets(dire);

    j->cartonDeLaPersona = crearCartonAutomatico(dire);

    return j;
}

// Mostrar datos del jugador y su cartón
void mostrarJugador(jugadorPtr j) {
    printf("\n--- DATOS DEL JUGADOR ---\n");
    printf("Nombre: %s\n", getNombreJugador(j));
    printf("DNI: %d\n", getDniJugador(j));
    mostrarCarton(j->cartonDeLaPersona);
}

// Getters
char* getNombreJugador(jugadorPtr j) {
    return j->nombre;
}

int getDniJugador(jugadorPtr j) {
    return j->dni;
}

cartonPtr getCartonJugador(jugadorPtr j) {
    return j->cartonDeLaPersona;
}

