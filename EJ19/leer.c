#include <stdio.h>

int main(void)
{
    FILE *archivo;
    char nombreArchivo[] = "contador.txt";
    archivo = fopen(nombreArchivo, "r");

    char caracterL;

    int num_lineas = 0;
    while(caracterL != EOF)
    {
        if(caracterL == '\n')
        {
            num_lineas++;
        }
        caracterL = (char) fgetc(archivo);
        printf("%c", caracterL);
    }
    fclose(archivo);
    printf("El fichero contiene %i lienas", num_lineas);

    return 0;
}