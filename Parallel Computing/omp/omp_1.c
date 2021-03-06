//prog 5-1: helloworld

/*
    Compile:
        gcc -fopenmp omp1.c 
    Perfomance:
        gcc -pg 
        ./a.out
        gprof a.out

*/
#include<stdio.h>
#include<stdlib.h>
#include<omp.h>

void Hello();

int main(int argc,char* argv[])
{
    int thread_count = atoi(argv[1]);
    #pragma omp parallel num_threads(thread_count)
        Hello();
}

void Hello()
{
    int my_rank = omp_get_thread_num();
    int thread_count = omp_get_num_threads();

    printf("Hello from thread %d of %d\n",my_rank,thread_count);
}