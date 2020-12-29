#include <stdio.h>
#include <omp.h>

void print_task(int k)
{
    int tid, nthreads;
    tid = omp_get_thread_num();
    nthreads = omp_get_num_threads();
    printf("print task: nthreads = %d, thread id = %d, k = %d\n", nthreads, tid, k);
    return;
}

void foo(void)
{
    int tid, nthreads;
    tid = omp_get_thread_num();
    nthreads = omp_get_num_threads();
    printf("foo: nthreads = %d, thread id = %d\n", nthreads, tid);
    for(int i = 1; i < 3; i++){
        #pragma omp task firstprivate(i)
        print_task(i);
    }
    return;
}

int main()
{
    printf("orphan task\n");
    foo();

    printf("parallel region\n");
    #pragma omp parallel num_threads(4)
    {
        #pragma omp single
        foo();
    }
    return 0;
}