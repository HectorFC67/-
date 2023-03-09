#include "censo.h"
#include "persona.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>


void imprimirPersona(Persona p)
{
	printf("[Nombre: %s, Edad: %i]\n", p.nombre, p.edad);
}
