#include<stdio.h>
int main()
{
    int m,n;
    scanf("%d%d",&m,&n);
    char s[m*2+1][n*2+1];
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            s[i*2+1][j*2+1]='*';
            s[i*2][j*2+1]='-';
            s[i*2+1][j*2]='|';
            s[i*2][j*2]='+';
        }
       
    }

    for(int i=0;i<=m*2;i++){
        if(i%2==0)s[i][n*2]='+';
        else s[i][n*2]='|';
    }
     

    for(int i=0;i<n*2+1;i++)
    {
        if(i%2==0)s[m*2][i]='+';
        else s[m*2][i]='-';

    }

    for(int i=0;i<m*2+1;i++)
    {
        for(int j=0;j<n*2+1;j++)
        {
            printf("%c",s[i][j]);
        }
        printf("\n");
    }
    return 0;
}