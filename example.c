#include<stdio.h>
#include<omp.h>

/*Example1
void simple(int n, float *a, float *b)
{
    int i;

    #pragma omp parallel for
        for(i=1; i<n; i++)  //i is private by default
        {
            b[i] = a[i]+a[i-1]/2.0;
            printf("%d %f\n",omp_get_thread_num(),b[i]);
        }
            
}

int main()
{
    //int a[5]={1,2,3,4,5};
    float a[10]={6,7,8,9,10,1,2,3,4,5};
    float b[10];

    simple(10,a,b);
    printf("\n");
    for(int i=0;i<10;i++)
    {
        printf("%f\n",b[i]);
    }
}

Output:
0 10.000000
0 11.500000
0 13.000000
1 14.500000
1 6.000000
2 2.500000
2 4.000000
3 5.500000
3 7.000000

0.000000
10.000000
11.500000
13.000000
14.500000
6.000000
2.500000
4.000000
5.500000
7.000000
*/

int main(){
    int x;
    x = 2;
    #pragma omp parallel num_threads(12) shared(x)
    {
        if (omp_get_thread_num() == 0) 
        {
            x = 5;
        } 
        else 
        {
            /* Print 1: the following read of x has a race */
            printf("1: Thread# %d: x = %d\n", omp_get_thread_num(),x );
        }
    //#pragma omp barrier
        if (omp_get_thread_num() == 0) {
        /* Print 2 */
        printf("2: Thread# %d: x = %d\n", omp_get_thread_num(),x );
        } else {
        /* Print 3 */
        printf("3: Thread# %d: x = %d\n", omp_get_thread_num(),x );
        }
    }
return 0;

}
