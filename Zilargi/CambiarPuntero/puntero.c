#include <stdio.h>

int main() {
    int *a = 5;
    int b = 10;

    *a = &b;
    
    return 0;
}
