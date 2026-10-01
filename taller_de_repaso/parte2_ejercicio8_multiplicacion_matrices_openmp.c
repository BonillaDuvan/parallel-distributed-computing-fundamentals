/**
 * @file parte2_ejercicio8_multiplicacion_matrices_openmp.c
 * @brief Compara la multiplicacion secuencial y paralela de matrices con OpenMP.
 * @author Douglas Bonilla
 * @date 2026-09-30
 */

#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main(void) {
    int n, hilos;

    printf("Dimension de las matrices cuadradas (recomendado 300 o mas): ");
    if (scanf("%d", &n) != 1 || n < 1 || n > 3000) {
        printf("Dimension invalida.\n");
        return 1;
    }

    printf("Numero de hilos (por ejemplo 2, 4 u 8): ");
    if (scanf("%d", &hilos) != 1 || hilos < 1) {
        printf("Numero de hilos invalido.\n");
        return 1;
    }

    size_t cantidad = (size_t)n * (size_t)n;
    double *a = malloc(cantidad * sizeof(double));
    double *b = malloc(cantidad * sizeof(double));
    double *cSec = calloc(cantidad, sizeof(double));
    double *cPar = calloc(cantidad, sizeof(double));

    if (a == NULL || b == NULL || cSec == NULL || cPar == NULL) {
        printf("No se pudo reservar memoria.\n");
        free(a);
        free(b);
        free(cSec);
        free(cPar);
        return 1;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            a[(size_t)i * n + j] = (double)((i + j) % 10);
            b[(size_t)i * n + j] = (double)((i * 2 + j) % 10);
        }
    }

    double inicio = omp_get_wtime();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            double suma = 0.0;
            for (int k = 0; k < n; k++) {
                suma += a[(size_t)i * n + k] * b[(size_t)k * n + j];
            }
            cSec[(size_t)i * n + j] = suma;
        }
    }

    double Ts = omp_get_wtime() - inicio;

    omp_set_num_threads(hilos);
    inicio = omp_get_wtime();

    #pragma omp parallel for
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            double suma = 0.0;
            for (int k = 0; k < n; k++) {
                suma += a[(size_t)i * n + k] * b[(size_t)k * n + j];
            }
            cPar[(size_t)i * n + j] = suma;
        }
    }

    double Tp = omp_get_wtime() - inicio;
    double speedup = (Tp > 0.0) ? Ts / Tp : 0.0;
    double eficiencia = speedup / hilos;

    int correcto = 1;
    for (size_t i = 0; i < cantidad; i++) {
        if (cSec[i] != cPar[i]) {
            correcto = 0;
            break;
        }
    }

    printf("\nMatrices calculadas. Verificacion: %s\n", correcto ? "correcta" : "diferencias encontradas");
    printf("Elemento C[0][0]: %.2f\n", cPar[0]);
    printf("Elemento C[n-1][n-1]: %.2f\n", cPar[cantidad - 1]);
    printf("Ts: %.9f segundos\n", Ts);
    printf("Tp: %.9f segundos\n", Tp);
    printf("Hilos: %d\n", hilos);
    printf("Speedup experimental: %.6f\n", speedup);
    printf("Eficiencia: %.6f (%.2f%%)\n", eficiencia, eficiencia * 100.0);

    free(a);
    free(b);
    free(cSec);
    free(cPar);
    return 0;
}
