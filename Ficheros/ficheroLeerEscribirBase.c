#include <stdio.h>
#include <stdlib.h>

#define MAX_PERSONAS 100

typedef struct {
    int id;
    char nombre[50];
    float dinero;
} Persona;

int main() {
    FILE *fichero;
    Persona personas[MAX_PERSONAS];
    int num_personas = 0;

    // Creamos un archivo llamado "personas.txt" en modo escritura
    fichero = fopen("personas.txt", "w");
    if (fichero == NULL) {
        printf("Error al crear el archivo\n");
        return 1;
    }

    // Escribimos los datos de las personas en el archivo
    fprintf(fichero, "ID\tNombre\tDinero\n");
    fprintf(fichero, "-----------------------\n");
    fprintf(fichero, "1\tJuan\t100.50\n");
    fprintf(fichero, "2\tPedro\t50.20\n");
    fprintf(fichero, "3\tMaria\t75.80\n");

    // Cerramos el archivo
    fclose(fichero);

    // Abrimos el archivo en modo lectura
    fichero = fopen("personas.txt", "r");
    if (fichero == NULL) {
        printf("Error al abrir el archivo\n");
        return 1;
    }

    // Leemos los datos de las personas del archivo y los almacenamos en un array de estructuras Persona
    char buffer[100];
    fgets(buffer, 100, fichero); // Leemos la primera línea (encabezado)
    fgets(buffer, 100, fichero); // Leemos la segunda línea (separador)
    while (fgets(buffer, 100, fichero)) {
        sscanf(buffer, "%d\t%s\t%f", &personas[num_personas].id, personas[num_personas].nombre, &personas[num_personas].dinero);
        num_personas++;
    }

    // Imprimimos los datos de las personas por consola
    printf("ID\tNombre\tDinero\n");
    printf("-----------------------\n");
    for (int i = 0; i < num_personas; i++) {
        printf("%i\t%s\t%.2f\n", personas[i].id, personas[i].nombre, personas[i].dinero);
    }

    // Cerramos el archivo
    fclose(fichero);

    return 0;
}
