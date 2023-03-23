#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "carrito.h"

void modificarCompra(Compra* c, int cant)
{
    c->cant=cant;
}

void imprimirCompra (Compra c)
{
    printf("Ref.%i  %s \t %.2f x %i kg/ud\n", c.producto->ref, c.producto->nombre, c.producto->precio, c.cant);
}

void crearCarrito(Carrito* c, Producto** productos, int* cantidades, int tamanyo)
{
    float importeTotal;
    c->compras=(Compra*) malloc(tamanyo*(sizeof(Compra)));
    for(int i=0; i<5; i++)
    {
        c->compras[i].producto = productos[i];
        c->compras[i].cant = cantidades[i];
        importeTotal += productos[i]->precio * c->compras[i].cant;
    }
    c->importe = importeTotal;
}

void imprimirCarrito(Carrito c)
{
    printf("TICKET\n");
    printf("------\n");
    for(int i = 0; i<5; i++)
    {
        printf("Ref.%i  %s \t %.2f x %i kg/ud\n", c.compras->producto->ref, c.compras->producto->nombre, c.compras->producto->precio, c.compras->cant);
    }
    printf("...................................................................\n");
    printf("TOTAL: %.2f euros", c.importe);
}

void devolverCarrito(Carrito c)
{
    free(c.compras);
}