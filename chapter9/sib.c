#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <math.h>

#define M 1000000

#pragma omp declare simd inbranch
int change(int *p)
{
    *p = *p + 10;
    return *p;
}

int myaddint(int* a, int* b, int n)
{
    #pragma omp simd
    for(int i = 0; i < n; i++)
    {
        if(b[i] > M/2){
            a[i] = change(&b[i]);
        }
    }
    return a[n-1];
}

int main()
{
    int a[M], b[M], i;
    double t1, t2;

    for(i = 0; i < M; i++)
    {
        a[i] = i;
        b[i] = i;
    }

    t1 = omp_get_wtime();
    myaddint(a, b, M);
    t2 = omp_get_wtime();
    printf("%d    %d    %d\n", M-1, a[M-1], b[M-1]);
    printf("Elapsed CPU time = %lf seconds.\n", t2 - t1);

    for(i = 0; i < M; i++)
    {
        a[i] = i;
        b[i] = i;
    }
    t1 = omp_get_wtime();
    for(i = 0; i < M; i++)
    {
        if(b[i] > M/2)
        {
            a[i] = b[i] + 10;
        }
    }
    t2 = omp_get_wtime();
    printf("%d    %d    %d\n", M-1, a[M-1], b[M-1]);
    printf("Elapsed CPU time = %lf seconds.\n", t2 - t1);
    return 0;
}