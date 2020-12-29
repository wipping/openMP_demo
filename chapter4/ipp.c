#include <stdio.h>
#include <omp.h>

void printnumthreads(int n)
{
    int nthreads;
    

    #pragma omp parallel private(nthreads) if(n > 10) num_threads(4)
    {
        nthreads = omp_get_num_threads();
        printf("number of threads = %d, n = %d\n", nthreads, n);
    }
    return;
}

int main()
{
    printnumthreads(2);
    printf("\n");
    printnumthreads(20);
    return 0;
}