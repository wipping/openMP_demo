#include <omp.h>
#include <stdio.h>

int main()
{
    omp_set_num_threads(4);
    #pragma omp parallel
    {
        #pragma omp task
        printf("hello world from a thread id = %d\n", omp_get_thread_num());
    }
    return 0;
}