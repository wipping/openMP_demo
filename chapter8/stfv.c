#include <stdio.h>
#include <omp.h>
#include <unistd.h>

int main()
{
    #pragma omp parallel
    {
        int x = 10;
        #pragma omp single
        {
            #pragma omp task firstprivate(x)//task 1
            {
                x++;
                sleep(3);
                printf("from task 1: x = %d\n", x);
            }
            #pragma omp taskwait

            #pragma omp task firstprivate(x)
            {
                x++;
                printf("from task 2: x = %d\n", x);
            }
        }
    }
    return 0;
}