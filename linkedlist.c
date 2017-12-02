/*
	linkedlist
	date:2017-11-07
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct listNode* listPointer;

struct listNode
{
	char data[4];
	listPointer next;
};

void printList(struct listNode* n)
{
	while(n!=NULL)
	{
		//printf(" %c ",n->data);
		printf(" %p ",&n->data);
		printf(" %ld ",sizeof(struct listNode));
		printf(" %s ",n->data);
		n=n->next;
	}
	printf("\n");
}

void linkedlist_insert(listPointer* head,listPointer x,char c)
{
	listPointer newnode=NULL;
	newnode = (struct listNode*)malloc(sizeof(struct listNode));
	newnode->data[0]=c;
	if(*head!=NULL)
	{
		newnode->next = x->next;
		x->next=newnode;
	}
	else
	{
		newnode->next=NULL;
		*head=newnode;
	}
}

int main()
{	
	char a[]="abcde";
	listPointer head=NULL;
	listPointer node1=NULL;
	listPointer node2=NULL;
	listPointer test_null=NULL;
	head=(struct listNode*)malloc(sizeof(struct listNode));
	node1=(struct listNode*)malloc(sizeof(struct listNode));
	node2=(struct listNode*)malloc(sizeof(struct listNode));

	strcpy(head->data,"abc");
	head->next=node1;

	strcpy(node1->data,"def");
	node1->next=node2;

	strcpy(node2->data,"ghi");
	node2->next=NULL;

	printList(test_null);
	linkedlist_insert(&test_null,node1,'x');
	printList(test_null);

	return 0;
}