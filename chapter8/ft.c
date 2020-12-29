#include <stdio.h>
#include <omp.h>

int fib(int n)
{
    int fib_result;
    int i, j;
    if(n < 2){
        fib_result = n;
    }
    else{
        #pragma omp task shared(i) firstprivate(n)
        i = fib(n-1);

        #pragma omp task shared(j) firstprivate(n)
        j = fib(n-2);

        #pragma omp taskwait
        fib_result = i + j;
    }
    return (fib_result);

}

int main()
{
    int n = 16, result;
    omp_set_dynamic(0);
    omp_set_num_threads(4);
    #pragma omp parallel shared(n)
    {
        #pragma omp single
        {
            result = fib(n);
            printf("fib(%d) = %d\n", n, result);
        }
    }
    return 0;
}