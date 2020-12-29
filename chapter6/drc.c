#include <omp.h>
#include <stdio.h>

int main()
{
    int x;
    x = 0;

    omp_set_num_threads(8);
    #pragma omp parallel shared(x)
    {
        #pragma omp critical(critical_plus)
        x = x + 1;
    }

    printf("x = %d\n", x);
    return 0;
}