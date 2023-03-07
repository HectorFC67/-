#include <stdio.h>
#include "complex.h"
#include <math.h>

void imprimir(Complex c){
    printf("El numero complejo es (%.2f , %.2f)\n", c.real, c.imaginario);
}

Complex sumar(Complex cRI, Complex cAB)
{
    Complex c;
    c.real = cRI.real + cAB.real;
    c.imaginario = cRI.imaginario + cAB.imaginario;
    return c;
}

void restar(Complex* cRI, Complex cAB)
{
    cRI -> real -= cAB.real;
    cRI -> imaginario -= cAB.imaginario;
}

float modulo(Complex c)
{
    return sqrt(c.real*c.real + c.imaginario*c.imaginario);
}