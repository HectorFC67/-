#include "poligono.h"
#include "punto.h"
#include <stdio.h>
#include <stdlib.h>

void imprimirPoligono(Poligono poli)
{
    for(int i = 0; i < poli.numVertices; i++)
    {
        printf("Punto %i(%i, %i)", i, poli.vertices->x, poli.vertices->y);
    }
}

float  perimetro(Poligono  poli)
{
    float distanciaTotal = 0.00;
    poli.vertices = (Punto*) malloc(sizeof(Punto) * poli.numVertices);
    for(int i = 1; i < poli.numVertices; i++)
    {
        if(i = poli.numVertices-1)
        {
            distanciaTotal += distancia(poli.vertices[i], poli.vertices[0]); 
        }else{
            distanciaTotal += distancia(poli.vertices[i-1], poli.vertices[i]); 
        }
    }
}

void liberar(Poligono poli)
{       
    free(poli.vertices);
    poli.vertices = NULL;
}