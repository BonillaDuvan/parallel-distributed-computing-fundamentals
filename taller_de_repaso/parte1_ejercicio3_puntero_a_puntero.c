/**
 * @file parte1_ejercicio3_puntero_a_puntero.c
 * @brief Accede y modifica una variable mediante un puntero a puntero.
 * @author Douglas Bonilla
 * @date 2026-09-30
 */

#include <stdio.h>

int main(void) {
    int numero;

    printf("Ingrese un entero: ");
    if (scanf("%d", &numero) != 1) {
        printf("Entrada invalida.\n");
        return 1;
    }

    int *p = &numero;
    int **pp = &p;

    printf("Valor original: %d\n", **pp);
    **pp = **pp * 2;
    printf("Valor duplicado mediante puntero a puntero: %d\n", numero);

    return 0;
}
