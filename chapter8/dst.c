#include <omp.h>
#include <stdio.h>
#include <unistd.h>

int main()
{
    int a, b, c;

    #pragma omp parallel
    {
        #pragma omp master
        {
            #pragma omp task depend(out:a)
            {
                #pragma omp critical
                printf("task 1\n");
            }

            #pragma omp task depend(out:b)
            {
                #pragma omp critical
                printf("task 2\n");                
            }

            #pragma omp task depend(in:a) depend(out:c)
            {
                #pragma omp critical
                printf("task 3\n");
            }

            #pragma omp task depend(in:b)
            {
                printf("task 4\n");
            }
        }

        // if(1 == omp_get_thread_num())
        //     sleep(1);
    }
    return 0;
}