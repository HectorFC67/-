#include "array.h"

void escalar(int* enteros, Point* p, int tamano) {
  for (int i = 0; i < tamano; i++) {
    p[i].x *= enteros[i];
    p[i].y *= enteros[i];
  }
}