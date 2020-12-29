#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <omp.h>

int main()
{
    printf("hello 1\n");
    #pragma omp parallel
    {
        printf("hi\n");
    }
    printf("hello 2\n");
    return 0;
}
