#ifndef CENSO_H_
#define CENSO_H_

#include "persona.h"

typedef struct {
    int num_personas;
    Persona* personas;
    float media_edad;
} GrupoPersonas;

GrupoPersonas crearGrupoPersonas(int num_personas);
void agregarPersona(GrupoPersonas* grupo, Persona persona);
void calcularMediaEdad(GrupoPersonas* grupo);

int cuantasPersonas(Persona* personas, int tamanyo, int edad);
GrupoPersonas recuperarJovenes(Persona* personas, int tamanyo);
Persona* recuperarYogurin(Persona* personas, int tamanyo);

int cuantosNombres(Persona[], int, char);
char** listadoNombres(Persona[], int, char);

#endif /* CENSO_H_ */
