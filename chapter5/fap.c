#include <stdio.h>
#include <omp.h>

int main()
{
    int nthreads, tid, i;
    int a[10], b[10], c[10];
    omp_set_num_threads(3);

    for(i = 0; i < 10; i++)
    {
        a[i] = 10 * (i+1);
        b[i] = i + 1;
        tid = omp_get_thread_num();
        nthreads = omp_get_num_threads();
        printf("nthreads = %d, tid = %d, a[%d] = %d\n", nthreads, tid, i, a[i]);
    }
    printf("-----before parallel\n");
    printf("\n");

    #pragma omp parallel private(tid, nthreads) shared(a, b, c)
    {
        #pragma omp for
        for(i = 0; i < 10; i++)
        {
            tid = omp_get_thread_num();
            nthreads = omp_get_num_threads();
            c[i] = a[i] + b[i];
            printf("nthreads = %d, tid = %d, c[%d] = %d\n", nthreads, tid, i, c[i]);
        }
    }
    printf("\n");
    printf("-----after parallel\n");
    tid = omp_get_thread_num();
    nthreads = omp_get_num_threads();
    printf("nthreads = %d, tid = %d\n", nthreads, tid);
    return 0;
}