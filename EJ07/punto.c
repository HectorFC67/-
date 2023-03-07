#include <stdio.h>
#include "punto.h"
 
void escalar(Punto* p, int n)
{
    (*p).x += n;
    p->y += n;
}

void imprimirPunto(Punto p)
{
    printf("Las coordenadas son (%i , %i)", p.x, p.y);
}