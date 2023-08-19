// Laboratorio 1 Computacion Paralela
// Stefano Aragoni, Roberto Vallecillos, Carol Arevalo
// Series de PI con scope Private

#include <stdio.h>
#include <omp.h>

int main() {
    int n = 10000000;  
    int thread_count = 2;  
    double sum = 0.0;
    double pi_approx;
    double factor = 1.0;

    #pragma omp parallel for num_threads(thread_count) reduction(+:sum) private(factor)
    for (int k = 0; k < n; k++) {
        factor = (k % 2 == 0) ? 1.0 : -1.0;
        sum += factor / (2.0 * k + 1.0);
    }

    pi_approx = 4.0 * sum;

    printf("Valor de PI: %.20f\n", pi_approx);

    return 0;
}