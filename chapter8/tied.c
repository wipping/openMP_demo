#include <stdio.h>
#include <omp.h>

#define LARGE_NUM 10000000
double a[LARGE_NUM];

void process(double x)
{
    printf("x = %d\n", x);
    return ;
}

int main()
{
    for(int i = 0; i < LARGE_NUM; i++){
        a[i] = i;
    }

    #pragma omp parallel
    {
        #pragma omp single
        {
            #pragma omp task untied
            {
                for(int i = 0; i < LARGE_NUM; i++){
                    #pragma omp task
                    process(a[i]);
                }
            }
        }
    }

    return 0;
}