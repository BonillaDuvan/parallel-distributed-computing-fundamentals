/*
 * @file ce_02_speedup.c
 * @brief Speedup.
 * @author Douglas Bonilla 
 * @date 20/09/2026
 */

#include <stdio.h>

int main() {
    double Ts, Tp, speedup;

    printf("========================================\n");
    printf(" SPEEDUP EXPERIMENTAL\n");
    printf("========================================\n\n");

    printf("Ingrese el tiempo secuencial Ts (segundos): ");
    scanf("%lf", &Ts);

    printf("Ingrese el tiempo paralelo Tp (segundos): ");
    scanf("%lf", &Tp);

    if (Ts <= 0 || Tp <= 0) {
        printf("\nError: los tiempos deben ser mayores que 0.\n");
        return 1;
    }

    speedup = Ts / Tp;

    printf("\n----------------------------------------\n");
    printf("Tiempo secuencial Ts = %.6f segundos\n", Ts);
    printf("Tiempo paralelo Tp   = %.6f segundos\n", Tp);
    printf("Speedup experimental = %.6f\n", speedup);
    printf("----------------------------------------\n");

    printf("\nFormula:\n");
    printf("S = Ts / Tp\n");
    printf("S = %.6f / %.6f\n", Ts, Tp);
    printf("S = %.6f\n", speedup);

    return 0;
}