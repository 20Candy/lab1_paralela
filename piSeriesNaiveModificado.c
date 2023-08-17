// Laboratorio 1 Computacion Paralela
// Stefano Aragoni, Roberto Vallecillos, Carol Arevalo
// Series de Pi sin dependencia en el loop

#include <stdio.h>
#include <omp.h>

int main() {
    int n = 10000000;  
    int thread_count = 1;  
    double sum = 0.0;
    double pi_approx;

    #pragma omp parallel for num_threads(thread_count) reduction(+:sum)
    for (int k = 0; k < n; k++) {
        double factor = (k % 2 == 0) ? 1.0 : -1.0;
        sum += factor / (2.0 * k + 1.0);
    }

    pi_approx = 4.0 * sum;

    printf("Approximate value of PI: %.10f\n", pi_approx);

    return 0;
}