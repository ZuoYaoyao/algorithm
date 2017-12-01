#include<stdio.h>
#include<string.h>



long long int fib(int n,int m)
{
  /* Declare an array to store Fibonacci numbers. */
  long long int f[n+1];
  int i;
 
  /* 0th and 1st number of the series are 0 and 1*/
  f[0] = 0%m;
  f[1] = 1%m;
 
  for (i = 2; i <= n; i++)
  {
      /* Add the previous 2 numbers in the series
         and store it */
      f[i] = (f[i-1] + f[i-2])%m;
  }
 
  return f[n];
}

int main(){
    int n,m;
    scanf("%d",&n);
    scanf("%d",&m);
    printf("%lld\n",fib(n,m));
    return 0;
}