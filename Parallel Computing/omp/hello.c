#include<omp.h>
#include<stdio.h>

int main()
{
    #pragma omp parallel
    {
        printf("hello omp!\n");
    }
}