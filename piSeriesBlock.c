// Laboratorio 1 Computacion Paralela
// Stefano Aragoni, Roberto Vallecillos, Carol Arevalo
// Políticas de planificación y block_size

#include <stdio.h>
#include <omp.h>

int main() {

    omp_sched_t scheduleType = omp_sched_static;
    //omp_sched_t scheduleType = omp_sched_dynamic;
    //omp_sched_t scheduleType = omp_sched_guided;
    //omp_sched_t scheduleType = omp_sched_auto;

    int chunkSize = 16;
    omp_set_schedule(scheduleType, chunkSize); // politica de planificacion y tamaño de bloque

    // 5 iteraciones para poder llenar las tablas
    for (int i = 0; i < 5; i++) {

        int n = 10e6;  
        int thread_count = omp_get_num_procs();  // retorna el número de procesadores de la maquina virtual

        double pi_approx;
        double sum = 0.0;
        double factor = 1.0;
        double start_time, end_time;

        start_time = omp_get_wtime();

        #pragma omp parallel for num_threads(thread_count) schedule(runtime) reduction(+:sum) private(factor)
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
