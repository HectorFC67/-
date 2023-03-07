#include <stdio.h>

#define nombre_max 30

typedef struct {
  char nombre[nombre_max];
  int edad;
} Estudiante;

void datosEst() {
    Estudiante objEst;
    printf("Introduce un nombre para el estudiante: ");
    fgets(objEst.nombre, nombre_max, stdin);

    printf("Introduce la edad del estudiante: ");
    scanf("%d", &objEst.edad);

    printf("El nombre del estudiante es %sTiene %d anyos", objEst.nombre, objEst.edad);
}

int main() {
    datosEst();
    return 0;
}
