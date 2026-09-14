/*
 * @file ce_03_mayor_menor_ternarios.c
 * @brief Greater than and less than with ternary operators.
 * @author Douglas Bonilla
 * @date 13/09/2026
 */
#include <stdio.h>

int mayor_de_tres(int a, int b, int c) {
    int mayor_ab = (a > b) ? a : b;
    return (mayor_ab > c) ? mayor_ab : c;
}

int menor_de_tres(int a, int b, int c) {
    int menor_ab = (a < b) ? a : b;
    return (menor_ab < c) ? menor_ab : c;
}

int main(void) {
    int a, b, c;

    printf("Ingrese tres enteros: ");
    if (scanf("%d %d %d", &a, &b, &c) != 3) {
        printf("Entrada invalida.\n");
        return 1;
    }

    printf("Mayor: %d\n", mayor_de_tres(a, b, c));
    printf("Menor: %d\n", menor_de_tres(a, b, c));

    return 0;
}
