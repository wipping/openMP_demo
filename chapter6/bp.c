#include <stdio.h>
#include <omp.h>

int main()
{
    int nthreads, tid;
    omp_set_num_threads(8);
    #pragma omp parallel private(tid, nthreads)
    {
        tid = omp_get_thread_num();
        nthreads = omp_get_num_threads();
        printf("hello from thread id = %d in %d threads\n", tid, nthreads);
        #pragma omp barrier
        if(0 == tid) {
            nthreads = omp_get_num_threads();
            printf("there are %d threads to say hello!\n", omp_get_num_threads());
        }
    }
    return 0;
}