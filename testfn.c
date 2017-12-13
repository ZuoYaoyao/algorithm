#include<stdio.h>
#include<omp.h>

int main()
{
    #pragma omp parallel
        printf("in parallel %d\n",omp_in_parallel());
    printf("in parallel %d\n",omp_in_parallel());
    printf("max thread: %d\n",omp_get_max_threads());
    printf("max processor: %d\n",omp_get_num_procs());
    omp_set_dynamic(3);
    printf("adjust %d\n",omp_get_dynamic());
    printf("thread limit %d\n",omp_get_thread_limit());

    omp_set_num_threads(5);
    #pragma omp parallel for num_threads(12)
        for(int i=0;i<16;i++){
            printf("ID: %d Value:%d\n",omp_get_thread_num(),i);
        }
    return 0;
}