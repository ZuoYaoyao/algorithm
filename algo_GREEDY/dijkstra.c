#include<stdio.h>
#include<string.h>
#define INF 0x7fffffff
#define G_SIZE 20

int n;
int Edge[G_SIZE][G_SIZE];
int S[G_SIZE];
int dist[G_SIZE];
int path[G_SIZE];

void Dijkstra(int v0)
{
    int i,j,k;
    //init
    for(i=0;i<n;i++)
    {
        dist[i]=Edge[v0][i];
        S[i]=0;
        if(i!=v0&&dist[i]<INF)
            path[i]=v0;
        else
            path[i]=-1;
    }

    S[v0]=1;dist[v0]=0;

    for(i=0;i<n-1;++i)
    {
        int min =INF,u=v0;
        
        //find x V-S && dist[x] is min in the V-S
        for(j=0;j<n;++j)
        {
            if(!S[j]&&dist[j]<min)
            {
                u=j;
                min=dist[j];
            }
        }

        S[u]=1;

        //update
        for(k=0;k<n;k++)
        {
            if(!S[k]&&Edge[u][k]<INF&&dist[u]+Edge[u][k]<dist[k])
            {
                dist[k]=dist[u]+Edge[u][k];
                path[k]=u;
            }
        }
    }

    for(i=0;i<n;++i)printf("%d\n",dist[i]);
}

int main()
{   
    /*
    int a[5][5]={{0,10,INF,30,100},
                 {INF,0,50,INF,INF},
                 {INF,INF,0,INF,10},
                 {INF,INF,20,0,60},
                 {INF,INF,INF,INF,0}};
    */
    int a[5][5]={{0,3,INF,7,INF},
    {3,0,4,2,INF},
    {INF,4,0,5,6},
    {7,2,5,0,4},
    {INF,INF,6,4,0}};

    n=5;
    for(int hor=0;hor<n;hor++)
    {
        for(int ver=0;ver<n;ver++)
        {
            Edge[hor][ver]=a[hor][ver];
        }
    }
    Dijkstra(0);
    return 0;
}