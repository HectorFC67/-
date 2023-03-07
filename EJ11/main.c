#include "array.h"

int main() {
    // Crear un array de 3 enteros de forma estática y lo inicialice con tres valores
    int enteros[3] = {2, 3, 4};

    // Crear un array de 3 estructuras Point(x, y) de forma dinámica y lo inicialice con tres puntos con coordenadas cualesquiera
    Point* p = (Point*)malloc(3 * sizeof(Point));
    
    p -> x = 1;
    p -> y = 2;
    (*(p+1)).x = 3;
    (*(p+1)).y = 4;
    p[2].x = 5;
    p[2].y = 6;


    // Llamar a la función para escalar los puntos
    escalar(enteros, p, 3);

    // Visualizar el contenido del array de puntos después de su escalado
    printf("Coordenadas despues de escala:\n");
    for (int i = 0; i < 3; i++) {
        printf("Punto %d: (%d, %d)\n", i+1, p[i].x, p[i].y);
    }

    // Liberar la memoria asignada
    free(p);

    return 0;
}