/*
    2017-12-04
    Problem:    Minimal Spanning Tree
    
    Algorithm:  1.Prim
                
                2.Kruskal
    
    Author:     Derrick

    Date:       2017-12-03
*/
#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define INF 100000

using namespace std;

typedef struct edge{
    int a,b;
    int w;
}Edge;

Edge e[10];
int root[6];
int getRoot(int v)
{
    while(v!=root[v])v=root[v];
    return v;
}

bool compare(Edge a,Edge b){

    return a.w<b.w;
}

int a[6][6]={{0,6,1,5,INF,INF},
             {6,0,5,INF,3,INF},
             {1,5,0,5,6,4},
             {5,INF,5,0,INF,2},
             {INF,3,6,INF,0,6},
             {INF,INF,4,2,6,0}};

void cnostuctEdge()
{
   int k=0;
   for(int i=0;i<6;i++)
   {
       for(int j=i;j<6;j++)
       {
           if(a[i][j]!=0&&a[i][j]!=INF)
           {
               e[k].a = i;
               e[k].b = j;
               e[k].w = a[i][j];
               k++;
           }
       }
   }
}



void prim(int start)
{
    int lowcost[6];
    int visited[6];
    int temp;
    int curr;
    memset(visited,0,sizeof(visited));

    for(int i=0;i<6;i++){
        lowcost[i] = a[start][i];
    }

    visited[start] = 1;

    curr = start;

    printf("%d\n",curr);

    for(int k=1;k<6;k++){
        int min=INF;
        //find adj of current point which is unvisited
        //above is misleading yourself
        for(int i=0;i<6;i++){
            if(min>lowcost[i]&&visited[i]!=1){
                    min = lowcost[i];
                    temp = i;
            }
        }
        visited[temp] = 1;
        curr = temp;
        printf("%d %d cost:%d\n",k,curr,min);
    
    //update mincost
    for(int i=0;i<6;i++){
        if(!visited[i]&&lowcost[i]>a[curr][i]){
            lowcost[i] = a[curr][i];
        }
    }
    }

}


void kruskal()
{
    int edgenum=10;
    int vertexnum=6;
    int sum=0;
    //sort by weight
    sort(e,e+10,compare);
    cout<<endl;
    for(int i=0;i<10;i++){
        cout<<e[i].w<<" "<<e[i].a<<" "<<e[i].b<<endl;
    }
    cout<<endl;
    for(int i=0;i<vertexnum;++i){
            root[i]=i;
            cout<<i<<"de root"<<root[i]<<endl;
    }

    for(int i=0;i<edgenum;++i){

        //获得一条边的两个顶点所在的集合
        int root1=getRoot(e[i].a);
        int root2=getRoot(e[i].b);
        if(root1!=root2){
            cout<<root[root1]<<" "<<root[root2]<<endl;
            root[root1]=root[root2];
            sum+=e[i].w;
             cout<<root[root1]<<" "<<root[root2];
        }
        cout<<endl;
    }

    cout<<"this is the root of all"<<endl;
    for(int i=0;i<6;i++){
        cout<<getRoot(i)<<endl;
    }
    cout<<"this is kruskal: "<<sum<<endl;
}

int main()
{
    prim(0);
    cnostuctEdge();
    kruskal();
    return 0;
}
