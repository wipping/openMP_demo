#include <stdio.h>
#include <omp.h>

int main()
{
    int i, tid, nthreads;
    int a[10];

    omp_set_num_threads(3);
    printf("nthreads    id    i    a[]\n");

    #pragma omp parallel private(i, tid, nthreads) shared(a)
    {
        #pragma omp for
        for(i = 0; i < 10; i++)
        {
            a[i] = i + 1;
            tid = omp_get_thread_num();
            nthreads = omp_get_num_threads();
            printf("   %d        %d    %d     %d\n", nthreads, tid, i, a[i]);
        }

        #pragma omp single
        printf("\n");

        #pragma omp for ordered
        for(i = 1; i < 10; i++)
        {
            #pragma omp ordered
            a[i] = a[i-1] - 1;

            tid = omp_get_thread_num();
            nthreads = omp_get_num_threads();
            printf("   %d        %d    %d     %d\n", nthreads, tid, i, a[i]);
        }
    }
    return 0;
}