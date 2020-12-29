#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <omp.h>

#define m 10000

int main()
{
    int i, j;
    double start_time, end_time, used_time, tick, x;

    omp_set_num_threads(2);

    start_time = omp_get_wtime();
    printf("start_time = %e secondes.\n", start_time);
    
    x = 0;
    #pragma omp parallel for private(i, j) lastprivate(x)
    for(i = 1; i < m+1; i++)
    {
        for(j = 1; j < m+1; j++)
        {
            x = x + log(pow(2.71828, (pow(sin(pow(1.1, 1.1)), 1.1) + 1.0))+1.0);
        }
    }

    end_time = omp_get_wtime();
    printf("end_time = %e seconds.\n", end_time);
    used_time = end_time - start_time;
    printf("used_time = %e seconds.\n", used_time);
    printf("x = %e\n", x);

    printf("\n");
    tick = omp_get_wtick();
    printf("tick = %e seconds.\n", tick);
    return 0;
}