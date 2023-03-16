#include <stdio.h>

#define MAX_NUM 10

int main(void)
{
    FILE *archivo;
    char nombreArchivo[] = "contador.txt";
    archivo = fopen(nombreArchivo, "w");

    fprintf(archivo, "Escribiendo %i numeros: \n", MAX_NUM);
    for(int i = 0; i < MAX_NUM; i++)
    {
        fprintf(archivo, "%i\n", i);
    }

    fclose(archivo);
    return 0;
}