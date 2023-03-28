/*
 * main.c
 *
 *  Created on: 22/04/2014
 *      Author: perallos
 */

#include "punto.h"
#include <stdio.h>
#include <stdlib.h>

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
	printf("Inserta la cantidad de vertices que va a tener el poligono: ");
	

	return 0;
}
