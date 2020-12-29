#include <stdio.h>
#include <omp.h>

int main()
{
    long int i, sum, product;
    int x[10];
    omp_set_num_threads(3);

    sum = 0;
    product = 1;

    #pragma omp parallel for private(i) shared(x, sum, product)
    for(i = 0; i < 10; i++)
    {
        x[i] = i + 1;

        #pragma omp atomic
        sum = sum + x[i];

        #pragma omp atomic
        product = product * x[i];

        printf("x[%d] = %d, sum = %d, product = %d\n", i, x[i], sum, product);
    }
    
    printf("sum = %d product = %d\n", sum, product);
    return 0;
}