/*
 * @file ce_10_gestion_estudiantes_structs.c
 * @brief Student management using structs.
 * @author Douglas Bonilla 
 * @date 13/09/2026
 */
#include <stdio.h>
#include <stdlib.h>

#define NUM_NOTAS 3
#define NOTA_MAXIMA 100.0
#define NOTA_APROBACION 60.0

typedef struct {
    int id;
    char nombre[100];
    double notas[NUM_NOTAS];
} Estudiante;

double calcular_promedio(const Estudiante *estudiante) {
    double suma = 0.0;

    for (int i = 0; i < NUM_NOTAS; i++) {
        suma += estudiante->notas[i];
    }

    return suma / NUM_NOTAS;
}

void mostrar_estudiante(const Estudiante *estudiante) {
    double promedio = calcular_promedio(estudiante);

    printf("ID: %d | Nombre: %s | Promedio: %.2f\n",
           estudiante->id, estudiante->nombre, promedio);
}

int main(void) {
    int n;

    printf("Numero de estudiantes: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("El numero de estudiantes debe ser positivo.\n");
        return 1;
    }

    Estudiante *estudiantes = malloc((size_t)n * sizeof(Estudiante));
    if (estudiantes == NULL) {
        printf("No fue posible reservar memoria.\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        printf("\nEstudiante %d\n", i + 1);

        printf("ID: ");
        scanf("%d", &estudiantes[i].id);

        printf("Nombre: ");
        scanf(" %99[^\n]", estudiantes[i].nombre);

        for (int j = 0; j < NUM_NOTAS; j++) {
            do {
                printf("Nota %d (0-100): ", j + 1);
                scanf("%lf", &estudiantes[i].notas[j]);

                if (estudiantes[i].notas[j] < 0.0 ||
                    estudiantes[i].notas[j] > NOTA_MAXIMA) {
                    printf("La nota debe estar entre 0 y 100.\n");
                }
            } while (estudiantes[i].notas[j] < 0.0 ||
                     estudiantes[i].notas[j] > NOTA_MAXIMA);
        }
    }

    printf("\n=== Promedio de cada estudiante ===\n");
    for (int i = 0; i < n; i++) {
        mostrar_estudiante(&estudiantes[i]);
    }

    printf("\n=== Estudiantes aprobados ===\n");
    int hay_aprobados = 0;

    for (int i = 0; i < n; i++) {
        if (calcular_promedio(&estudiantes[i]) >= NOTA_APROBACION) {
            mostrar_estudiante(&estudiantes[i]);
            hay_aprobados = 1;
        }
    }

    if (!hay_aprobados) {
        printf("No hay estudiantes aprobados.\n");
    }

    free(estudiantes);
    return 0;
}
