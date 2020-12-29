#include <omp.h>
#include <stdio.h>

int main()
{
    omp_set_num_threads(3);
    #pragma omp parallel sections
    {
        #pragma omp section
        {
            #pragma omp task
            printf("task 1 from a thread id = %d\n", omp_get_thread_num());
        }

        #pragma omp section
        {
            #pragma omp task
            printf("task 2 from a thread id = %d\n", omp_get_thread_num());
        }

        #pragma omp section
        {
            #pragma omp task
            printf("task 3 from a thread id = %d\n", omp_get_thread_num());
        }
    }
    return 0;
}