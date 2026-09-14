/*
 * @file ce_04_factorial_paridad.c
 * @brief Factorial and parity.
 * @author Douglas Bonilla
 * @date 13/09/2026

 */
#include <stdio.h>

int main(void) {
    int n;
    unsigned long long factorial = 1;

    printf("Ingrese un entero positivo: ");
    if (scanf("%d", &n) != 1) {
        printf("Entrada invalida.\n");
        return 1;
    }

    while (n < 0) {
        printf("El numero debe ser positivo o cero. Intente nuevamente: ");
        if (scanf("%d", &n) != 1) {
            printf("Entrada invalida.\n");
            return 1;
        }
    }

    for (int i = 2; i <= n; i++) {
        factorial *= (unsigned long long)i;
    }

    if (n % 2 == 0) {
        printf("El numero %d es par.\n", n);
    } else {
        printf("El numero %d es impar.\n", n);
    }

    printf("Factorial de %d: %llu\n", n, factorial);

    return 0;
}
