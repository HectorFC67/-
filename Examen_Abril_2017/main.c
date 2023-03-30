#include "censo.h"
#include "persona.h"
#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE 10

int main(void)
{
    Persona personas[5];
    personas[0].nombre = "Hodei"; personas[0].edad = 6;
    personas[1].nombre = "Anita"; personas[1].edad = 41;
    personas[2].nombre = "Aitor"; personas[2].edad = 12;
    personas[3].nombre = "Idoia"; personas[3].edad = 31;
    personas[4].nombre = "Maite"; personas[4].edad = 24;

    char linea[MAX_LINE];
    int edad;
    printf("Menores de que edad quieres buscar: ");
    fgets(linea, sizeof(linea), stdin);
    sscanf(linea, "%i", &edad);

    int cantidadMenores = cuantasPersonas(personas, 5, edad);
    printf("Hay %d personas menores de %i anyos.\n", cantidadMenores, edad);

	for( int i=0; i<5; i++)
	{
        if(personas[i].edad<edad)
        {
            imprimirPersona(personas[i]);
        }
		
	}

    GrupoPersonas grupoJovenes = recuperarJovenes(personas, 5);
    printf("Hay %d personas menores de 30 anyos con una media de edad de %.2f\n", grupoJovenes.numeroPersonas, grupoJovenes.mediaEdad);

    Persona* yogurin = recuperarYogurin(personas, 5);
    printf("El yogurin es %s con una edad de %d\n", yogurin->nombre, yogurin->edad);

    crearInforme(grupoJovenes, "informe.txt");

    char letra = "";
    printf("Segun que primera letra deseas buscar personas (introduzca en mayusculas): ");
    fgets(linea, sizeof(linea), stdin);
    sscanf(linea, "%c", &letra);
    char** listaNombres = listadoNombres(personas, 5, letra);
    int j = cuantosNombres(personas, 5, letra);
    for(int i = 0; i < j; i++)
    {
        printf("%s\n", listaNombres[i]);
    }

    free(listaNombres);
    return 0;
}

void crearInforme(GrupoPersonas gp, char* fichero)
{
    FILE *archivo;
    archivo = fopen(fichero, "w");
    fprintf(archivo, "CENSO DE JOVENES\n----------------------------\n");
    for (int i = 0; i < gp.numeroPersonas; i++)
    {
        fprintf(archivo, "Nombre: %s, Edad: %i\n", gp.arrayPersonas[i].nombre, gp.arrayPersonas[i].edad);
    }
    fprintf(archivo, "Media: %.2f\n", gp.mediaEdad);
}