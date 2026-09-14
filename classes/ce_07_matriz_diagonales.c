/*
 * @file ce_07_matriz_diagonales.c
 * @brief  Square matrix and diagonals.
 * @author Douglas Bonilla 
 * @date 13/09/2026
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ALEATORIO 50
#define MIN_ALEATORIO 1

int main(void) {
    int n;

    printf("Tamano de la matriz cuadrada: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("El tamano debe ser un entero positivo.\n");
        return 1;
    }

    int matriz[n][n];
    int suma_principal = 0;
    int suma_secundaria = 0;

    srand((unsigned)time(NULL));

    printf("\nMatriz generada:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matriz[i][j] = MIN_ALEATORIO +
                           rand() % (MAX_ALEATORIO - MIN_ALEATORIO + 1);
            printf("%4d", matriz[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < n; i++) {
        suma_principal += matriz[i][i];
        suma_secundaria += matriz[i][n - 1 - i];
    }

    printf("\nSuma diagonal principal: %d\n", suma_principal);
    printf("Suma diagonal secundaria: %d\n", suma_secundaria);

    if (suma_principal > suma_secundaria) {
        printf("La diagonal principal tiene la suma mayor.\n");
    } else if (suma_secundaria > suma_principal) {
        printf("La diagonal secundaria tiene la suma mayor.\n");
    } else {
        printf("Ambas diagonales tienen la misma suma.\n");
    }

    return 0;
}
