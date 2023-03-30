/*
 * Punto.h
 *
 *  Created on: 22/04/2014
 *      Author: perallos
 */

#ifndef PUNTO_H_
#define PUNTO_H_

typedef struct
{
	int x,y;
} Punto;

void imprimirPunto(Punto p);
float distancia(Punto p1, Punto p2);
void trasladarXY(Punto *p1, Punto *p2, int x, int y);

#endif /* PUNTO_H_ */
