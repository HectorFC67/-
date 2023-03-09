#include "censo.h"
#include "persona.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

int main(void)
{
	Persona personas[5];
	personas[0].nombre="Hodei"; personas[0].edad=6;
	personas[1].nombre="Anita"; personas[1].edad=41;
	personas[2].nombre="Aitor"; personas[2].edad=12;
	personas[3].nombre="Idoia"; personas[3].edad=31;
	personas[4].nombre="Maite"; personas[4].edad=24;

	imprimirPersona(personas[0]);

	return 0;
}
