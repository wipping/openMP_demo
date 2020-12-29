#include <omp.h>
#include <stdio.h>
#include <math.h>

/*
                        +------------------------------+
                        |                              |
                        |                              |   
                        |                              |
                        v                              v
                    (task1)                        (task6)
                        |
                +-------+-------+
                |       |       |
                |       |       |
                |       |       |
                v       v       v 
             (task2) (task3) (task5)
                        |
                        |
                        v
                     (task4)
*/

void pause_seconds(int i)
{
    double start_time, end_time, used_time, pause_time;

    pause_time = fabs(i);
    start_time = omp_get_wtime();
    used_time = -1.0;
    do
    {
        end_time = omp_get_wtime();
        used_time = end_time - start_time;
    }while(used_time < pause_time);
}

int main()
{
    omp_set_num_threads(4);
    #pragma omp parallel
    {
        #pragma omp single
        {
            #pragma omp task /* task 1 */
            {
                pause_seconds(5);
                printf("task 1 thread id = %d\n", omp_get_thread_num());

                #pragma omp task /* task 2 */
                {
                    pause_seconds(2);
                    printf("task 2 thread id = %d\n", omp_get_thread_num());
                }

                #pragma omp task /* task 3 */
                {
                    printf("task 3 thread id = %d\n", omp_get_thread_num());

                    #pragma omp task /* task 4 */
                    printf("task 4 thread id = %d\n", omp_get_thread_num());
                }

                #pragma omp task /* task 5 */
                {
                    pause_seconds(1);
                    printf("task 5 thread id = %d\n", omp_get_thread_num());
                }
            }
            #pragma omp taskwait

            #pragma omp task /* task 6 */
            printf("task 6 thread id = %d\n", omp_get_thread_num());
        }
    }
    return 0;
}