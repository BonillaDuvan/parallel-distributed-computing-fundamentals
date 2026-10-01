/**
 * @file parte1_ejercicio5_reserva_memoria_con_doble_puntero.c
 * @brief Reserva memoria dinamica mediante un puntero a puntero y suma un arreglo.
 * @author Douglas Bonilla
 * @date 2026-09-30
 */

#include <stdio.h>
#include <stdlib.h>

int crearArreglo(int **arreglo, int n) {
    *arreglo = malloc((size_t)n * sizeof(int));
    return *arreglo != NULL;
}

int main(void) {
    int n;
    long long suma = 0;
    int *arreglo = NULL;

    printf("Cantidad de elementos: ");
    if (scanf("%d", &n) != 1 || n < 1 || n > 1000000) {
        printf("Cantidad invalida.\n");
        return 1;
    }

    if (!crearArreglo(&arreglo, n)) {
        printf("No se pudo reservar memoria.\n");
        return 1;
    }

    printf("Ingrese %d enteros:\n", n);
    for (int i = 0; i < n; i++) {
        if (scanf("%d", arreglo + i) != 1) {
            printf("Entrada invalida.\n");
            free(arreglo);
            return 1;
        }
        suma += *(arreglo + i);
    }

    printf("Suma: %lld\n", suma);

    free(arreglo);
    return 0;
}