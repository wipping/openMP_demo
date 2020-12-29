#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

const int N = 32;

#pragma omp declare simd uniform(num) notinbranch
double aver(double a, double num)
{
    double c;
    c = (a + num) / 2.0;
    return c;
}

#pragma omp declare simd uniform(a) notinbranch
double add(double* a, int i, double* b)
{
    double c;
    c = a[i] + *b;
    return c;
}

int main()
{
    int i;
    double a[N], b[N], c[N], tmp;

    for(i = 0; i < N; i++)
    {
        a[i] = i;
        b[i] = N - i;
    }

    // #pragma omp simd private(tmp)
    for(i = 0; i <= N; i++)
    {
        tmp = aver(a[i], 1.0);
        c[i] = add(b, i, &tmp);
    }

    for(i = 0; i < N; i++)
    {
        printf("%d    %f    %f    %f\n", i, a[i], b[i], c[i]);
    }

    return 0;
}