#include <stdio.h>
#include <omp.h>

int main()
{
    #pragma omp parallel
    {
        #pragma omp single
        {
            printf("Northeastern University");
            #pragma omp task
            {
                printf(" is");

                #pragma omp task
                printf(" a beautiful university");
            }
            #pragma omp taskwait
            printf(" in China!");
        }
    }
    printf("\n");
    return 0;
}