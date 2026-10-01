/**
 * @file parte1_ejercicio1_recorrido_punteros.c
 * @brief Recorre un arreglo usando aritmetica de punteros.
 * @author Douglas Bonilla
 * @date 2026-09-30
 */

#include <stdio.h>

int main(void) {
    int arreglo[] = {10, 20, 30, 40, 50};
    int n = (int)(sizeof(arreglo) / sizeof(arreglo[0]));
    int *p = arreglo;

    printf("Elementos del arreglo:\n");

    for (int i = 0; i < n; i++) {
        printf("Elemento %d: %d\n", i, *(p + i));
    }

    return 0;
}
