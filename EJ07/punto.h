#ifndef PUNTO_H
#define PUNTO_H
typedef struct 
{
    /* data */
    int x;
    int y;
} Punto;

void escalar(Punto* p, int n);

void imprimirPunto(Punto p);

#endif