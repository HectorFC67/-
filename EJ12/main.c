#include <stdio.h>
#include "fraccion.h"

int main() {
    // 1) Declarar una variable de tipo entero
    int entero = 5;
    printf("%i\n", entero);

    // 2) Definir un tipo de datos Fracción (numerador y denominador) y una variable de este tipo
    Fraccion fraccion1 = {3, 4};
    printf("%i/%i\n", fraccion1.numerador, fraccion1.denominador);

    // 3) Declarar un puntero a un entero
    int* ptr_entero;

    // 4) Declarar un puntero a una fracción
    Fraccion* ptr_fraccion;

    // 5) Hacer que el puntero declarado en (3) apunte al entero declarado en (1)
    ptr_entero = &entero;
    printf("%i\n", *ptr_entero);

    // 6) Apuntar con el puntero de (4) a una fracción creada en memoria dinámica
    ptr_fraccion = crear_fraccion(3, 4);
    printf("%i/%i\n", ptr_fraccion->numerador, ptr_fraccion->denominador);

    // 7) Modificar el valor de la fracción (por ejemplo con 3/4) creada en (2)
    fraccion1.numerador = 1;
    fraccion1.denominador = 2;
    printf("%i/%i\n", fraccion1.numerador, fraccion1.denominador);

    // 8) Modificar el valor de la fracción (por ejemplo con 3/4) creada en (6)
    ptr_fraccion->numerador = 2;
    ptr_fraccion->denominador = 3;
    printf("%i/%i\n", ptr_fraccion->numerador, ptr_fraccion->denominador);

    // 9) Modificar el valor del entero usando el puntero declarado en (3)
    *ptr_entero = 10;
    printf("%i\n", *ptr_entero);

    // 10) Supongamos una función declarada como sumar(Fraccion a, Fraccion b).
    // Llamarla usando las dos fracciones declaradas en (2) y (6)
    Fraccion resultado = *sumar(fraccion1, *ptr_fraccion);
    printf("El resultado de la suma es: %d/%d\n", resultado.numerador, resultado.denominador);

    // 11) ¿Y si la funcione fuese multiplicar(Fraccion *a, Fraccion *b)? Invocarla.
    Fraccion* ptr_fraccion1;
    Fraccion* ptr_fraccion2;
    ptr_fraccion1 = crear_fraccion(3, 4);
    ptr_fraccion2 = crear_fraccion(2, 3);
    Fraccion resultado1 = multiplicar(ptr_fraccion1, ptr_fraccion2);
    printf("El resultado de la multiplicacion es: %d/%d\n", resultado1.numerador, resultado1.denominador);
    
    // 12) Declarar un array de 5 enteros en memoria estática.
    int enteros_array[5];
    enteros_array[0] = 0;
    enteros_array[1] = 1;
    enteros_array[2] = 2;
    enteros_array[3] = 3;
    enteros_array [4] = 4;
    for (int i = 0; i < 5; i++) {
        printf("%d\n", enteros_array[i]);
    }

    // 13) Declarar un array de 5 fracciones en memoria dinámica.

    Fraccion *fracciones = malloc(5 * sizeof(Fraccion));

    fracciones[0].numerador = 1;
    fracciones[0].denominador = 2;

    fracciones[1].numerador = 3;
    fracciones[1].denominador = 4;

    fracciones[2].numerador = 5;
    fracciones[2].denominador = 6;

    fracciones[3].numerador = 7;
    fracciones[3].denominador = 8;

    fracciones[4].numerador = 9;
    fracciones[4].denominador = 10;

    for (int i = 0; i < 5; i++) {
        printf("%d/%d\n", fracciones[i].numerador, fracciones[i].denominador);
    }

    // 14) Modifica la posición 3 de ambos arrays.
    enteros_array[2] = 42;

    fracciones[2].numerador = 23;
    fracciones[2].denominador = 43;

    for (int i = 0; i < 5; i++) {
        printf("%d\n", enteros_array[i]);
    }

    for (int i = 0; i < 5; i++) {
        printf("%d/%d\n", fracciones[i].numerador, fracciones[i].denominador);
    }

    // 15) Declarar un puntero a enteros y otro a fracciones y usarlos para manejar los array de (12) y (13). 
    // Modificar con ellos la posición 2 de los array.

    // Declaración de los punteros
    int* ptr_enteros = enteros_array;
    Fraccion* ptr_fracciones = fracciones;

    ptr_enteros[1] = 10;

    ptr_fracciones[1].numerador = 11;
    ptr_fracciones[1].denominador = 12;
    
    // 16) Imprimir por pantalla la dirección de memoria del entero que está en la posición 3 del array de enteros.

    printf("Dirección de memoria del entero en la posición 3: %p\n", &enteros_array[2]);

    // Liberar memoria dinámica
    destruir_fraccion(ptr_fraccion);

    return 0;
}