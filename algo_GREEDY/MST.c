/*
    Problem:    Minimal Spanning Tree
    
    Algorithm:  1.Prim
                
                2.Kruskal
    
    Author:     Derrick

    Date:       2017-12-03
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define INF 100000

int a[6][6]={{0,6,1,5,INF,INF},
             {6,0,5,INF,3,INF},
             {1,5,0,5,6,4},
             {5,INF,5,0,INF,2},
             {INF,3,6,INF,0,4},
             {INF,INF,4,2,6,0}
    };

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

int main()
{
    prim(0);

    return 0;
}