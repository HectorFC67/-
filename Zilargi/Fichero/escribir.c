#include <stdio.h>
#include <string.h>

#define MAX_NOMBRE 20

struct persona {
    char nombre[MAX_NOMBRE];
    int edad;
};

int main() {
    FILE *archivo;
    char nombreArchivo[] = "prueba.txt"; // nombre del archivo
    struct persona p = {"Juan", 25};

    // abrimos fichero para escribir en el
    archivo = fopen(nombreArchivo, "w");

    // si no lo detecta
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo.\n");
        return 1;
    }

    // escribir en dos lineas los datos de cada persona
    fprintf(archivo, "Nombre: %s\n", p.nombre);
    fprintf(archivo, "Edad: %d\n", p.edad);

    fclose(archivo);
    return 0;
}
