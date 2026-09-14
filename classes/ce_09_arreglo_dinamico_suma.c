/*
 * @file ce_09_arreglo_dinamico_suma.c
 * @brief Dynamic memory with arrays.
 * @author Douglas Bonilla 
 * @date 13/09/2026
 */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n;
    long long suma = 0;

    printf("Numero de elementos: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("El numero de elementos debe ser positivo.\n");
        return 1;
    }

    int *arreglo = malloc((size_t)n * sizeof(int));
    if (arreglo == NULL) {
        printf("No fue posible reservar memoria.\n");
        return 1;
    }

    printf("Ingrese %d valores:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arreglo[i]);
        suma += arreglo[i];
    }

    printf("Suma total: %lld\n", suma);

    free(arreglo);
    return 0;
}
