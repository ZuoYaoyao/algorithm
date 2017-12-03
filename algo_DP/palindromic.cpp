#include<cstdio>
#include<cstring>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;
int length[3001][3001]={0};
int main()
{
   
    char s[3001];
    cin>>s;

    int size=strlen(s);
    for(int i=0;i<size;i++)
        length[i][i]=1;

    for(int k=1;k<size;k++)
        for(int i=0;i<size;i++)
                {
                    int j=i+k;
                    if(s[i]==s[j]&&k==1){
                        length[i][j]=2;
                    }
                    else if(s[i]==s[j]){
                        length[i][j]=length[i+1][j-1]+2;
                        
                    }
                    else {
                        length[i][j]=max(length[i+1][j],length[i][j-1]);
                        
                    }
                   
                }

    cout<<size-length[0][size-1]<<endl;
    /*for(int i=0;i<size;i++){
         for(int j=0;j<size;j++){
                    cout<<length[i][j]<<" ";
                }
        cout<<endl;
    }
    */
    return 0;

}