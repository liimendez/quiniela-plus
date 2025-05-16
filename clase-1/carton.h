#ifndef CARTON_H_INCLUDED
#define CARTON_H_INCLUDED

#include "funciones.h"
#include "jugada.h"

// Adelanto jugadorE en vez de incluir jugador.h
struct jugadorE;
typedef struct jugadorE * jugadorPtr;

struct cartonE;
typedef struct cartonE * cartonPtr;

// Crea un carton automatico con números aleatorios no repetidos
cartonPtr crearCartonAutomatico(char dir[15]);

// Crea un carton ingresado por teclado con numeros no repetidos
cartonPtr crearCartonPorTeclado();

// Muestra el carton simple
void mostrarCarton(cartonPtr c);

// Muestra el carton con los aciertos marcados y datos del jugador
void mostrarCartonConAciertos(cartonPtr c, jugadaPtr j, jugadorPtr jugador);

// Guarda los datos del carton en un archivo
void guardarCartonEnArchivo(cartonPtr c, const char *nombreArchivo);

// Getters
char *getFecha(cartonPtr c);
int *getNumerosCarton(cartonPtr c);
char *getDireccion(cartonPtr c);
int getValor(cartonPtr c);

// Setters
void setFecha(cartonPtr c, char *nueva);
void setDireccion(cartonPtr c, char *nuevo);
void setTamCarton(cartonPtr c, int tam[2]);
void setValor(cartonPtr c, int valor);

void ordenarCarton(int carton[], int tam);
int compararEnteros(const void *a, const void *b);

#endif // CARTON_H_INCLUDED
