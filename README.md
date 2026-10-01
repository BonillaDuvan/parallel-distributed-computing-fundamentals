# Parallel & Distributed Computing Fundamentals

Repositorio dedicado a los fundamentos de programación paralela, distribuida y gestión de memoria en C. Contiene la resolución del **Taller de Repaso**, abarcando el uso de punteros, asignación dinámica de memoria y paralelización de algoritmos mediante OpenMP.

---

## 📁 Estructura del Repositorio

```text
parallel-distributed-computing-fundamentals/
├── classes/
│   ├── ce_01_primos_arreglo.c
│   ├── ce_02_intercambio_punteros.c
│   ├── ce_03_mayor_menor_ternarios.c
│   ├── ce_04_factorial_paridad.c
│   ├── ce_05_suma_digitos_recursiva.c
│   ├── ce_06_invertir_arreglo_punteros.c
│   ├── ce_07_matriz_diagonales.c
│   ├── ce_08_notas_calificaciones.c
│   ├── ce_09_arreglo_dinamico_suma.c
│   └── ce_10_gestion_estudiantes_structs.c
├── docs/
│   └── FP_PD_01_TALLER_REPASO_C.md
├── sessions/
├── taller_de_repaso/
│   ├── parte1_ejercicio1_recorrido_punteros.c
│   ├── parte1_ejercicio2_intercambio_punteros.c
│   ├── parte1_ejercicio3_puntero_a_puntero.c
│   ├── parte1_ejercicio4_invertir_arreglo_punteros.c
│   ├── parte1_ejercicio5_reserva_memoria_con_doble_puntero.c
│   ├── parte2_ejercicio6_suma_arreglo_openmp.c
│   ├── parte2_ejercicio7_producto_escalar_openmp.c
│   └── parte2_ejercicio8_multiplicacion_matrices_openmp.c
├── .gitignore
└── README.md

📌 Contenido de los Ejercicios (classes/)

1.ce_01_primos_arreglo.c: Búsqueda y filtrado de números primos en arreglos.

2.ce_02_intercambio_punteros.c: Intercambio de valores (swap) mediante paso por referencia con punteros.

3.ce_03_mayor_menor_ternarios.c: Evaluación de valores máximo/mínimo empleando operadores ternarios.

4.ce_04_factorial_paridad.c: Cálculo iterativo/recursivo de factoriales y verificación de paridad.

5.ce_05_suma_digitos_recursiva.c: Algoritmo recursivo para la suma de los dígitos de un número.

6.ce_06_invertir_arreglo_punteros.c: Inversión de arreglos utilizando aritmética de punteros.

7.ce_07_matriz_diagonales.c: Manipulación de matrices bidimensionales y cálculo de diagonales.

8.ce_08_notas_calificaciones.c: Procesamiento de datos estadísticos sobre calificaciones.

9.ce_09_arreglo_dinamico_suma.c: Gestión e incremento dinámico de memoria con malloc y free.

10.ce_10_gestion_estudiantes_structs.c: Modelado de entidades y registros mediante estructuras (struct).

📌 Contenido del Taller de Repaso (taller_de_repaso/)

*Parte 1: Punteros y Memoria Dinámica

1.parte1_ejercicio1_recorrido_punteros.c: Recorrido de arreglos utilizando aritmética de punteros.

2.parte1_ejercicio2_intercambio_punteros.c: Intercambio de valores (swap) mediante paso por referencia.

3.parte1_ejercicio3_puntero_a_puntero.c: Manipulación de direcciones con indirección múltiple (punteros a punteros).

4.parte1_ejercicio4_invertir_arreglo_punteros.c: Inversión de arreglos in-place usando punteros inicio/fin.

5.parte1_ejercicio5_reserva_memoria_con_doble_puntero.c: Asignación y liberación dinámica de memoria con malloc/free.

*Parte 2: Programación Paralela con OpenMP

Los programas de la Parte 2 incluyen límites máximos de datos y validación de memoria para prevenir el agotamiento de RAM o colapso del equipo.

1.parte2_ejercicio6_suma_arreglo_openmp.c

2.parte2_ejercicio7_producto_escalar_openmp.c

3.parte2_ejercicio8_multiplicacion_matrices_openmp.c


🛠️️ Compilación y 

Ejercicios de classes/

Bash
gcc -std=c11 -Wall -Wextra -pedantic classes/ce_01_primos_arreglo.c -o ce_01
.\ce_01.exe

Ejercicios de taller_de_repaso/

Parte 1 (Punteros):

Bash
gcc -std=c11 taller_de_repaso/parte1_ejercicio1_recorrido_punteros.c -o parte1_ej1
.\parte1_ej1.exe

Parte 2 (OpenMP):
Requiere el flag -fopenmp para habilitar el soporte multihilo:


Bash
gcc -fopenmp taller_de_repaso/parte2_ejercicio6_suma_arreglo_openmp.c -o ej6
gcc -fopenmp taller_de_repaso/parte2_ejercicio7_producto_escalar_openmp.c -o ej7
gcc -fopenmp taller_de_repaso/parte2_ejercicio8_multiplicacion_matrices_openmp.c -o ej8

.\ej6.exe



