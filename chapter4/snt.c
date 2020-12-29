#include <stdio.h>
#include <omp.h>

int main()
{
    int nthreads_set, nthreads, tid;

    #pragma omp parallel private(tid, nthreads)
    {
        nthreads = omp_get_num_threads();
        tid = omp_get_thread_num();
        printf("number of threads(defualt) = %d   id = %d\n", nthreads, tid);
    }
    printf("-----before OMP_SET_NUM_THREADS\n\n");

    nthreads_set = 3;
    omp_set_num_threads(nthreads_set);
    printf("set_number_threads = %d\n", nthreads_set);

    #pragma omp parallel private(tid, nthreads)
    {
        nthreads = omp_get_num_threads();
        tid = omp_get_thread_num();
        printf("number of threads(default) = %d   id = %d\n", nthreads, tid);
    }
    return 0;
}