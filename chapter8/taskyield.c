#include <stdio.h>
#include <omp.h>

int main()
{
    #pragma omp task
    {
        printf("task 1a\n");
        
        #pragma omp critical
        {
            printf("task 1b\n");
            #pragma omp task
            {
                printf("task 3\n");
            }
            #pragma omp taskyield
        }
    }

    #pragma omp task
    {
        #pragma omp critical
        {
            printf("task 2\n");
        }
    }
    return 0;
}