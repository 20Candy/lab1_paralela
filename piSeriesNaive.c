// Laboratorio 1 Computacion Paralela
// Stefano Aragoni, Roberto Vallecillos, Carol Arevalo
// Series de PI Naive

#include <stdio.h>
#include <omp.h>

int main() {
    int n = 1000;  
    int thread_count = 2; 
    double factor = 1.0;
    double sum = 0.0;
    double pi_approx;

    #pragma omp parallel for num_threads(thread_count) reduction(+:sum)
    for (int k = 0; k < n; k++) {
        sum += factor / (2.0 * k + 1.0);
        factor = -factor;
    }

    pi_approx = 4.0 * sum;

    printf("Valor de PI: %f\n", pi_approx);

    return 0;
}