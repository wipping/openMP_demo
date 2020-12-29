#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <omp.h>

int main()
{
    int tid, mcpu;

    tid = omp_get_thread_num();
    mcpu = omp_get_num_threads();
    printf("hello from thread &d in %d CPUs\n", tid, mcpu);
    printf("------before parallel\n");
    printf("\n");
    printf("------during parallel\n");

#pragma omp parallel num_threads(3) private(tid, mcpu)
{
    tid = omp_get_thread_num();
    mcpu = omp_get_num_threads();
    printf("hello from thread %d in %d CPUs\n", tid, mcpu);
}
    printf("\n");
    printf("------after parallel\n");
    printf("hello from thread %d in %d CPUs\n", tid, mcpu);
    return 0;
}
