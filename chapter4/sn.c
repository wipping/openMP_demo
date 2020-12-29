#include <stdio.h>
#include <omp.h>

int main()
{
    omp_set_nested(1);
    omp_set_dynamic(0);

    printf("nested region(1 or 0): %d\n", omp_get_nested());

    #pragma omp parallel num_threads(2)
    {
        if(0 == omp_get_thread_num()) {
            omp_set_num_threads(4);
        }
        else {
            omp_set_num_threads(3);
        }
        #pragma omp master
        printf("* * * * * outer zone: active_levle = %d, team_size = %d\n", omp_get_active_level(), omp_get_team_size(omp_get_active_level()));
        printf("outer: thread_ID = %d, threads_in_team = %d\n", omp_get_thread_num(), omp_get_num_threads());
        #pragma omp parallel
        {
            #pragma omp master
            printf("-----inner zone: active_level = %d, team_size = %d\n", omp_get_active_level(), omp_get_team_size(omp_get_active_level()));
            printf("inner: thread_ID = %d, threads_in_team = %d\n", omp_get_thread_num(), omp_get_num_threads());    
        }
    }
    return 0;
}