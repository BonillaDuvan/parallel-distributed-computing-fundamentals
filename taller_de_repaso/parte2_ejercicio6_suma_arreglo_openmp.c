/**
 * @file parte2_ejercicio6_suma_arreglo_openmp.c
 * @brief Compara la suma secuencial y paralela de un arreglo con OpenMP.
 * @author Douglas Bonilla
 * @date 2026-09-30
 */

#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main(void) {
    int n, hilos;

    printf("Tamano del arreglo (recomendado 1000000 o mas): ");
    if (scanf("%d", &n) != 1 || n < 1 || n > 100000000) {
        printf("Tamano invalido.\n");
        return 1;
    }

    printf("Numero de hilos (por ejemplo 2, 4 u 8): ");
    if (scanf("%d", &hilos) != 1 || hilos < 1) {
        printf("Numero de hilos invalido.\n");
        return 1;
    }

    double *arreglo = malloc((size_t)n * sizeof(double));
    if (arreglo == NULL) {
        printf("No se pudo reservar memoria.\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        arreglo[i] = (double)(i % 100) / 10.0;
    }

    double sumaSecuencial = 0.0;
    double inicio = omp_get_wtime();

    for (int i = 0; i < n; i++) {
        sumaSecuencial += arreglo[i];
    }

    double Ts = omp_get_wtime() - inicio;

    double sumaParalela = 0.0;
    omp_set_num_threads(hilos);
    inicio = omp_get_wtime();

    #pragma omp parallel for reduction(+:sumaParalela)
    for (int i = 0; i < n; i++) {
        sumaParalela += arreglo[i];
    }

    double Tp = omp_get_wtime() - inicio;
    double speedup = (Tp > 0.0) ? Ts / Tp : 0.0;
    double eficiencia = speedup / hilos;

    printf("\nSuma secuencial: %.6f\n", sumaSecuencial);
    printf("Suma paralela: %.6f\n", sumaParalela);
    printf("Ts: %.9f segundos\n", Ts);
    printf("Tp: %.9f segundos\n", Tp);
    printf("Hilos: %d\n", hilos);
    printf("Speedup experimental: %.6f\n", speedup);
    printf("Eficiencia: %.6f (%.2f%%)\n", eficiencia, eficiencia * 100.0);

    free(arreglo);
    return 0;
}
