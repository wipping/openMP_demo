#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <omp.h>

int main()
{
    int i, j, k, nthreads, n_running_threads, num_steps;
    double x, tsum, sum, step, start_time, end_time, used_time;

    nthreads = 4;
    num_steps = 500;
    start_time = omp_get_wtime();
    omp_set_num_threads(nthreads);
    step = 1.0 / num_steps;
    sum = 0.0;

#pragma omp parallel private(x, i) default(shared)
{
    n_running_threads = omp_get_num_threads();
    #pragma omp for reduction(+:sum)
    for(i = 0; i < num_steps; i++)
    {
        for(j = 0; j < num_steps; j++)
        {
            for(k = 0; k < num_steps; k++)
            {
                x = (i + j + k + 0.5) * step;
                sum = sum + sin(tan(log(abs(sin(cos(x+20.0)+2.0)+3.0)+4.0)));
            }
        }
    }
}
    tsum = step * sum;
    end_time = omp_get_wtime();
    used_time = end_time - start_time;
    printf("used_time = %lf second\n", used_time);
    printf("nthreads = %d num_steps = %d\n", n_running_threads, num_steps);
    printf("tsum = %lf\n", tsum);
    return 0;
}
