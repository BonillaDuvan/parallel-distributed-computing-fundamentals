/**
 * @file parte1_ejercicio4_invertir_arreglo_punteros.c
 * @brief Invierte un arreglo utilizando aritmetica de punteros.
 * @author Douglas Bonilla
 * @date 2026-09-30
 */

#include <stdio.h>

void invertir(int *arreglo, int n) {
    int *inicio = arreglo;
    int *fin = arreglo + n - 1;

    while (inicio < fin) {
        int temporal = *inicio;
        *inicio = *fin;
        *fin = temporal;
        inicio++;
        fin--;
    }
}

void mostrar(const int *arreglo, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", *(arreglo + i));
    }
    printf("\n");
}

int main(void) {
    int n;

    printf("Cantidad de elementos (1 a 1000): ");
    if (scanf("%d", &n) != 1 || n < 1 || n > 1000) {
        printf("Cantidad invalida.\n");
        return 1;
    }

    int arreglo[1000];

    printf("Ingrese %d enteros:\n", n);
    for (int i = 0; i < n; i++) {
        if (scanf("%d", arreglo + i) != 1) {
            printf("Entrada invalida.\n");
            return 1;
        }
    }

    printf("Arreglo original: ");
    mostrar(arreglo, n);

    invertir(arreglo, n);

    printf("Arreglo invertido: ");
    mostrar(arreglo, n);

    return 0;
}