#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#define Maxsize 10
using namespace std;
typedef struct LinkNode{
	int data;
	struct LinkNode *next;
}LinkNode; 

typedef struct{
	LinkNode *front,*rear;
}LinkQueue;

void Link_init(LinkQueue &p)
{
	p.front = p.rear = (LinkNode *)malloc(sizeof(LinkNode));
	p.front->next =  NULL;
}

void EnQueue(LinkQueue &p,int e)
{
	LinkNode *s;
	s = (LinkNode *)malloc(sizeof(LinkNode));
		
	p.rear->next = s;
	s->next = NULL;
	s->data = e;
	p.rear = s;

}

void DeQueue(LinkQueue &p,int &e)
{
	if(p.front == p.rear)
	{
		printf("Queue is empty!");
		exit(-1);
	}
	e = p.front->next->data;
	LinkNode *L = p.front->next;
	p.front->next = L->next;
	free(L);
}

void display (LinkQueue q) 
{
	if (q.front == q.rear) 
	{
		cout<<"it is an empty queue!"<<endl;
		return;
	} 
	else 
	{
		LinkNode *temp = q.front;
		while (temp->next) 
		{
			cout<<"display element"<<temp->next->data;
			temp = temp->next;
		}
		cout<<endl;
	}
}


int main()
{
	LinkQueue L;
	int e;
	Link_init(L);
	EnQueue(L,3);
	EnQueue(L,99);
	DeQueue(L,e);
	printf("delete element is %d\n",e);
	display(L);
	return 0;
}
