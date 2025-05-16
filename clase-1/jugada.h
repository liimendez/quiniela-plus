#ifndef JUGADA_H_INCLUDED
#define JUGADA_H_INCLUDED

struct jugadaE;
typedef struct jugadaE *jugadaPtr;

// Crea una jugada con 20 numeros aleatorios entre 0 y 99 (pueden repetirse)
jugadaPtr crearJugada();

// Muestra la jugada
void mostrarJugada(jugadaPtr j);

// Devuelve la cantidad de aciertos entre una jugada y un cartón (de 8 numeros)
int getAciertos(jugadaPtr j, int *carton);

// Getter para el arreglo de la jugada
int* getNumerosJugada(jugadaPtr j);

// Libera memoria
void liberarJugada(jugadaPtr j);

#endif // JUGADA_H_INCLUDED
