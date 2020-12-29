#include <stdio.h>
#include <omp.h>

int main()
{
    int nthreads, tid;
    long int i, j;
    long int max = 100000;
    double starttime, endtime, time;
    double a, b, c;

    omp_set_num_threads(4);
    a = 0.0;
    b = 0.0;
    c = 0.0;

    #pragma omp parallel private(i, j) default(shared)
    {
        starttime = omp_get_wtime();
        #pragma omp for reduction(+:a) schedule(static)
        for(i = 1; i < max; i++){
            for(j = i; j < max; j++) {
                a = a + (double)(i+j)/(double)(i*j);
            }
        }
        endtime = omp_get_wtime();
        time = (endtime - starttime) * 1000.0;
        #pragma omp single
        printf("static schedule time = %f13.5 milleseconds, a = %f\n", time, a);

        starttime = omp_get_wtime();
        #pragma omp for reduction(+:b) schedule(dynamic)
        for(i = 1; i < max; i++) {
            for(j = i; j < max; j++) {
                b = b + (double)(i+j)/(double)(i*j);
            }
        }
        endtime = omp_get_wtime();
        time = (endtime - starttime) * 1000.0;
        #pragma omp single
        printf("dynamic schedule time = %f13.5 millesecond, b = %f\n", time, b);

        starttime = omp_get_wtime();
        #pragma omp for reduction(+:c) schedule(guided)
        for(i = 1; i < max; i++) {
            for(j = i; j < max; j++) {
                c = c + (double)(i+j)/(double)(i*j);
            }
        }
        endtime = omp_get_wtime();
        time = (endtime - starttime) * 1000.0;
        #pragma omp single
        printf("guided schedule time = %f13.5 millesecond, b = %f\n", time, c);
    }
    return 0;
}