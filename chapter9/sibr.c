#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <math.h>

#define N 45
int a[N], b[N], c[N];

#pragma omp declare simd inbranch
int fib(int n)
{
    if(n <= 2)
        return n;
    else
        return fib(n-1)+fib(n-2);
}

int main()
{
    for(int i = 0; i < N; i++)
    {
        b[i] = i;
    }

    #pragma omp for simd
    for(int i = 0; i < N; i++)
    {
        a[i] = fib(b[i]);
    }
    printf("a[%d] = %d\n", N-1, a[N-1]);
    
    return 0;
}