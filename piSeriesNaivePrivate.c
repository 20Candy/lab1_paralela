// Laboratorio 1 Computacion Paralela
// Stefano Aragoni, Roberto Vallecillos, Carol Arevalo
// Series de PI con scope Private

#include <stdio.h>
#include <omp.h>

int main() {
    int n = 1000000;  
    int thread_count = 4;  
    double sum = 0.0;
    double pi_approx;

    #pragma omp parallel num_threads(thread_count) private(sum)
    {
        double local_sum = 0.0;
        #pragma omp for
        for (int k = 0; k < n; k++) {
            double factor = (k % 2 == 0) ? 1.0 : -1.0;
            local_sum += factor / (2.0 * k + 1.0);
        }
        #pragma omp critical
        sum += local_sum;
    }

    pi_approx = 4.0 * sum;

    printf("Valor de PI: %.20f\n", pi_approx);

    return 0;
}