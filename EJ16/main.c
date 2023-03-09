#include <stdio.h>
#include <stdlib.h>

void main()
{
    typedef struct 
    {
        int x;
        int y;
    } Point;
    
    // Estatico
    Point arrayE[5][4][3];
    arrayE[2][3][1].x = 3;
    arrayE[2][3][1].y = 4;

    printf("Punto en array estatico (%i, %i)\n", arrayE[2][3][1].x, arrayE[2][3][1].y);
    // Estatico/Dinamico
    Point* arrayED[5][4];

    for (int i = 0; i<5; i++)
    {
        for (int j = 0; j<4; j++)
        {
            arrayED[i][j] = (Point*) malloc((sizeof(Point)) * 3);
        }
    }
    arrayED[2][3][1].x = 3;
    arrayED[2][3][1].y = 4;

    printf("Punto en array estatico/dinamico (%i, %i)\n", arrayED[2][3][1].x, arrayED[2][3][1].y);

    for (int i = 0; i<5; i++)
    {
        for (int j = 0; j<4; j++)
        {
            free(arrayED[i][j]);
        }
    }

    // Dinamico
    Point ***arrayD = (Point***) malloc(sizeof(Point**) * 5);
    for (int i = 0; i < 5; i++) {
        arrayD[i] = (Point**) malloc(sizeof(Point*) * 4);
        for (int j = 0; j < 4; j++) {
            arrayD[i][j] = (Point*) malloc(sizeof(Point) * 3);
        }
    }
    arrayD[2][3][1].x = 3;
    arrayD[2][3][1].y = 4;

    printf("Punto en array estatico/dinamico (%i, %i)\n", arrayD[2][3][1].x, arrayD[2][3][1].y);

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 4; j++) {
            free(arrayED[i][j]);
        }
        free(arrayED[i]);
    }
    free(arrayED);

    return 0;

}

