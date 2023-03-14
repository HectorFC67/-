#include <stdio.h>
#include <string.h>

#define PARAM_CONFIG_FILE "-configFile"

int main(int argc, char*argv[])
{
    printf("El numero de argumentos es: %i\n", argc);
    for (int i = 0; i<argc; i++)
    {
        printf("\t%s\n",argv[i]);
    }
    if(strcmp(argv[1], PARAM_CONFIG_FILE)==0)
    {
        printf("Fichero de configuracion establecido.\n");
    }


    return 0;
}