/*
 * main.c
 *
 *  Created on: 22/04/2014
 *      Author: perallos
 */

#include "punto.h"
#include "poligono.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE 5

void leerPoligono(Poligono *pol)
{
	char str[MAX_LINE];
	printf("NUMERO VERTICES: ");
	fflush(stdout);
	fgets(str, MAX_LINE, stdin);
	int numVertices;
	sscanf(str, "%i", &numVertices);

	inicializarPoligono(pol, numVertices);

	int i;
	for(i=0; i<numVertices;i++)
	{
		printf("VERTICE %i (X): ", i+1);
		fflush(stdout);
		fgets(str, MAX_LINE, stdin);
		int x;
		sscanf(str, "%i", &x);
		printf("VERTICE %i (Y): ", i+1);
		fflush(stdout);
		fgets(str, MAX_LINE, stdin);
		int y;
		sscanf(str, "%i", &y);

		pol->vertices[i].x = x;
		pol->vertices[i].y = y;
	}
}

int main(int argc, char* argv[])
{
	Punto p1 = {1,2};
	imprimirPunto(p1);

	// PARTE 1 (0,5p)
	Punto p2 = {1, 2};
	Punto p3;
	p3.x = 3;
	p3.y = 4;
	/*
	 * OPCIONAL: Pasando las coordenadas de los puntos como parametros
	 * sscanf(argv[1], "%i", &p2.x);
	 * sscanf(argv[2], "%i", &p2.y);
	 * sscanf(argv[3], "%i", &p3.x);
	 * sscanf(argv[4], "%i", &p3.y);
	 */
	imprimirPunto(p2);
	imprimirPunto(p3);
	printf("Distancia = %f\n", distancia(p2, p3));
	trasladarXY(&p2, &p3, 5, 6);
	printf("Después de trasladar los puntos...\n");
	printf("Distancia = %f\n", distancia(p2, p3));
	imprimirPunto(p2);
	imprimirPunto(p3);

	// PARTE 2 (0,75p)
	Poligono pol;
	/**
	 *	pol.numVertices = 4;
	 *	pol.vertices = (Punto*)malloc(sizeof(Punto)*pol.numVertices);
	 *	pol.vertices[0].x = 0;
	 *	pol.vertices[0].y = 0;
	 *	pol.vertices[1].x = 1;
	 *	pol.vertices[1].y = 1;
	 *	pol.vertices[2].x = 2;
	 *	pol.vertices[2].y = 2;
	 *	pol.vertices[3].x = 3;
	 *	pol.vertices[3].y = 3;
	 */

	leerPoligono(&pol);
	imprimirPoligono(pol);
	printf("Perimetro = %f\n", perimetro(pol));


	// PARTE 3 (0,75p)
	Punto p4 = {4, 4};
	anadirVertice(&pol, p4);
	printf("Después de añadir un vertice...\n");
	imprimirPoligono(pol);
	Poligono *pol2 = (Poligono*)malloc(sizeof(Poligono));
	copiarPoligono(pol2, pol);
	printf("Después de copiar el poligono...\n");
	imprimirPoligono(*pol2);

	liberar(&pol);
	liberar(pol2);
	return 0;
}
