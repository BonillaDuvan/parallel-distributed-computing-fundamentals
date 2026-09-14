/*
 * @file ce_02_intercambio_punteros.c
 * @brief Swapping values ​​using pointers.
 * @author Douglas Bonilla
 * @date 13/09/2026
 */
#include <stdio.h>

void intercambiar(int *a, int *b) {
    int temporal = *a;
    *a = *b;
    *b = temporal;
}

int main(void) {
    int a, b;

    printf("Ingrese el primer entero: ");
    scanf("%d", &a);

    printf("Ingrese el segundo entero: ");
    scanf("%d", &b);

    printf("\nAntes del intercambio: a = %d, b = %d\n", a, b);

    intercambiar(&a, &b);

    printf("Despues del intercambio: a = %d, b = %d\n", a, b);

    return 0;
}
