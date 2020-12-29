#include <stdio.h>
#include <omp.h>

int main()
{
    int tid, nthreads;

    omp_set_num_threads(2);

    #pragma omp parallel private(tid, nthreads)
    {
        #pragma omp sections nowait
        {
            #pragma omp section
            {
                tid = omp_get_thread_num();
                nthreads = omp_get_num_threads();
                printf("section 1: nthreads = %d, tid = %d\n", nthreads, tid);
            }

            #pragma omp section
            {
                tid = omp_get_thread_num();
                nthreads = omp_get_num_threads();
                printf("section 2: nthreads = %d, tid = %d\n", nthreads, tid);
            }

            #pragma omp section
            {
                tid = omp_get_thread_num();
                nthreads = omp_get_num_threads();
                printf("section 3: nthreads = %d, tid = %d\n", nthreads, tid);                
            }
        }
    }
    return 0;
}