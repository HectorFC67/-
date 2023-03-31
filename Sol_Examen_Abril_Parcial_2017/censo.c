#include <stdlib.h>
#include <string.h>
#include "censo.h"

GrupoPersonas crearGrupoPersonas(int num_personas) {
    GrupoPersonas grupo;
    grupo.num_personas = num_personas;
    grupo.personas = malloc(sizeof(Persona) * num_personas);
    grupo.media_edad = 0;
    return grupo;
}

void agregarPersona(GrupoPersonas* grupo, Persona persona) {
    grupo->personas[grupo->num_personas++] = persona;
}

void calcularMediaEdad(GrupoPersonas* grupo) {
    float media = 0;
    for (int i = 0; i < grupo->num_personas; i++) {
        media += grupo->personas[i].edad;
    }
    grupo->media_edad = media / grupo->num_personas;
}

int cuantasPersonas(Persona* personas, int tamanyo, int edad) {
    int contador = 0;
    for (int i = 0; i < tamanyo; i++) {
        if (personas[i].edad < edad) {
            contador++;
        }
    }
    return contador;
}

GrupoPersonas recuperarJovenes(Persona* personas, int tamanyo) {
    GrupoPersonas jovenes = crearGrupoPersonas(0);
    for (int i = 0; i < tamanyo; i++) {
        if (personas[i].edad < 30) {
            agregarPersona(&jovenes, personas[i]);
        }
    }
    calcularMediaEdad(&jovenes);
    return jovenes;
}

Persona* recuperarYogurin(Persona* personas, int tamanyo) {
    Persona* yogurin = &personas[0];
    for (int i = 1; i < tamanyo; i++) {
        if (personas[i].edad < yogurin->edad) {
            yogurin = &personas[i];
        }
    }
    return yogurin;
}

int cuantosNombres(Persona ap[], int tamanyo, char letra)
{
	int cuantos=0;
	int i=0;
	while (i<tamanyo)
	{
		if (letra == ap[i].nombre[0]) cuantos++;
		i++;
	}
	return cuantos;

}

char** listadoNombres(Persona ap[], int tamanyo, char letra)
{
	int cuantos=cuantosNombres(ap,tamanyo,letra);
	char **listado=(char**)malloc(sizeof(char*)*cuantos);
	int i=0;
	int j=0;
	while (i<tamanyo)
	{
		if (letra == ap[i].nombre[0]){
			listado[j]=(char*)malloc(sizeof(char)*(strlen(ap[i].nombre)+1));
			strcpy(listado[j], ap[i].nombre);
			j++;
		}
		i++;
	}
	return listado;
}

