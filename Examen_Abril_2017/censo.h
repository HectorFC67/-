#include "persona.h"

#ifndef CENSO_H
#define CENSO_H

typedef struct
{
	int numeroPersonas;
	Persona* arrayPersonas;
    float mediaEdad;
} GrupoPersonas;

int cuantasPersonas(Persona ap[], int tamanyo, int edad);
GrupoPersonas recuperarJovenes(Persona ap[], int tamanyo);
Persona* recuperarYogurin(Persona ap[], int tamanyo);
int cuantosNombres(Persona ap[], int tamanyo, char letra);
char** listadoNombres(Persona ap[], int tamanyo, char letra);

#endif