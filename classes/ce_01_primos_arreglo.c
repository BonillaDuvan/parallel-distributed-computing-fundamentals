/*
 * @file ce_01_primos_arreglo.c
 * @brief  Prime numbers in an array.
 * @author Douglas Bonilla
 * @date 13/09/2026
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ALEATORIO 100
#define MIN_ALEATORIO 1

int es_primo(int numero) {
    if (numero < 2) {
        return 0;
    }

    for (int i = 2; i * i <= numero; i++) {
        if (numero % i == 0) {
            return 0;
        }
    }
    return 1;
}

int main(void) {
    int n;

    printf("Tamano del arreglo: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("El tamano debe ser un entero positivo.\n");
        return 1;
    }

    int *arreglo = malloc((size_t)n * sizeof(int));
    if (arreglo == NULL) {
        printf("No fue posible reservar memoria.\n");
        return 1;
    }

    srand((unsigned)time(NULL));

    int cantidad_primos = 0;

    printf("\nArreglo generado:\n");
    for (int i = 0; i < n; i++) {
        arreglo[i] = MIN_ALEATORIO +
                     rand() % (MAX_ALEATORIO - MIN_ALEATORIO + 1);
        printf("%d ", arreglo[i]);

        if (es_primo(arreglo[i])) {
            cantidad_primos++;
        }
    }

    printf("\n\nCantidad de numeros primos: %d\n", cantidad_primos);

    free(arreglo);
    return 0;
}
