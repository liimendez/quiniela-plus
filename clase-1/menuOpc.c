#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "menuOpc.h"
#include "carton.h"
#include "jugador.h"
#include "jugada.h"

void pausarPantalla() {
    printf("\nPresione ENTER para continuar...");
    while (getchar() != '\n');
}

void simularHastaGanar(cartonPtr carton) {
    int intentos = 0;
    int aciertos = 0;
    jugadaPtr jugada;

    do {
        jugada = crearJugada();
        aciertos = getAciertos(jugada, getNumerosCarton(carton));
        liberarJugada(jugada);
        intentos++;
    } while (aciertos < 8);

    printf("¡Ganaste con 8 aciertos luego de %d jugadas!\n", intentos);
}

void menuDeOpciones() {
    int opcion;
    jugadorPtr jugador = NULL;
    jugadaPtr jugada = NULL;
    char respuesta;

    srand(time(NULL));

    do {
        system("cls");

        premiosPosibles();
        getchar();
        system("cls");

        printf("=== MENU DE OPCIONES ===\n\n");
        printf("1. Comprar carton manual\n");
        printf("2. Comprar carton automatico\n");
        printf("3. Mostrar jugador con carton\n");
        printf("4. Generar jugada y mostrarla\n");
        printf("5. Mostrar carton con aciertos y jugada\n");
        printf("6. Mostrar premio ganado\n");
        printf("7. Simular cuantas jugadas necesito para ganar con 8 aciertos\n");
        printf("0. Salir\n\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);
        getchar(); // Limpia el ENTER

        system("cls");

        switch (opcion) {
            case 1:
            case 2:
                if (jugador != NULL) {
                    printf("Ya hay un jugador con carton. Desea reemplazarlo? (s/n): ");
                    respuesta = getchar();
                    getchar();
                    if (respuesta != 's' && respuesta != 'S') {
                        printf("Operacion cancelada.\n");
                        break;
                    }
                    free(jugador);
                    jugador = NULL;
                }
                jugador = (opcion == 1) ? crearJugador() : crearJugadorCartonAuto();
                printf("Carton %s asignado correctamente.\n", (opcion == 1) ? "manual" : "automatico");
                break;

            case 3:
                if (jugador != NULL) {
                    mostrarJugador(jugador);
                } else {
                    printf("Debe comprar un carton primero.\n");
                }
                break;

            case 4:
                if (jugada != NULL) {
                    liberarJugada(jugada);
                }
                jugada = crearJugada();
                printf("Jugada generada:\n");
                mostrarJugada(jugada);
                break;

            case 5:
                if (jugador != NULL && jugada != NULL) {
                    printf("Numeros jugados:\n");
                    mostrarJugada(jugada);
                    printf("\nCarton con aciertos:\n");
                    mostrarCartonConAciertos(getCartonJugador(jugador), jugada, jugador);
                } else {
                    printf("Debe tener un carton y una jugada generada.\n");
                }
                break;

            case 6:
                if (jugador != NULL && jugada != NULL) {
                    int aciertos = getAciertos(jugada, getNumerosCarton(getCartonJugador(jugador)));

                    printf("\n *** cantidad de aciertos: %d ***\n",aciertos);

                    printf("\nResultado:\n");
                    switch (aciertos) {
                        case 8: printf("Ganaste $11000000\n"); break;
                        case 7: printf("Ganaste $20000\n"); break;
                        case 6: printf("Ganaste $500\n"); break;
                        case 5: printf("Ganaste $50\n"); break;
                        default: printf("No ganaste ningun premio.\n"); break;
                    }
                } else {
                    printf("Debe generar una jugada y tener un carton.\n");
                }
                break;

            case 7:
                if (jugador != NULL) {
                    simularHastaGanar(getCartonJugador(jugador));
                } else {
                    printf("Debe tener un carton primero.\n");
                }
                break;

            case 0:
                printf("Saliendo del sistema...\n");
                break;

            default:
                printf("Opcion invalida. Intente nuevamente.\n");
                break;
        }

        if (opcion != 0) {
            pausarPantalla();
        }

    } while (opcion != 0);

    if (jugador != NULL) free(jugador);
    if (jugada != NULL) liberarJugada(jugada);
}


void premiosPosibles(){

printf("\n\t PREMIOS EN JUEGO !!! ");
printf("\n\t con 5 aciertos 50$ ");
printf("\n\t con 6 aciertos 500$ ");
printf("\n\t con 7 aciertos 20.000$ ");
printf("\n\t con 8 aciertos 11.000.000$");
printf("\n\t mucha suerteeeee!!!\n\n");

};














