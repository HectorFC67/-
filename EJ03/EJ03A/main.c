#include <stdio.h>

void echo(void);

int main(void)
{
    echo();
    return 0;
}

void echo(void)
{
    char c;
    do
    {
        c = getchar();
        if (c != '\n')
        {
            printf("El caracter introducido es %c ASCII: %i \n", c, c);
            char upperC= c-32;
            printf("El caracter introducido es %c\n", upperC);
            
        }
    }while (c != 'Q');
}
