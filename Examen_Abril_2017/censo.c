#include "censo.h"
#include "persona.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>


int cuantasPersonas(Persona ap[], int tamanyo, int edad)
{
    int i = 0;
    while(ap != '\0')
    {
        if(edad < 18)
        {
            i++;
        }
        ap++;
    }
    return i;
}
GrupoPersonas recuperarJovenes(Persona* ap, int tamanyo)
{

}
Persona* recuperarYogurin(Persona* ap, int tamanyo)
{

}
