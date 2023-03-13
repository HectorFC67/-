#include "censo.h"
#include "persona.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

// Función para calcular cuántas personas menores de la edad indicada hay en el array de personas
int cuantasPersonas(Persona ap[], int tamanyo, int edad)
{
    int i = 0;
    int cantidad=0;
    while(i<tamanyo)
    {
        if(ap[i].edad < edad)
        {
           cantidad++;
        }
         i++;
    
    }
    return cantidad;
}
// Función para recuperar un grupo de personas menores de 30 años y su media de edad
GrupoPersonas recuperarJovenes(Persona ap[], int tamanyo)
{
    GrupoPersonas gp;
    int suma = 0;
    int j = 0;
    gp.numeroPersonas = cuantasPersonas(ap, tamanyo, 30);
    gp.arrayPersonas = (Persona*)malloc(sizeof(Persona)*gp.numeroPersonas);
    for (int i = 0; i < tamanyo; i++)
    {
        if(ap[i].edad < 30)
        {
            suma += ap[i].edad;
            gp.arrayPersonas[j] = ap[i];
            j++;
        }
    }
    gp.mediaEdad = suma/gp.numeroPersonas;
    return gp;
}
// Función para calcular cuántas personas menores de la edad indicada hay en el array de personas
Persona* recuperarYogurin(Persona ap[], int tamanyo)
{
    Persona* p = &ap[0];
    int i = 0;
    while(i < tamanyo)
    {
        if(ap[i].edad < p->edad)
        {
            *p = ap[i];
        }
        i++;
    }
    return p;
}
