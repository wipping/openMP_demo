#include <stdio.h>
#include <omp.h>

#define l 4
#define m 4
#define n 2

int main()
{
    int tid, i, j, k, counter;
    omp_set_num_threads(3);

    counter = 0;
    #pragma omp parallel for collapse(2) private(i, j, k, tid) firstprivate(counter)
    for(i = 1; i <= l; i++) {
        for(j = 1; j <= m; j++) {
            for(k = 1; k <= n; k++){
                tid = omp_get_thread_num();
                counter = counter + 1;
                printf("tid = %d, counter = %d, i = %d, j = %d, k = %d\n", tid, counter, i, j, k);
            }
        }
    }
    return 0;
}
