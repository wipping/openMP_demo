#include <stdio.h>
#include <omp.h>

int main()
{
    #pragma omp parallel
    {
        #pragma omp single
        {
            #pragma omp taskgroup
            {
                printf("Northeastern University");

                #pragma omp task
                {
                    printf(" is");

                    #pragma omp task
                    printf(" a beautiful university");
                }
            }
            printf(" in China!");
        }
    }
    printf("\n");
    return 0;
}