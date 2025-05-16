#include <time.h>
#include <stdlib.h>
#include "funciones.h"

void cargarVectorIntConValor(int vec[], int t, int valor) {
    for (int i = 0; i < t; i++) {
        vec[i] = valor;
    }
}

void cargarVectorIntAleatorioSinRepetir(int vec[], int t, int minimo, int maximo) {
    for (int i = 0; i < t; i++) {
        int numero, busqueda;

        do {
            numero = aleatorioEntre(minimo, maximo);
            busqueda = busquedaVectorInt(vec, i, numero); // busca solo en los primeros i
        } while (busqueda != -1); // Mientras se encuentre, se genera otro numero

        vec[i] = numero;
    }
}

void cargarVectorIntAleatorio(int vec[], int t, int minimo, int maximo) {
    for (int i = 0; i < t; i++) {
        vec[i] = aleatorioEntre(minimo, maximo);
    }
}

int busquedaVectorInt(int vec[], int t, int busco) {
    for (int i = 0; i < t; i++) {
        if (vec[i] == busco) {
            return i;
        }
    }
    return -1;
}

int aleatorioEntre(int minimo, int maximo) {
    return minimo + rand() % (maximo - minimo + 1);
}


