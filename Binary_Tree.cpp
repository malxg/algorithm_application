#include <stdio.h>
#include <iostream>
#include <stdlib.h>

using namespace std;
enum booled{fa,tr};

typedef struct ElemType{
	int value1;
	float value2;
}ElemType;

typedef struct TreeNode{
	ElemType data;
	struct TreeNode *ltree,*rtree;
}TreeNode,*Tree;

void init_BinaryTree(Tree &p)
{
	p = (TreeNode *)malloc(sizeof(TreeNode));
    p->data = {0,1.1};
    p->ltree = NULL;
    p->rtree = NULL;
	printf("init is true\n");
	return;
}

booled create_BinaryTree(Tree &p)
{
	
	TreeNode *q1,*q2;
	
	q1 = (TreeNode *)malloc(sizeof(TreeNode));
	q2 = (TreeNode *)malloc(sizeof(TreeNode));
	q1->data = {1,1.1};
	q2->data = {2,1.1};
	q2->ltree = q1->ltree = NULL;
	q2->rtree = q1->rtree = NULL;
	
	p->ltree = q1;
	p->rtree = q2;
	
	return tr;
}



int main()
{
	Tree p = NULL;
	init_BinaryTree(p);
	int x = create_BinaryTree(p);
	
	printf(" %d %.2f",p->ltree->data.value1,p->ltree->data.value2);
	
	return 0;
}
