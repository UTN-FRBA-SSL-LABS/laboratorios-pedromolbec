#include <stdio.h>
#include "../src/carrito.h"
#include "minunit/minunit.h"

/*
 * Tests de integracion: verifican que las funciones trabajan bien
 * en combinacion, no de forma aislada.
 */

void test_compra_con_descuento(void){
    printf("\n[compra con descuento]\n");
    Carrito c;
    carrito_init(&c);
    Producto p = {"Pan", 200, 3};
    Producto l = {"Leche", 350, 2};  /* 350 x 2 = 700 */
    carrito_agregar(&c, p);
    carrito_agregar(&c, l);
    ASSERT_IGUAL(1300, carrito_total(&c));
    ASSERT_IGUAL(1170, carrito_descuento(1300, 10));  /* <-- completar el valor esperado */
}

void test_agregar_hasta_llenar(void){
    printf("\n[capacidad maxima de carrito]\n");
    Carrito c;
    carrito_init(&c);
    Producto p = {"Leche", 350, 1};
    carrito_agregar(&c, p);
    carrito_agregar(&c, p);
    carrito_agregar(&c, p);
    carrito_agregar(&c, p); 
    ASSERT_IGUAL(0, carrito_agregar(&c, p)); 
}

/*Llenar el carrito hasta su capacidad máxima (4 productos)
Verificar que el conteo es MAX_ITEMS
Verificar que intentar agregar uno más devuelve 0
Verificar que el conteo sigue siendo MAX_ITEMS (no cambió) */

int main(void) {
    printf("=== Tests de integracion ===");
    /* Descomentar a medida que agregues las funciones: */
    test_compra_con_descuento();
    test_agregar_hasta_llenar(); 
    RESUMEN();
    return EXIT_CODE();
}
