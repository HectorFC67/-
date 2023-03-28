#include "punto.h"

#ifndef POLIGONO_H_
#define POLIGONO_H_

typedef struct
{
	Punto* vertices;
    int numVertices;
} Poligono;

void imprimirPoligono(Poligono poli);
float  perimetro(Poligono  poli);
void liberar(Poligono poli);

#endif /* POLIGONO_H_ */