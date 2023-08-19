// Laboratorio 1 Computacion Paralela
// Stefano Aragoni, Roberto Vallecillos, Carol Arevalo
// Series de PI con ecuacion alternativa

#include <stdio.h>
#include <omp.h>

int main() {
    int n = 10000000;  
    int thread_count = 6; 
    double pi_approx;

    double sum_pos = 0.0;
    double sum_neg = 0.0;

    #pragma omp parallel for num_threads(thread_count) reduction(+:sum_pos)
    for (int k = 0; k < n; k++) {
        if (k % 2 == 0) {
            sum_pos += 1.0 / (2.0 * k + 1.0);
        }
    }

    #pragma omp parallel for num_threads(thread_count) reduction(+:sum_neg)
    for (int k = 0; k < n; k++) {
        if (k % 2 != 0) {
            sum_neg += 1.0 / (2.0 * k + 1.0);
        }
    }

    double sum = sum_pos - sum_neg;
    pi_approx = 4.0 * sum;

    printf("Valor de PI: %.20f\n", pi_approx);

    return 0;
}