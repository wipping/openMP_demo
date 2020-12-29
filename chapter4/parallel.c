#include <stdio.h>
#include <omp.h>
int main()
{
    int tid, nthreads;
    nthreads = omp_get_num_threads();
    tid = omp_get_thread_num();

    if(omp_in_parallel())
    {
        printf("in the parallel region! id = %d   number of threads: %d\n", tid, nthreads);
    }
    else
    {
        printf("in the serial region! id = %d   number of threads: %d\n", tid, nthreads);     
    }
    printf("-----before parallel region\n\n");

    #pragma omp parallel private(tid, nthreads)
    {
        nthreads = omp_get_num_threads();
        tid = omp_get_thread_num();
        if(omp_in_parallel())
        {
            printf("in the parallel region! id = %d   number of threads: %d\n", tid, nthreads);
        }
        else
        {
            printf("in the serial region! id = %d   number of threads: %d\n", tid, nthreads);     
        }
    }
    printf("\n");
    printf("----after parallel region\n");

    nthreads = omp_get_num_threads();
    tid = omp_get_thread_num();
    tid = omp_get_thread_num();
    if(omp_in_parallel())
    {
        printf("in the parallel region! id = %d   number of threads: %d\n", tid, nthreads);
    }
    else
    {
        printf("in the serial region! id = %d   number of threads: %d\n", tid, nthreads);     
    }
    return 0;
}