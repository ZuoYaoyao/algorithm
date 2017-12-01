#include<cstdio>
#include<cstring>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    char a[1001];
    char b[1001];
    cin>>a;
    cin>>b;
    int res[1001][1001]={0};
    
    for(int i=1;i<=strlen(a);i++)
    {
        for(int j=1;j<=strlen(b);j++)
        {
            if(a[i]==b[j])res[i][j]=res[i-1][j-1]+1;
            else res[i][j]=max(res[i-1][j],res[i][j-1]);
        }
    }
    for(int i=1;i<=strlen(a);i++)
    {
        for(int j=1;j<=strlen(b);j++)
        {
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<strlen(a)<<endl;
    cout<<res[strlen(a)][strlen(b)]<<endl;
    return 0;
}