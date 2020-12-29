#include <stdio.h>
#include <omp.h>

int main()
{
    int nthreads_set, nthreads, tid;

    nthreads_set = 3;
    omp_set_dynamic(1);
    omp_set_num_threads(nthreads_set);
    printf("set_number_threads = %d\n", nthreads_set);
    printf("dynamic region(1 or 0): %d\n\n", omp_get_dynamic());
    
    #pragma omp parallel private(tid, nthreads)
    {
        nthreads = omp_get_num_threads();
        tid = omp_get_thread_num();
        printf("number of threads = %d   tid = %d\n", nthreads, tid);
        printf("------------------------\n");
    }
    return 0;
}

