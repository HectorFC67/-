#include <stdio.h>
#include "caracteres.h"
#include <stdbool.h>

int main(void)
{
    printf("%i",isUpperCase('A'));
    printf("%i", isLowerCase('a'));
    isLetter('a');
    isNumber(5);
    isOtherCharacter(35);
    isEnter(10);
    toUpperCase('a');
    toLowerCase('A');
    
    return 0;
}