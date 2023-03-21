#include <stdio.h>
#include <stdlib.h>
#include "string.h"

#define MAX_LINE 10
#define MAX_LENGTH 10

typedef struct{
    int id;
    char* nombre;
    float nota;
}Asignatura;

char mostrarMenu()
{
    printf("\nMenu de opciones\n");
    printf("1. Introducir asignatura\n");    
    printf("2. Mostrar listado\n");
    printf("3. Calcular media\n");
    printf("Pulsar 'q' para salir\n\n");
    printf("Elija una opcion: ");

    char linea[10];
    fgets(linea,10,stdin);
    return *linea;// return linea[0]
}

void introducirAsig(Asignatura *asignatura) {
    char *c;
    int id;
    float nota;
    printf("\nIntroducir asignatura:\n");
    printf("ID (introduce entero): ");
    fgets(c, MAX_LINE, stdin);
    sscanf(c, "%i", &id);

    printf("Nombre de la asignatura (introduce string con menos de 10 caracteres): ");
    fgets(c, MAX_LINE, stdin);
    char *str_aux = (char*) malloc(MAX_LENGTH*sizeof(char));
    sscanf(c, "%s", str_aux);
    int tamanyo = strlen(str_aux);
    asignatura->nombre = (char*)malloc((tamanyo+1)*sizeof(char));
    strcpy(asignatura->nombre, str_aux);
    free(str_aux);

    printf("Nota (introduce float con dos decimales maximo): ");
    fgets(c, MAX_LINE, stdin);
    sscanf(c, "%.2f", &nota);
    printf("Asignatura introducida con exito.\n");
    asignatura->id = id;
    asignatura->nota = nota;
}


void mostrarListado(Asignatura asignaturas[], int numeroAsig) {
    printf("\nListado de asignaturas:\n");
    for(int i = 0; i < numeroAsig; i++) {
        printf("ID: %i Nombre: %s Nota: %.2f\n", asignaturas[i].id, asignaturas[i].nombre, asignaturas[i].nota);
    }
}

void calcularMedia(Asignatura asignaturas[], int numeroAsig) {
    float media = 0;
    for(int i = 0; i < numeroAsig; i++) {
        media += asignaturas[i].nota;
    }
    media /= numeroAsig;
    printf("\nLa media de las asignaturas es: %.2f\n", media);
}

void salir()
{
    printf("Saliendo...");
    exit(0);
}

void liberarMemoria(Asignatura *as, int numAsig)
{
    for(int i = 0; i < numAsig; i++)
    {
        free(as[i].nombre);
    }
}

int main(void) {
    Asignatura asignaturas[5];
    char opcion;
    int i = 0;
    while(1) {
        opcion = mostrarMenu();

        switch (opcion) {
            case '1':
                if(i<5)
                 {
                    introducirAsig(&asignaturas[i]);
                    i++;
                 }else
                 {
                    printf("Has anyadido el numero maximo de asignaturas");
                 }
                
                break;
            case '2':
                mostrarListado(asignaturas, i);
                break;
            case '3':
                calcularMedia(asignaturas, i);
                break;
            case 'q':
                salir();
            default:
                printf("Opción no válida.\n");
        }
    }
    liberarMemoria(asignaturas, i);
    return 0;
}

