#ifndef PRODUCTO_H_
#define PRODUCTO_H_

typedef struct
{
	int ref;
	char nombre[20];
	float precio;
} Producto;

void imprimirProducto(Producto p);


#endif /* PRODUCTO_H_ */
