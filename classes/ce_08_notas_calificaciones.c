/*
 * @file ce_08_notas_calificaciones.c
 * @brief Grades and marks.
 * @author Douglas Bonilla 
 * @date 13/09/2026
 */
#include <stdio.h>

char obtener_calificacion(double nota) {
    if (nota >= 90.0 && nota <= 100.0) {
        return 'A';
    } else if (nota >= 80.0) {
        return 'B';
    } else if (nota >= 70.0) {
        return 'C';
    } else if (nota >= 60.0) {
        return 'D';
    } else {
        return 'F';
    }
}

int main(void) {
    double nota;

    printf("Ingrese una nota entre 0 y 100: ");
    if (scanf("%lf", &nota) != 1 || nota < 0.0 || nota > 100.0) {
        printf("La nota debe estar entre 0 y 100.\n");
        return 1;
    }

    printf("Calificacion: %c\n", obtener_calificacion(nota));

    return 0;
}
