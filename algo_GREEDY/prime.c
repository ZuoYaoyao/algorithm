#include<stdio.h>

int prime(int n)
{
    int i;
    for (i = 2; i < n; i++)
        if(n%i == 0)return 0;
    return 1;
}
int main()
{
    int i, n;
    n = 100000;
    for (i = 2; i <= n; i++)
        if (prime(i))printf("%d\n", i);

    return 0;
}