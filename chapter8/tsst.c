#include <stdio.h>
#include <omp.h>

int main()
{
    int k = 9;
    
    omp_set_num_threads(2);
    omp_set_dynamic(0);

    #pragma omp parallel shared(k)
    {
        #pragma omp sections firstprivate(k)
        {
            #pragma omp section
            {
                printf("task_%d: do task\n", omp_get_thread_num());
                #pragma omp task shared(k)
                {
                    #pragma omp critical
                    printf("in task: k = %d\n", k);
                }
                #pragma omp taskwait
            }
        }
    }
    printf("after parallel region, k = %d\n", k);
    return 0;
}