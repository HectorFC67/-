#include <stdio.h>
#include <stdlib.h>

#ifndef ARRAY_H
#define ARRAY_H

typedef struct
{
    int x;
    int y;
} Point;

void escalar(int* enteros, Point* p, int tamano);

#endif ARRAY_H