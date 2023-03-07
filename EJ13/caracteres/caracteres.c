#include "caracteres.h"
#include <stdio.h>
#include <stdlib.h>

void printCaracteres(char *array)
{
    int i = 0;
    while(array[i] != '\0')
    {
        printf("%c", array[i]);
        i++;
    }
}
int tamanyoCadenaChar(char *array)
{
    int i = 0;
    while(*array != '\0')
    {
        i++;
        array++;
    }
    return i;
}
char* clonChar(char *array)
{
    int size = tamanyoCadenaChar(array);

    // char newArray[size+1]; si lo definimos asi en memoria estatica, al salir se pierde esta variable
    char* newArray = malloc (size*(sizeof(char)));
    int i = 0;

    while(array[i] != '\0')
    {
        newArray[i] = array [i];
        i++;
    }
    newArray[i] = '\0';
    return newArray;
}
char mixCadenasChar(char *array1, char *array2)
{
    while (*array1 != '\0')
    {
        array1++;
    }
    copyCadenaCharToChar(array1, array2);
}
void copyCadenaCharToChar(char *array1, char *array2)
{
    int i = 0;
    while(array2[i] != '\0'){
        array1[i] = array2[i];
        i++;
    }
    array1[i] = '\0';
}