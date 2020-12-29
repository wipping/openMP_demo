#include <stdio.h>
#include <omp.h>

int main()
{
    omp_set_num_threads(4);
    #pragma omp parallel
    {
        printf("A ");
        
        #pragma omp task
        printf("race(thread id = %d)\n", omp_get_thread_num());

        printf("car ");
    }
    return 0;
}