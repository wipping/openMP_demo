#include <stdio.h>
#include <omp.h>

#if 0
int main()
{
    int data = 0, flag = 0;
    #pragma omp parallel sections num_threads(2) shared(data, flag)
    {
        #pragma omp section
        {
            #pragma omp critical
            printf("tid = %d data = %d\n", omp_get_thread_num(), data);

            for(int i = 0; i < 10000; i++){
                data++;
            }
            
            flag = 1;
        }

        #pragma omp section
        {
            while (!flag);
            #pragma omp critical
            printf("tid = %d data = %d\n", omp_get_thread_num(), data);

            data--;
            printf("tid = %d data = %d\n", omp_get_thread_num(), data);
        }
    }
    return 0;
}
#else
int main()
{
    int data = 0, flag = 0;
    int count = 10000;
    #pragma omp parallel sections num_threads(2) shared(data, flag) firstprivate(count)
    {
        #pragma omp section
        {
            #pragma omp critical
            printf("tid = %d data = %d\n", omp_get_thread_num(), data);

            for(int i = 0; i < count; i++){
                data++;
            }
            
            flag = 1;
            #pragma omp flush(flag)
        }

        #pragma omp section
        {
            while (!flag){
                #pragma omp flush(flag)
            }
            #pragma omp critical
            printf("tid = %d data = %d\n", omp_get_thread_num(), data);

            data--;
            printf("tid = %d data = %d\n", omp_get_thread_num(), data);
        }
    }
    return 0;
}
#endif