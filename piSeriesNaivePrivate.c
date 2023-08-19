// Laboratorio 1 Computacion Paralela
// Stefano Aragoni, Roberto Vallecillos, Carol Arevalo
// Series de PI con scope Private

#include <stdio.h>
#include <omp.h>

int main() {
    int n = 10e6;  
    int thread_count = 4;

    // 5 iteraciones para poder llenar las tablas
    for (int i = 0; i < 5; i++) {
        double factor = 1.0;
        double sum = 0.0;
        double pi_approx;
        double start_time, end_time;

        start_time = omp_get_wtime();

        #pragma omp parallel for num_threads(thread_count) reduction(+:sum) private(factor)
        for (int k = 0; k < n; k++) {
            factor = (k % 2 == 0) ? 1.0 : -1.0;
            sum += factor / (2.0 * k + 1.0);
        }

        pi_approx = 4.0 * sum;

        end_time = omp_get_wtime();
        printf("Valor de PI: %.20f, Tiempo: %f\n", pi_approx, end_time - start_time);
    }

    return 0;
}