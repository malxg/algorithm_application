#include <stdio.h>
#include <iostream>
using namespace std;


typedef struct ElemType{
	int value1;
}ElemType;

typedef struct ThreadNode{
	ElemType data;
	struct ThreadNode *lchild,*rchild;
	int ltag,rtag;
}ThreadNode,*ThreadTree;

ThreadNode *pre = NULL;

void visit(ThreadNode *q);

void InThread(ThreadTree T)
{
	if(T != NULL)
	{
		InThread(T->lchild);
		visit(T);
		InThread(T->rchild);
	}
}

void visit(ThreadNode *q)
{
	if(q->lchild == NULL)
	{
		q->lchild = pre;
		q->ltag = 1;
	}
	if(pre != NULL && pre->rchild == NULL)
	{
		pre->rchild = q;
		pre->rtag = 1;
	}
	pre = q;
	return;
}

void CreateInThread(ThreadTree T)
{
	pre = NULL;
	if(T != NULL)
	{
		InThread(T);
		if(pre->rchild == NULL)
		{
			pre->rtag = 1;
		}
	}
}
int main()
{
	return 0;
}
