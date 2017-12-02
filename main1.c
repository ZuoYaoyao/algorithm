#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

typedef struct node* listnode;

listnode init()
{
    listnode head;
    listnode *linknode;
    linknode =(listnode*) malloc(sizeof(listnode)*5);
    head = malloc(sizeof(listnode));
    for(int i=0;i<5;i++)
    {
         linknode[i]->data = i+1;
         if(i<4)linknode[i]->next = linknode[i+1];
    }
    linknode[4]->next=NULL;

    head->data = 0;
    head->next = linknode[0];
    return head;
}

int main()
{
    listnode head = init();
    listnode i = malloc(sizeof(listnode));
    for(i=head;i;i=i->next){
        printf("%d\n",i->data);
    }
    return 0;
}