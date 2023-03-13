#include <stdio.h>
#include <string.h>

#define MAX_NOMBRE 20

struct persona {
    char nombre[MAX_NOMBRE];
    int edad;
};

int main() {
    FILE *archivo;
    char nombreArchivo[] = "prueba.txt";
    struct persona p;

    archivo = fopen(nombreArchivo, "r");

    if (archivo == NULL) {
        printf("No se pudo abrir el archivo.\n");
        return 1;
    }

    fscanf(archivo, "Nombre: %s\n", p.nombre);
    fscanf(archivo, "Edad: %d\n", &p.edad);

    printf("Nombre: %s\n", p.nombre);
    printf("Edad: %d\n", p.edad);

    fclose(archivo);
    return 0;
}
