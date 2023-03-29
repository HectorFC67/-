/*
 * main.c
 *
 *  Created on: 22/04/2014
 *      Author: perallos
 */

#include "punto.h"
#include "poligono.h"
#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE 10

int main(void)
{
	Punto p1 = {1,2};
	Punto p2 = {3, 4};
	imprimirPunto(p1);

	printf("La distancia entre ambos es puntos es %.2f\n", distancia(p1, p2));

	trasladarXY(&p1, &p2, 6, 7);
	printf("Los puntos se han desplazado 6 en el eje X y 7 en el eje Y\n");
	imprimirPunto(p1);
	imprimirPunto(p2);

	char nums[MAX_LINE];
    int numeroVertices = 0;
    printf("Cuantos vertices quieres que tenga el Poligono: ");
    fgets(nums,MAX_LINE, stdin);
    sscanf(nums, "%i", &numeroVertices);
    Punto *vertices = (Punto*) malloc(sizeof(Punto) * numeroVertices);

    for(int i = 0; i < (numeroVertices); i++)
    {
        int x;
        int y;
        printf("Coordenada X del Punnto %i: ", i+1);
        fgets(nums, MAX_LINE, stdin);
        sscanf(nums, "%i", &x);
        printf("Coordenada Y del Punnto %i: ", i+1);
        fgets(nums, MAX_LINE, stdin);
        sscanf(nums, "%i", &y);
        Punto punto = {x,y};
        vertices[i] = punto;
    }

    Poligono poligono = {numeroVertices, vertices};
    imprimirPoligono(poligono);
    perimetro(poligono);

    liberar(poligono);

	

	return 0;
}
