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
    float sumatorio =0;
    float importeTotal = 0;
    c->importe =0;
    c->compras=(Compra*) malloc(tamanyo*(sizeof(Compra)));
    for(int i=0; i<tamanyo; i++)
    {
        c->compras[i].producto = productos[i];
        c->compras[i].cant = cantidades[i];
    }
    for(int i=0; i<tamanyo; i++)
    {
        sumatorio = c->compras[i].cant * c->compras[i].producto[i].precio;
        importeTotal += sumatorio;
    }
    c->importe = importeTotal;
}

void imprimirCarrito(Carrito c)
{
    printf("TICKET\n");
    printf("------\n");
    for(int i = 0; i < 5; i++)
    {
        printf("Ref.%i  %s \t %.2f x %i kg/ud\n", c.compras[i].producto->ref, c.compras[i].producto->nombre, c.compras[i].producto->precio, c.compras[i].cant);
    }
    printf("...................................................................\n");
    printf("TOTAL: %.2f euros", c.importe);
}

void devolverCarrito(Carrito c)
{
    free(c.compras);
}