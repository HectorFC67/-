#include "complex.h"

int main(){

    Complex complejoA = {2.5,4.5};
    Complex complejoB = {5.2,6.7};

    imprimir(complejoA);
    sumar(complejoA, complejoB);
    restar(&complejoA, complejoB);
    imprimir(complejoA);

    return 0;
}