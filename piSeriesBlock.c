// Laboratorio 1 Computacion Paralela
// Stefano Aragoni, Roberto Vallecillos, Carol Arevalo
// Políticas de planificación y block_size

#include <stdio.h>
#include <omp.h>

int main() {
    int n = 10e6;  
    int thread_count = omp_get_num_procs();;   // 4 cores tiene la maquina virtual
    double pi_approx;
    
    printf("Número de hilos: %d\n", thread_count);

    return 0;
}
