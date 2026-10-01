/**
 * @file parte1_ejercicio2_intercambio_punteros.c
 * @brief Intercambia dos valores enteros usando punteros.
 * @author Douglas Bonilla
 * @date 2026-09-30
 */

#include <stdio.h>

void intercambiar(int *a, int *b) {
    int temporal = *a;
    *a = *b;
    *b = temporal;
}

int main(void) {
    int a, b;

    printf("Ingrese dos enteros: ");
    if (scanf("%d %d", &a, &b) != 2) {
        printf("Entrada invalida.\n");
        return 1;
    }

    printf("Antes: a = %d, b = %d\n", a, b);
    intercambiar(&a, &b);
    printf("Despues: a = %d, b = %d\n", a, b);

    return 0;
}