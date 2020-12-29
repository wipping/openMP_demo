#include <stdio.h>
#include <omp.h>

static omp_lock_t lock;

int main()
{
    int tid, i = 0;

    omp_set_num_threads(3);
    omp_init_lock(&lock);
    omp_set_lock(&lock);
    #pragma omp parallel firstprivate(i, tid) shared(lock)
    {
        #pragma omp master
        {
            i = i + 1;
            tid = omp_get_thread_num();
            omp_unset_lock(&lock);
            printf("thread = %d, id = %d\n", tid, i);
        }
    }
    omp_destroy_lock(&lock);
    return 0;
}