#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMPLEADOS 100
#define MAX_SECTORES 10

typedef struct {
    int id;
    char nombre[50];
    float sueldo;
} Empleado;

typedef struct {
    int id;
    Empleado *empleados;
    int num_empleados;
} Sector;

int main() {
    FILE *fichero;
    Sector sectores[MAX_SECTORES];
    int num_sectores = 0;

    // Creamos un array de empleados de forma dinámica
    Empleado *empleados = (Empleado *) malloc(MAX_EMPLEADOS * sizeof(Empleado));
    int num_empleados = 0;

    // Creamos los empleados
    empleados[num_empleados].id = 1;
    strcpy(empleados[num_empleados].nombre, "Juan");
    empleados[num_empleados].sueldo = 2000.0;
    num_empleados++;

    empleados[num_empleados].id = 2;
    strcpy(empleados[num_empleados].nombre, "Pedro");
    empleados[num_empleados].sueldo = 1500.0;
    num_empleados++;

    empleados[num_empleados].id = 3;
    strcpy(empleados[num_empleados].nombre, "Maria");
    empleados[num_empleados].sueldo = 3000.0;
    num_empleados++;

    // Creamos un sector de forma dinámica y asignamos los empleados
    Sector *sector = (Sector *) malloc(sizeof(Sector));
    sector->id = 1;
    sector->empleados = empleados;
    sector->num_empleados = num_empleados;

    // Añadimos el sector al array de sectores
    sectores[num_sectores] = *sector;
    num_sectores++;

    // Creamos un archivo llamado "miembros.txt" en modo escritura
    fichero = fopen("miembros.txt", "w");
    if (fichero == NULL) {
        printf("Error al crear el archivo\n");
        return 1;
    }

    // Escribimos los datos de los empleados por sector en el archivo
    for (int i = 0; i < num_sectores; i++) {
        fprintf(fichero, "Sector %d:\n", sectores[i].id);
        fprintf(fichero, "ID\tNombre\tSueldo\n");
        fprintf(fichero, "-----------------------\n");
        for (int j = 0; j < sectores[i].num_empleados; j++) {
            fprintf(fichero, "%d\t%s\t%.2f\n", sectores[i].empleados[j].id, sectores[i].empleados[j].nombre, sectores[i].empleados[j].sueldo);
        }
        fprintf(fichero, "\n");
    }

    // Cerramos el archivo
    fclose(fichero);

    // Liberamos la memoria asignada dinámicamente
    free(empleados);
    free(sector);

    return 0;
}
