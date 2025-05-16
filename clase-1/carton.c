#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "carton.h"
#include "jugador.h"

struct cartonE {
    char direccion[20];
    int valor;
    char fecha[20];
    int numeros[8]; // En lugar de tamCarton
};

//----------------------------------------------------
cartonPtr crearCartonAutomatico(char dir[15]) {
    cartonPtr c = malloc(sizeof(struct cartonE));
    setFecha(c,"domingo");
    c->valor = 70;
    strcpy(c->direccion, dir);

    cargarVectorIntAleatorioSinRepetir(c->numeros, 8, 0, 99);

    ordenarCarton(c->numeros, 8);
    guardarCartonEnArchivo(c, "cartones.txt");
    return c;
}

//----------------------------------------------------
cartonPtr crearCartonPorTeclado() {
    cartonPtr c = malloc(sizeof(struct cartonE));
    strcpy(c->fecha, "domingo");
    c->valor = 70;

    printf("Ingrese direccion donde se adquiere el carton: ");
    fflush(stdin);
    gets(c->direccion);

    int i = 0;
    int numero;

    while (i < 8) {
        printf("Ingrese numero en la posicion %d (entre 0 y 99, sin repetir): ", i + 1);

        if (scanf("%d", &numero) != 1) {
            printf("Entrada invalida. Debe ingresar un numero.\n");
            while (getchar() != '\n');
            continue;
        }

        if (numero < 0 || numero > 99) {
            printf("Numero fuera de rango. Intente de nuevo.\n");
        } else if (busquedaVectorInt(c->numeros, i, numero) != -1) {
            printf("Numero repetido. Intente con otro.\n");
        } else {
            c->numeros[i] = numero;
            i++;
        }
    }

    ordenarCarton(c->numeros, 8);
    guardarCartonEnArchivo(c, "cartones.txt");

    return c;
}

//----------------------------------------------------
void mostrarCarton(cartonPtr c) {
    printf("\n\t******* CARTON  *******\n");
    printf("\t*Fecha: %s * Direccion: %s *\n", c->fecha, c->direccion);
    printf("\t*Precio: $%d *\n", c->valor);
    printf("\t+------------------------+\n\t| ");
    for (int i = 0; i < 8; i++) {
        printf("%2d ", c->numeros[i]);
    }
    printf("|\n\t+------------------------+\n");
}

//----------------------------------------------------
void mostrarCartonConAciertos(cartonPtr c, jugadaPtr j, jugadorPtr jugador) {
    printf("\n\t*** CARTON DE %s ***\n", getDireccion(c));
    printf("\tNombre: %s\n", getNombreJugador(jugador));
    printf("\tDNI: %d\n", getDniJugador(jugador));
    printf("\tFecha: %s\n", getFecha(c));
    printf("\tPrecio: $%d\n", getValor(c));
    printf("\n\t+-----------------------------------+\n\t| ");

    int *numerosCarton = getNumerosCarton(c);
    int *numerosJugada = getNumerosJugada(j);

    for (int i = 0; i < 8; i++) {
        int acierto = 0;
        for (int k = 0; k < 20; k++) {
            if (numerosCarton[i] == numerosJugada[k]) {
                acierto = 1;
                break;
            }
        }
        printf(acierto ? "*%2d " : " %2d ", numerosCarton[i]);
    }

    printf("|\n\t+-----------------------------------+\n");
    printf("\t+++ Cantidad de aciertos: %d +++\n", getAciertos(j, numerosCarton));
}

//----------------------------------------------------
void guardarCartonEnArchivo(cartonPtr c, const char *nombreArchivo) {
    FILE *archivo = fopen(nombreArchivo, "a");
    if (archivo == NULL) {
        printf("Error al abrir el archivo.\n");
        return;
    }

    fprintf(archivo, "Direccion: %s\n", c->direccion);
    fprintf(archivo, "Fecha: %s\n", c->fecha);
    fprintf(archivo, "Valor: %d\n", c->valor);
    fprintf(archivo, "Numeros del carton: ");
    for (int i = 0; i < 8; i++) {
        fprintf(archivo, "%d ", c->numeros[i]);
    }
    fprintf(archivo, "\n-----------------------------\n");
    fclose(archivo);
}

//----------------------------------------------------
void ordenarCarton(int carton[], int tam) {
    qsort(carton, tam, sizeof(int), compararEnteros);
}

int compararEnteros(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

//----------------------------------------------------
// Getters
char *getFecha(cartonPtr c) {
    return c->fecha;
}

int *getNumerosCarton(cartonPtr c) {
    return c->numeros;
}

char *getDireccion(cartonPtr c) {
    return c->direccion;
}

int getValor(cartonPtr c) {
    return c->valor;
}

//----------------------------------------------------
// Setters
void setFecha(cartonPtr c, char *nueva) {
    strcpy(c->fecha, nueva);
}

void setDireccion(cartonPtr c, char *nuevo) {
    strcpy(c->direccion, nuevo);
}

void setTamCarton(cartonPtr c, int tam[2]) {
    memcpy(c->numeros, tam, 2 * sizeof(int));
}

void setValor(cartonPtr c, int valor) {
    c->valor = valor;
}
