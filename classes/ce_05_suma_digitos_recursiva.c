/*
 * @file ce_05_suma_digitos_recursiva.c
 * @brief Suma recursive digit
 * @author Douglas Bonilla
 * @date 13/09/2026
 * 
 */
#include <stdio.h>

int suma_digitos(unsigned long long numero) {
    if (numero < 10) {
        return (int)numero;
    }

    return (int)(numero % 10) + suma_digitos(numero / 10);
}

int main(void) {
    unsigned long long numero;

    printf("Ingrese un entero positivo: ");
    if (scanf("%llu", &numero) != 1) {
        printf("Entrada invalida.\n");
        return 1;
    }

    printf("Suma de los digitos: %d\n", suma_digitos(numero));

    return 0;
}
