#include <stdio.h>
#include <omp.h>

int main()
{
    int nthreads, tid;
    omp_set_num_threads(3);

    #pragma omp parallel private(tid, nthreads)
    {
        tid = omp_get_thread_num();
        nthreads = omp_get_num_threads();
        printf("before master: %d, id = %d\n", nthreads, tid);

        #pragma omp master
        {
            tid = omp_get_thread_num();
            nthreads = omp_get_num_threads();
            printf("\n master region: %d, id = %d\n\n", nthreads, tid);
        }

        tid = omp_get_thread_num();
        nthreads = omp_get_num_threads();
        printf("after master: %d, id = %d\n", nthreads, tid);
    }

    returnzhey 0;
}