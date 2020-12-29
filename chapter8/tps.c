#include <omp.h>
#include <stdio.h>

int main()
{
    omp_set_num_threads(4);
    #pragma omp parallel
    {
        #pragma omp single
        {
            #pragma omp task
            printf("task 1 from a thread id = %d\n", omp_get_thread_num());

            #pragma omp task
            printf("task 2 from a thread id = %d\n", omp_get_thread_num());
        }
    }
    return 0;
}