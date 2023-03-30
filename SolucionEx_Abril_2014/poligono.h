/*
 * poligono.h
 *
 *  Created on: 22/04/2014
 *      Author: perallos
 */

#include "punto.h"

#ifndef POLIGONO_H_
#define POLIGONO_H_

typedef struct
{
	int numVertices;
	Punto *vertices;
} Poligono;

void inicializarPoligono(Poligono *p, int numVertices);
void imprimirPoligono(Poligono p);
float perimetro (Poligono p);
void anadirVertice(Poligono *pol, Punto p);
void copiarPoligono(Poligono *pol1, Poligono pol2);
void liberar(Poligono *p);

#endif /* POLIGONO_H_ */
