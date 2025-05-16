#ifndef JUGADOR_H
#define JUGADOR_H

struct cartonE;
typedef struct cartonE* cartonPtr;

typedef struct jugadorE* jugadorPtr;

// Prototipos
jugadorPtr crearJugador();
jugadorPtr crearJugadorCartonAuto();
void mostrarJugador(jugadorPtr j);
char* getNombreJugador(jugadorPtr j);
int getDniJugador(jugadorPtr j);
cartonPtr getCartonJugador(jugadorPtr j);

#endif
