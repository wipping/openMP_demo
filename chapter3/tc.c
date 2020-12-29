#include <stdio.h>
#include <omp.h>
int x = 0;
int y = 0;

#pragma omp threadprivate(x)
int main ()
{
    int tid, a;

    omp_set_num_threads(4);
    tid = omp_get_thread_num();
    a = -1;
    x = -1;
    y = -1;
    printf("* * * * * *1st serial region\n");
    printf("a = %d, x = %d, y = %d, id = %d\n", a, x, y, tid);
    printf("\n");
    printf("--- 1st parallel region---\n");
    #pragma omp parallel private(a, tid)
    {
        tid = omp_get_thread_num();
        printf("a = %d, x = %d, y = %d, id = %d\n", a, x, y, tid);
        a = a + tid + 10;
        x = x + tid + 10;
        y = y + tid + 10;
        printf("a = %d, x = %d, y = %d, id = %d change\n", a, x, y, tid);
    }

    tid = omp_get_thread_num();
    printf("\n");
    printf("* * *2nd serial region\n");
    printf("a = %d, x = %d, y = %d, id = %d\n", a, x, y, tid);
    a = a + tid + 10;
    x = x + tid + 10;
    y = y + tid + 10;
    printf("a = %d, x = %d, y = %d, id = %d change\n", a, x, y, tid);
    printf("\n");
    printf("--- 2nd parallel region---\n");

    #pragma omp parallel private(tid)
    {
        tid = omp_get_thread_num();
        printf("a = %d, x = %d, y = %d, id = %d\n", a, x, y, tid);
        a = a + tid + 10;
        x = x + tid + 10;
        y = y + tid + 10;
        printf("a = %d, x = %d, y = %d, id = %d change\n", a, x, y, tid);
        printf("\n");
    }
    printf("* * *3rd serial region\n");
    printf("a = %d, x = %d, y = %d, id = %d\n", a, x, y, tid);
    return 0;
}