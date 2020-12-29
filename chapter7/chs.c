#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <omp.h>

double start, end, start0, end0, tsum;
int loop_times = 0, fun1_times = 0, fun2_times = 0;
double loop_cal = 0.0, fun1_cal = 0.0, fun2_cal = 0.0;

void func1(double x, double y, double z, int m)
{
    int i, j;

    start = omp_get_wtime();
    for(i = 1; i < m+1; i++)
    {
        for(j = 1; j < m+1; j++)
        {
            x = sin(x+sin(log((double)m)));
            y = cos(x+y-cos(log((double)i)));
            z = sin(x+y+z+cos(log(abs(x+y)+j)));
        }
    }
    end = omp_get_wtime();
    fun1_times = fun1_times + 1;
    fun1_cal = fun1_cal + end - start;

    printf("fun 1: x = %lf, y = %lf, z = %lf\n", x, y, z);
    return ;
}

void func2(double x, double y, double z, int m)
{
    int i, j;
    double u = 1.0, v = 2.0;

    func1(-x, y, z, m);

    start = omp_get_wtime();
    for(i = 1; i < m+1; i++)
    {
        for(j = 1; j < m+1; j++)
        {
            u = cos(x+sin(cos(log10(m))));
            v = exp(cos(u+sin(cos((double)m))));
            x = sin(x+v+sin(log((double)m)));
            y = cos(x+y-cos(log((double)i)));
            z = sin(x+y+z+cos(log(abs(x+y)+j)));
        }
    }

    end = omp_get_wtime();
    fun2_times = fun2_times + 1;
    fun2_cal = fun2_cal + end - start;

    printf("fun 2: x = %lf, y = %lf, z = %lf\n", x, y, z);
    return ;
}

int main()
{
    int i, j, k, m = 500;
    double x = 1.0, y = 2.0, z = 3.0;

    start0 = omp_get_wtime();

    start = omp_get_wtime();
    for(i = 1; i < m+1; i++)
    {
        for(j = 1; j < m+1; j++)
        {
            x = sin(x+sin(log((double)m)));
            y = cos(x+y-cos(log((double)i)));
            z = sin(x+y+z+cos(log(abs(x+y)+j)));
        }
    }
    end = omp_get_wtime();
    loop_cal = loop_cal + end - start;
    loop_times = loop_times + 1;

    func1(x, y, z, m);
    func2(x, y, z, m);

    printf("x = %lf, y= %lf, z = %lf\n", x, y, z);

    end0 = omp_get_wtime();
    tsum = end0 - start0;

    printf("--------hot spots analysis result---------\n");
    printf("Total calculatal time = %f seconds\n", tsum);
    printf("loop&func times cal_time(s) cal_time(%)\n");
    printf("   loop1   %ld   %E   %2f %\n", loop_times, loop_cal, loop_cal/tsum * 100);
    printf("   func1   %ld   %E   %2f %\n", fun1_times, fun1_cal, fun1_cal/tsum * 100);
    printf("   func2   %ld   %E   %2f %\n", fun2_times, fun2_cal, fun2_cal/tsum * 100);
    return 0;
}
