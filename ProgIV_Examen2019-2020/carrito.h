#include "producto.h"

#ifndef CARRITO_H
#define CARRITO_H

typedef struct
{
	Producto* producto;
	int cant;
} Compra;

typedef struct
{
	Compra* compras;
	float importe;
} Carrito;

void modificarCompra(Compra* c, int cant);
void imprimirCompra (Compra c);
void crearCarrito(Carrito* c, Producto** productos, int* cantidades, int tamanyo);
void imprimirCarrito(Carrito c);
void devolverCarrito(Carrito c);
void leerProductos(Producto* productos[], char* fichero);

#endif