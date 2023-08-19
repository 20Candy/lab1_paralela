// Laboratorio 1 Computacion Paralela
// Stefano Aragoni, Roberto Vallecillos, Carol Arevalo
// Series de PI con ecuacion alternativa

#include <stdio.h>
#include <omp.h>

int main() {
    int n = 100000;  
    int thread_count = 4;  
    double pi_approx = 0.0;

    #pragma omp parallel num_threads(thread_count)
    {
        double local_sum = 0.0;

        #pragma omp for
        for (int i = 0; i < n; i++) {
            double term = (i % 2 == 0) ? 1.0 / (2.0 * i + 1) : -1.0 / (2.0 * i + 1);
            local_sum += term;
        }

        #pragma omp critical
        pi_approx += local_sum;
    }

    pi_approx *= 4.0;

    printf("Valor de PI: %.20f\n", pi_approx);

    return 0;
}