#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <math.h>

#define M 100000

int main()
{
    double sum = 0;
    double a[M] = {0};
    double t1, t2;

    for(int i = 0; i < M; i++){
        a[i] = 1;
    }

    t1 = omp_get_wtime();
    #pragma omp parallel
    {
        #pragma omp for simd reduction(+:sum)
        for(int i = 0; i < M; i++)
        for(int j = 0; j < M; j++)
        {
            sum += a[i];
        }
    }
    t2 = omp_get_wtime();
    printf("Elapsed CPU time = %lf seconds.\n", t2 - t1);
    printf("sum = %f\n", sum);
    printf("\n");

    t1 = omp_get_wtime();
    for(int i = 0; i < M; i++)
    for(int j = 0; j < M; j++)
    {
        sum += a[i];
    }    
    t2 = omp_get_wtime();
    printf("Elapsed CPU time = %lf seconds.\n", t2 - t1);
    printf("sum = %f\n", sum);
    printf("\n");

    return 0;
}