#include <stdio.h>
#include <omp.h>

#define m (4*3)

int main()
{
    omp_set_num_threads(3);
    #pragma omp parallel for schedule(dynamic)
    for(int i = 0; i < m; i++)
    {
        printf("tid = %d, i = %d\n", omp_get_thread_num(), i);
    }
    return 0;
}