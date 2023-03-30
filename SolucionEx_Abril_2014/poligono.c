/*
 * poligono.c
 *
 *  Created on: 22/04/2014
 *      Author: perallos
 */

#include "poligono.h"
#include "punto.h"
#include <stdio.h>
#include <stdlib.h>

void inicializarPoligono(Poligono *p, int numVertices)
{
	p->numVertices = numVertices;
	p->vertices = (Punto*)malloc(sizeof(Punto)*p->numVertices);
}

void imprimirPoligono(Poligono p)
{
	int i;
	for(i=0; i<p.numVertices;i++)
	{
		printf("Vertice %i = ",i);
		imprimirPunto(p.vertices[i]);
	}
}
float perimetro (Poligono p)
{
	int i;
	float perimetro = 0;
	for(i=0; i<p.numVertices;i++)
	{
		if (i == (p.numVertices -1))
		{
			perimetro = perimetro + distancia(p.vertices[i], p.vertices[0]);
		}else{
			perimetro = perimetro + distancia(p.vertices[i], p.vertices[i+1]);
		}
	}
	return perimetro;

}
void liberar(Poligono *p)
{
	free (p->vertices);
}

void anadirVertice(Poligono *pol, Punto p)
{
	Punto *verticesViejos = pol->vertices;

	pol->numVertices++;
	pol->vertices = (Punto*)malloc(sizeof(Punto) * pol->numVertices);

	int i;
	for(i=0; i<pol->numVertices-1;i++)
	{
		pol->vertices[i] = verticesViejos[i];
	}
	pol->vertices[pol->numVertices-1] = p;

	free(verticesViejos);
}

void copiarPoligono(Poligono *pol1, Poligono pol2)
{
	inicializarPoligono(pol1, pol2.numVertices);
	int i;
	for(i=0; i<pol1->numVertices;i++)
	{
		pol1->vertices[i] = pol2.vertices[i];
	}
}
