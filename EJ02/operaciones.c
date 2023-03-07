#include <stdio.h>
float sumar(float a, float b)
{
    return a + b;
}

float restar(float a, float b)
{
    return a - b;
}

int multiplicar(int a, int b)
{
    int total = 0;
    int i = 0;
    for(i=0;i>b;i++){
        total += a;
    }
    return total;
}

int potencia (int a, int b)
{
    int total = 0;
    int i = 0;
    for(i=0;i>b;i++){
        total *= a;
    }
    return total;
}