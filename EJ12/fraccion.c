#include <stdlib.h>
#include "fraccion.h"

Fraccion* crear_fraccion(int numerador, int denominador) {
    Fraccion* fraccion = malloc(sizeof(Fraccion));
    fraccion->numerador = numerador;
    fraccion->denominador = denominador;
    return fraccion;
}

void destruir_fraccion(Fraccion* fraccion) {
    free(fraccion);
}

Fraccion* sumar(Fraccion a, Fraccion b) {
    Fraccion* resultado = malloc(sizeof(Fraccion));
    resultado->numerador = a.numerador * b.denominador + b.numerador * a.denominador;
    resultado->denominador = a.denominador * b.denominador;
    return resultado;
}

Fraccion multiplicar(Fraccion *a, Fraccion *b){
    Fraccion resultado;// = (Fraccion*)malloc(sizeof(Fraccion));
    resultado.numerador = a->numerador * b->numerador;
    resultado.denominador = a->denominador * b->denominador;
    return resultado;
}