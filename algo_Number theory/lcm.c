#include<stdio.h>

int gcd(int a,int b)
{
    if(b==0)return a;
    else gcd(b,a%b);
}

int main(){
    int n;
    long long int a,b;
    long long int res;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%lld %lld",&a,&b);
        res=a*b/gcd(a,b);
        printf("%lld\n",res);
    }
    return 0;
}