#include <stdio.h>
#include <omp.h>

int main()
{
    int tid, i;
    int a[5];
    int sum, pdt, amax;

    omp_set_num_threads(4);
    tid = omp_get_thread_num();
    for(i = 0; i < 5; i++)
    {
        a[i] = i + 1;
        printf("a[%d] = %d, ", i, a[i]);
    }
    printf("\n");
    
    sum = 0;
    #pragma omp parallel private(i, tid) shared(a) reduction(+:sum)
    {
        #pragma omp for
        for(i = 0; i < 5; i++)
        {
            tid = omp_get_thread_num();
            sum += a[i];
            printf("i = %d, sum = %d, id = %d\n", i, sum, tid);
        }
    }

    printf("sum = %d\n", sum);
    printf("\n");

    pdt = 1;

    #pragma omp parallel for private(i, tid) shared(a) reduction(*:pdt)
    for(i = 0; i < 5; i++)
    {
        tid = omp_get_thread_num();
        pdt = pdt * a[i];
        printf("i = %d, pdt = %d, id = %d\n", i, pdt, tid);
    }
    printf("pdt = %d\n", pdt);
    printf("\n");

    amax = -1000;
    #pragma omp parallel for reduction(max:amax) private(i, tid) shared(a)
    for(i = 0; i < 5; i++)
    {
        tid = omp_get_thread_num();
        amax = amax > a[i] ? amax : a[i];
        printf("i = %d, amax = %d, id = %d\n", i, amax, tid);
    }

    printf("amax = %d\n", amax);
    return 0;
}