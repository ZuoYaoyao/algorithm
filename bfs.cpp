#include<stack>
#include<queue>
#include<cstdio>
using namespace std;

//Graph:1.adj

struct node{
    int data;
    struct node * next;
};

// list: struct node* list
// typedef struct node* linklist
// graph ajdacency matrix linklist* matrix
// struct node** matrix

void dfs()
{

}





void bfs()
{
    
}


















int main()
{
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    while(!s.empty())
    {
        printf("%d\n",s.top());
        s.pop();
    }
}