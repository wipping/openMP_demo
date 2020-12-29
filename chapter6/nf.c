#include <stdio.h>
#include <omp.h>

int main()
{
    int m = 4;
    int tid, nthreads, i;

    omp_set_num_threads(3);
    #pragma omp parallel private(tid, nthreads)
    {
        #pragma omp for
        for(i = 1; i <= m; i++)
        {
            tid = omp_get_thread_num();
            nthreads = omp_get_num_threads();
            printf("first for loop: %d, id = %d\n", nthreads, tid);
        }

        #pragma omp for nowait
        for(i = 1; i <= m; i++)
        {
            tid = omp_get_thread_num();
            nthreads = omp_get_num_threads();
            printf("second for loop: %d, id = %d\n", nthreads, tid);
        }

        #pragma omp for
        for(i = 1; i <= m; i++)
        {
            tid = omp_get_thread_num();
            nthreads = omp_get_num_threads();
            printf("third for loop: %d, id = %d\n", nthreads, tid);
        }
    }
    return 0;
}