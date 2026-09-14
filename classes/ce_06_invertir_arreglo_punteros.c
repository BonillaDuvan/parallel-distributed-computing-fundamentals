/*
 * @file ce_06_invertir_arreglo_punteros.c
 * @brief Reverse an array using pointer arithmetic.
 * @author Douglas Bonilla 
 * @date 13/09/2026
 */
#include <stdio.h>

void invertir_arreglo(int *inicio, int *fin) {
    while (inicio < fin) {
        int temporal = *inicio;
        *inicio = *fin;
        *fin = temporal;

        inicio++;
        fin--;
    }
}

void mostrar_arreglo(const int *arreglo, int n) {
    for (const int *p = arreglo; p < arreglo + n; p++) {
        printf("%d ", *p);
    }
    printf("\n");
}

int main(void) {
    int n;

    printf("Tamano del arreglo: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("El tamano debe ser un entero positivo.\n");
        return 1;
    }

    int arreglo[n];

    printf("Ingrese %d enteros:\n", n);
    for (int *p = arreglo; p < arreglo + n; p++) {
        scanf("%d", p);
    }

    printf("Arreglo original: ");
    mostrar_arreglo(arreglo, n);

    invertir_arreglo(arreglo, arreglo + n - 1);

    printf("Arreglo invertido: ");
    mostrar_arreglo(arreglo, n);

    return 0;
}
