#include <stdio.h>
#include <stdlib.h>

#ifndef FRACCION_H
#define FRACCION_H

typedef struct {
    int numerador;
    int denominador;
} Fraccion;

Fraccion* crear_fraccion(int numerador, int denominador);
void destruir_fraccion(Fraccion* fraccion);
Fraccion* sumar(Fraccion a, Fraccion b);
Fraccion multiplicar(Fraccion *a, Fraccion *b);


#endif