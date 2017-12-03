//一定要形成习惯，抽象的好处，不要因为一时的方便，而违反规定。

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<queue>

using namespace std;

struct node{
    int adjvex;
    struct node* next;
};

struct list{
    struct node* head;
};

struct graph{
    int vertex;
    struct list* array;
};

int visited[8];
queue<int> q;

struct graph* init(int v);
struct node* addnode(int adjvex);
void addEdge(struct graph* g,int src,int des);
void traverse(struct graph* g);
void dfs(struct graph* g,int start);
void bfs(struct graph* g,int start);

int main()
{
    //vertex number
    struct graph* g = init(8);
    //flag array
    memset(visited,0,sizeof(visited));
    //add edges
    addEdge(g, 0, 2);
    addEdge(g, 0, 1);
    addEdge(g, 1, 4);
    addEdge(g, 1, 3);
    addEdge(g, 2, 6);
    addEdge(g, 2, 5);
    addEdge(g, 7, 6);
    addEdge(g, 7, 5);
    addEdge(g, 7, 4);
    addEdge(g, 7, 3);
    
    traverse(g);
    dfs(g,0);

    //flag array
    memset(visited,0,sizeof(visited));
    bfs(g,0);
}

struct graph* init(int v)
{
    struct graph* g = (struct graph*)malloc(sizeof(struct graph));
    g->vertex = v;
    g->array = (struct list*)malloc(sizeof(struct list)*v);
    
    for(int i=0;i<v;i++)
        g->array[i].head = NULL;
    
    return g;
}

struct node* addnode(int adjvex)
{
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->adjvex = adjvex;
    newnode->next = NULL;
    return newnode;
}

void addEdge(struct graph* g,int src,int des)
{
    struct node* add = addnode(src);
    add->next = g->array[des].head;
    g->array[des].head = add;

    add = addnode(des);
    add->next = g->array[src].head;
    g->array[src].head = add;
    
    /*
    struct node* add = addnode(src);
    if(!g->array[des].head){
        g->array[des].head = add;
    }else{
        add->next = g->array[des].head->next;
        g->array[des].head->next = add;
    }
   
    add = addnode(des);

    if(!g->array[src].head){
        g->array[src].head = add;
    }else{
        add->next = g->array[src].head->next;
        g->array[src].head->next = add;
    }  
    */
}

//简单遍历
void traverse(struct graph* g)
{
    int v;
    for (v = 0; v < g->vertex; ++v)
    {
        struct node* pCrawl = g->array[v].head;
        printf("\n Adjacency list of vertex %d\n head ", v);
        while (pCrawl)
        {
            printf("-> %d", pCrawl->adjvex);
            pCrawl = pCrawl->next;
        }
        printf("\n");
    }
}


// 深度优先
void dfs(struct graph* g,int start)
{
    printf("\nthis is dfs\n");
    struct node* i;
    visited[start]=1;
    printf("%d\n",start);
    for(i=g->array[start].head;i;i=i->next){
        if(!visited[i->adjvex]){
            dfs(g,i->adjvex);
        }
    }
}

//广度优先
void bfs(struct graph* g,int start)
{
    printf("\nthis is bfs\n");
    struct node* i;
    int vis;
    q.push(start);
    visited[start]=1;
    while(!q.empty())
    {
        vis = q.front();
        printf("%d\n",vis);
        for(i=g->array[vis].head;i;i=i->next)
        {
            if(!visited[i->adjvex])
            {
                q.push(i->adjvex);
                visited[i->adjvex]=1;
            }
        }
        q.pop();
    }
}