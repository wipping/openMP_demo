#include <stdio.h>
#include <omp.h>
int x;
#pragma omp threadprivate(x)
int main()
{
    int tid, a;

    omp_set_num_threads(4);
    tid = omp_get_thread_num();
    a = -1;
    x = -2;
    printf("* * * * * * 1st serial region * * * * * *\n");
    printf("a = %d, x = %d, id = %d\n", a, x, tid);
    printf("\n");

    printf("---1st parallel region---\n");
    #pragma omp parallel firstprivate(a) private(tid) copyin(x)
    {
        tid = omp_get_thread_num();
        printf("a = %d, x = %d, id = %d\n", a, x, tid);
        a = a + tid + 10;
        x = x + tid + 100;
        printf("a = %d, x = %d, a&x change, id = %d\n", a, x, tid);
        printf("\n");
    }
    
    tid = omp_get_thread_num();
    printf("* * * * * * 2nd serial region * * * * * *\n");
    printf("a = %d, x = %d, id = %d\n", a, x, tid);
    printf("\n");
    a = a + tid + 10;
    x = x + tid + 100;
    printf("a = %d, x = %d, a&x chagned, id = %d\n", a, x, tid);

    printf("\n");
    printf("---2nd parallel region---\n");
    #pragma omp parallel firstprivate(a) private(tid)
    {
        tid = omp_get_thread_num();
        printf("2nd parallel: a = %d, x = %d, id = %d\n", a, x, tid);
        printf("\n");
        #pragma omp single copyprivate(x, a)
        {
            printf("\n");
            printf("---2nd parallel region single block\n");
            tid = omp_get_thread_num();
            printf("a = %d, x = %d, id = %d\n", a, x, tid);
            a = a + tid + 10;
            x = x + tid + 100;
            printf("a = %d, x = %d, a&x chagned, id = %d\n", a, x, tid);
        }
        printf("---2nd parallel region after single\n");
        tid = omp_get_thread_num();
        printf("a = %d, x = %d, id = %d\n", a, x, tid);
    }
    printf("\n");
    printf("* * * * * * 3rd serial region * * * * * *\n");
    printf("a = %d, x = %d, id = %d\n", a, x, tid);
    return 0;

}