#include <stdio.h>
#include <omp.h>

#define m 5

int main()
{
    int tid, i;
    omp_lock_t lock;

    omp_set_num_threads(3);
    omp_init_lock(&lock);
    
    #pragma omp parallel for private(tid, i) shared(lock)
    for(i = 0; i < m; i++)
    {
        tid = omp_get_thread_num();
        omp_set_lock(&lock);
        printf("thread_id = %d, i = %d\n", tid, i);
        omp_unset_lock(&lock);
    }

    omp_destroy_lock(&lock);
    return 0;
}