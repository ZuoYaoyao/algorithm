#include<stdio.h>
#include<stdlib.h>

struct listnode{
    int data;
    struct listnode* next;
};

void addEdge();
void traverse();

int main()
{
    struct listnode* list= malloc(sizeof(struct listnode)*5);
    for(int i=0;i<5;i++)
    {
        list[i].data=i*5;
    }
    for(int i=0;i<4;i++)
    {
        list[i].next=&list[i+1];
    }
    list[4].next=NULL;

    struct listnode* i = malloc(sizeof(struct listnode));
    for(i=list;i;i=i->next){
        printf("%d\n",i->data);
    }
    return 0;
}
