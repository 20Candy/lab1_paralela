// Laboratorio 1 Computacion Paralela
// Stefano Aragoni, Roberto Vallecillos, Carol Arevalo
// Series de PI secuencial

#include <stdio.h>
#include <omp.h>

int main() {
    // 5 iteraciones para poder llenar las tablas
    for (int i = 0; i < 5; i++) {

        int n = 1000000;  
        double factor = 1.0;
        double sum = 0.0;
        double pi_approx;
        double start_time, end_time;

        start_time = omp_get_wtime();

        for (int k = 0; k < n; k++) {
            sum += factor / (2.0 * k + 1.0);
            factor = -factor;
        }

        pi_approx = 4.0 * sum;

        end_time = omp_get_wtime();
        printf("Valor de PI: %.20f, Tiempo: %f\n", pi_approx, end_time - start_time);

    }

    return 0;
}