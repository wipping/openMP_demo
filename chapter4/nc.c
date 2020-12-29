#include <stdio.h>
#include <omp.h>

#define m 5
#define n 4

int main()
{
    int array1[m], array2[n];

    omp_set_nested(1);
    omp_set_dynamic(0);

    #pragma omp parallel sections shared(array1, array2) num_threads(3)
    {
        #pragma omp section
        {
            printf("* * * * * outer section1: active_level = %d, team_size = %d, id = %d, threads_in_team = %d\n",
                  omp_get_active_level(), omp_get_team_size(omp_get_active_level()), omp_get_thread_num(), omp_get_num_threads());
            #pragma omp parallel for shared(array1) num_threads(3)
            for(int i = 0; i < m; i++)
            {
                array1[i] = i;
                printf("-----inner section1: i = %d active_level = %d, team_size = %d, id = %d, threads_in_team = %d\n", i, 
                    omp_get_active_level(), omp_get_team_size(omp_get_active_level()), omp_get_thread_num(), omp_get_num_threads());
            }                  
        }

        #pragma omp section
        {
            printf("* * * * * outer section2: active_level = %d, team_size = %d, id = %d, threads_in_team = %d\n", 
                omp_get_active_level(), omp_get_team_size(omp_get_active_level()), omp_get_thread_num(), omp_get_num_threads());
            #pragma omp parallel for shared(array2) num_threads(2)
            for(int j = 0; j < n; j++)
            {
                array2[j] = j;
                printf("-----inner section2: j = %d, active_level = %d, team_size = %d, id = %d, threads_in_team = %d\n", j, 
                       omp_get_active_level(), omp_get_team_size(omp_get_active_level()), omp_get_thread_num(), omp_get_num_threads());
            }
        }
    }
    return 0;
}