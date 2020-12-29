#include <stdio.h>
#include <omp.h>

int main()
{
    int nthreads, tid, i;
    omp_set_num_threads(2);

    printf("for schedule(static)\n");
    #pragma omp parallel for private(i) schedule(static)
    for(i = 0; i < 10; i++)
    {
        tid = omp_get_thread_num();
        nthreads = omp_get_num_threads();
        printf("nthreads = %d, id = %d, i = %d\n", nthreads, tid, i);
    }
    printf("\n");

    printf("fpr schedule(static, 2)\n");
    #pragma omp parallel for private(i) schedule(static, 2)
    for(i = 0; i < 10; i++)
    {
        tid = omp_get_thread_num();
        nthreads = omp_get_num_threads();
        printf("nthreads = %d, id = %d, i = %d\n", nthreads, tid, i);
    }
    return 0;
}