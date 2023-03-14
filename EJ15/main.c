#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int id;
    float nota;
}Asignatura;

char mostrarMenu()
{
    printf("\nMenú de opciones\n");
    printf("1. Introducir asignatura\n");    
    printf("2. Mostrar listado\n");
    printf("3. Calcular media\n");
    printf("Pulsar q para salir\n\n");
    printf("Elija una opción: ");

    char linea[10];
    fgets(linea,10,stdin);
    return *linea;// return linea[0]
}

int main(void) {
    Asignatura asignaturas[5];
    char opcion = mostrarMenu();

    switch (opcion) {
        case '1':

        case '2':

        case '3':
            
        case 'q':
            printf("Saliendo...\n");
            exit(0);
        default:
            printf("Opción no válida.\n");
    }

    return 0;
}
