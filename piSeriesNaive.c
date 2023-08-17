#include <stdio.h>
#include <omp.h>

int main() {
    int n = 1000000;  // You can adjust the value of 'n' as needed
    int thread_count = 4;  // You can adjust the number of threads
    double factor = 1.0;
    double sum = 0.0;
    double pi_approx;

    #pragma omp parallel for num_threads(thread_count) reduction(+:sum)
    for (int k = 0; k < n; k++) {
        sum += factor / (2.0 * k + 1.0);
        factor = -factor;
    }

    pi_approx = 4.0 * sum;

    printf("Approximate value of PI: %.10f\n", pi_approx);

    return 0;
}