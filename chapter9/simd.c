#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <math.h>

#define M 10000

int main()
{
    float a[M], b[M];
    double t1, t2;

    t1 = omp_get_wtime();
    #pragma omp SIMD
    for(int j = 0; j < M; j++)
    {
        for(int i = 0; i < M; i++)
        {
            a[i] = 2.71828 * i + j;
            b[i] = 2.71828 * i + j;
        }
    }
    t2 = omp_get_wtime();
    printf("Elapsed CPU time = %lf seconds.\n", t2 - t1);
    printf("simd: a[10] = %f, b[10] = %f\n", a[10], b[10]);
    printf("\n");


    t1 = omp_get_wtime();
    for(int j = 0; j < M; j++)
    {
        for(int i = 0; i < M; i++)
        {
            a[i] = 2.71828 * i + j;
            b[i] = 2.71828 * i + j;
        }
    }
    t2 = omp_get_wtime();
    printf("Elapsed CPU time = %lf seconds.\n", t2 - t1);
    printf("simd: a[10] = %f, b[10] = %f\n", a[10], b[10]);
    printf("\n");

    return 0;
}