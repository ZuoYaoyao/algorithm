#include<stdio.h>

int gcd(int a,int b)
{
    if(b==0)return a;
    else return gcd(b,a%b);
}

int main()
{
    int n;
    int count,a,b,res;
    scanf("%d",&n);
    while(n--)
    {
        
        scanf("%d%d%d",&count,&a,&b);
        int g=gcd(a,b);
        res=0;
        for(int i=1;i<=count;i++)
        {
            if(i%g==0)res++;
        }
        if(res%2==0)printf("suantou\n");
        else printf("huaye\n");
    }

    return 0;
}