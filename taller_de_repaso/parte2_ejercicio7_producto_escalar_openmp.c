/**
 * @file parte2_ejercicio7_producto_escalar_openmp.c
 * @brief Calcula el producto escalar secuencial y paralelamente con OpenMP.
 * @author Douglas Bonilla
 * @date 2026-09-30
 */

#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main(void) {
    int n, hilos;

    printf("Longitud de los vectores (recomendado 1000000 o mas): ");
    if (scanf("%d", &n) != 1 || n < 1 || n > 100000000) {
        printf("Longitud invalida.\n");
        return 1;
    }

    printf("Numero de hilos (por ejemplo 2, 4 u 8): ");
    if (scanf("%d", &hilos) != 1 || hilos < 1) {
        printf("Numero de hilos invalido.\n");
        return 1;
    }

    double *a = malloc((size_t)n * sizeof(double));
    double *b = malloc((size_t)n * sizeof(double));

    if (a == NULL || b == NULL) {
        printf("No se pudo reservar memoria.\n");
        free(a);
        free(b);
        return 1;
    }

    for (int i = 0; i < n; i++) {
        a[i] = (double)(i % 100) / 10.0;
        b[i] = (double)((i + 1) % 100) / 10.0;
    }

    double productoSecuencial = 0.0;
    double inicio = omp_get_wtime();

    for (int i = 0; i < n; i++) {
        productoSecuencial += a[i] * b[i];
    }

    double Ts = omp_get_wtime() - inicio;

    double productoParalelo = 0.0;
    omp_set_num_threads(hilos);
    inicio = omp_get_wtime();

    #pragma omp parallel for reduction(+:productoParalelo)
    for (int i = 0; i < n; i++) {
        productoParalelo += a[i] * b[i];
    }

    double Tp = omp_get_wtime() - inicio;
    double speedup = (Tp > 0.0) ? Ts / Tp : 0.0;
    double eficiencia = speedup / hilos;

    printf("\nProducto secuencial: %.6f\n", productoSecuencial);
    printf("Producto paralelo: %.6f\n", productoParalelo);
    printf("Ts: %.9f segundos\n", Ts);
    printf("Tp: %.9f segundos\n", Tp);
    printf("Hilos: %d\n", hilos);
    printf("Speedup experimental: %.6f\n", speedup);
    printf("Eficiencia: %.6f (%.2f%%)\n", eficiencia, eficiencia * 100.0);

    free(a);
    free(b);
    return 0;
}
