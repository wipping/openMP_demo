#include <stdio.h>
#include <omp.h>
void work()
{
    int i = 100;
    #pragma omp task shared(i)
    {
        #pragma omp critical
        printf("in task: i = %d\n", i);
    }
    #pragma omp taskwait
    return;
}

int main()
{
    omp_set_num_threads(4);
    omp_set_dynamic(0);

    #pragma omp parallel
    {
        work();
    }
    return 0;
}