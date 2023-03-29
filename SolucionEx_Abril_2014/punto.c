/*
 * Punto.c
 *
 *  Created on: 22/04/2014
 *      Author: perallos
 */

#include "punto.h"
#include <stdio.h>


void imprimirPunto(Punto p)
{
	printf("(%i, %i)\n", p.x, p.y);
}

float distancia(Punto p1, Punto p2)
{
	return sqrt(((p2.x - p1.x)*(p2.x - p1.x)) + ((p2.y - p1.y)*(p2.y - p1.y)));
}

void trasladarXY(Punto *p1, Punto *p2, int x, int y)
{
	p1->x = p1->x + x;
	p1->y = p1->y + y;
	p2->x = p2->x + x;
	p2->y = p2->y + y;
}

