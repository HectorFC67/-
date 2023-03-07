#include "caracteres/caracteres.h"
#include <stdio.h>
#include <stdlib.h>

int main (void)
{
    char array1[] = "Hola, mundo!";
    printf("Funcion printf: %s\n", array1);

    printCaracteres(array1);

    char* clonedArray = clonChar(array1);
    printf("Cadena clonada: %s\n", clonedArray);

    free(clonedArray);

    char array2[] = "Estamos en C!";
    char *array = (char*) malloc ((tamanyoCadenaChar(array1)+tamanyoCadenaChar(array2)+1)*sizeof(char));

    copyCadenaCharToChar (array, array1);
    printf("Cadena copiada: %s\n", array);
    mixCadenasChar(array, array2);
    printf("Cadena concatenada: %s\n", array);

    return 0;
}