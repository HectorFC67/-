#ifndef COMPLEX_H
#define COMPLEX_H
typedef struct {
    float real;
    float imaginario;
}Complex;

void imprimir(Complex c);

Complex sumar(Complex cRI, Complex cAB);

void restar(Complex* cRI, Complex cAB);

float modulo(Complex c);

#endif