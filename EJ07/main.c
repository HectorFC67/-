#include "punto.h"

int main(){
    Punto punto = {6,7};

    escalar(&punto, 7);
    imprimirPunto(punto);
    return 0;
}