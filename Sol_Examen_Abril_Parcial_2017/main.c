#include "persona.h"
#include "censo.h"
#include <stdio.h>
#include <stdlib.h>

void crearInforme(GrupoPersonas gp, char *fichero) {
	FILE *f;
	f = fopen(fichero, "w");

	fprintf(f, "CENSO DE JOVENES\n");
	fprintf(f, "----------------\n");

	int i = 0;
	while (i < gp.num_personas) {
		fprintf(f, "[Nombre: %s, Edad: %i]\n", gp.personas[i].nombre,
				gp.personas[i].edad);
		i++;
	}
	fprintf(f, "Media: %.2f\n", gp.media_edad);

	fclose(f);
}

int main(void) {
	Persona personas[5];
	personas[0].nombre = "Hodei";
	personas[0].edad = 6;
	personas[1].nombre = "Anita";
	personas[1].edad = 41;
	personas[2].nombre = "Aitor";
	personas[2].edad = 12;
	personas[3].nombre = "Idoia";
	personas[3].edad = 31;
	personas[4].nombre = "Maite";
	personas[4].edad = 24;

	imprimirPersona(personas[0]);

	int tamanyo = sizeof(personas) / sizeof(Persona);
	int edad = 15;
	int edadMax = 30;

	int num_personas = cuantasPersonas(personas, tamanyo, edad);
	printf("Numero de personas menores de %d anyos: %d\n", edad, num_personas);

	GrupoPersonas gpersonas = recuperarJovenes(personas, tamanyo);

	Persona pers = { "", 0 };
	int tamanyogrupo = gpersonas.num_personas;

	for (int i = 0; i < tamanyogrupo; i++) {
		pers = gpersonas.personas[i];
		imprimirPersona(pers);
	}

	int media = gpersonas.media_edad;
	printf("Media: %i \n", media);

	Persona *yogurin = recuperarYogurin(personas, tamanyo);

	imprimirPersona(*yogurin);

	crearInforme(gpersonas, "informe.txt");
	free(gpersonas.personas);

	char **listado = listadoNombres(personas, 5, 'A');
	int cuantos = cuantosNombres(personas, 5, 'A');
	printf("Nombres con la inicial A: \n");
	int j;
	for (j = 0; j < cuantos; j++) {
		printf("%s\n", listado[j]);
		free(listado[j]);
	}
	free(listado);

	return 0;
}

