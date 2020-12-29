#include <stdio.h>
#include <omp.h>

int itmp;
#pragma omp threadprivate(itmp)
int var;

void work(void)
{
    printf("thread_%d: enter work\n", omp_get_thread_num());
    #pragma omp task
    {
        printf("thread_%d: do task1\n", omp_get_thread_num());
        #pragma omp task
        {
            printf("thread_%d: do task2\n", omp_get_thread_num());
            itmp = 1;
            #pragma omp task
            {
                printf("thread_%d: do task3\n", omp_get_thread_num());
            }
            var = itmp;
        }
        itmp = 2;
    }
}

int main()
{
    omp_set_num_threads(2);
    omp_set_dynamic(0);

    #pragma omp parallel
    {
        work();
    }

    #pragma omp parallel
    {
        printf("thread_%d: itmp = %d\n", omp_get_thread_num(), itmp);
    }

    printf("var = %d\n", var);
    return 0;
}