#include <stdbool.h>
#include <stdio.h>
#include "caracteres.h"

bool isUpperCase(char c)
{
    return (65 <= c && c <= 90);
}

bool isLowerCase(char c)
{
    return (97 <= c && c <= 122);
}

bool isLetter(char c)
{
    return (isUpperCase(c) || isLowerCase(c));
}

bool isNumber(char c)
{
    return (48 <= c && c <= 57);
}

int isOtherCharacter(int c)
{
    return !(isLetter(c) || isNumber(c));
}

int isEnter(int c)
{
    return (10 == c);
}

char toUpperCase(char c)
{
    char letraFinal = ' ';
    if(true == (isUpperCase(c)))
    {
        letraFinal = c;
    }else if(true == (isLowerCase(c))){
        letraFinal = c + 32;
    }
    return letraFinal;
}

int toLowerCase(int c)
{
    int letraFinal = c;
    if(true == (isLowerCase(c)))
    {
        letraFinal = c;
    }else if(true == (isUpperCase(c))){
        letraFinal = c - 32;
    }
    return letraFinal;
}
