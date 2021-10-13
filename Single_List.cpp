#include <stdio.h>
#include <iostream>
#include <stdlib.h>>
#define Maxsize 10
using namespace std;

typedef struct LNode{
	int data;
	LNode * next;
}LNode,*LinkList; 

LNode *Create_Link(void)
{
	LinkList L;
	L = (LNode * )malloc(sizeof(LNode));
	LNode * p;
	L->next = NULL;
	int i  = 10;
	p = L;
	while(--i)
	{
		LNode * q;
		q = (LNode * )malloc(sizeof(LNode));
		q->data = i;
		q->next = NULL;
		p->next=q;
		p = q;
	}
	
	return L;
	
}

LNode * Back_LI(LinkList L,int i,int e)
{
	if(L == NULL)
	{
		printf("LinkList is NULL!");
		return NULL;
	}
	
	LNode * p;
	p = L;
	
	while(i --)
	{
		p = p -> next;
	}
	
	LNode * q;
	q = (LNode *)malloc(sizeof(LNode));
	if (q == NULL)
	{
		printf("malloc false");
		return NULL;
	}
	q->next = p->next;
	p->next = q;
	q->data = e;
	
	return L;
	
}

LNode * Front_LI(LinkList L,int i,int e)
{
	if(L == NULL)
	{
		printf("LinkList is NULL!");
		return NULL;
	}
	if(i < 1)
	{
		printf("i < 1,out of limit");
		return NULL;
	}
	LNode * p;
	p = L;
	i = i - 1;
	while( i --)
	{
		p = p -> next;
	}
	
	LNode * q;
	q = (LNode *)malloc(sizeof(LNode));
	if (q == NULL)
	{
		printf("malloc false");
		return NULL;
	}
	q->next = p->next;
	p->next = q;
	q->data = e;
	
	return L;
	
}

LNode * F_LI(LinkList L,int i,int e)
{
	if(L == NULL)
	{
		printf("LinkList is NULL!");
		return NULL;
	}
	if(i < 1)
	{
		printf("i < 1,out of limit");
		return NULL;
	}
	LNode * p;
	p = L;
	while( i --)
	{
		p = p -> next;
	}
	
	LNode * q;
	q = (LNode *)malloc(sizeof(LNode));
	if (q == NULL)
	{
		printf("malloc false");
		return NULL;
	}
	q->next = p->next;
	p->next = q;
	q->data = p->data;
	p->data = e;
	return L;
	
}

int main()
{
	LinkList L=NULL;
	L = Create_Link();
	LNode * q;
	L = Front_LI(L,3,99);
	L = Back_LI(L,3,99);
	
	L = F_LI(L,2,99);
	q = L;
	for(int i = 0;i < 20;i ++)
	{
		q = q->next;
		printf("%d\n",q->data);
		
	}
	return 0;
}
