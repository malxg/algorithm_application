//Non recursive middle order

#include <iostream>
#define Maxsize 10
using namespace std;

typedef struct BitreeNode{
	int data;//data
	struct BitreeNode *ltree,*rtree;//right/left node
}BiTNode,*BiTree;

void readTree(BiTree T)//root node
{
	BiTree s[Maxsize],p = T;
	int top = 0;//follow node 
	
	//solve
	do
	{
		//所有 左结点 存入 树指针 数组 
		while(p != NULL)
		{
			s[top ++] = p;
			p = p->ltree;
		}
		
		//非 空树 
		if(top > 0)
		{
			p = s[top];
			cout << p->data << " ";
			p = p->rtree;
			cout << p->data << " ";//current right
            top --;
		} 
		
	}while(p != NULL && top != 0);
	
	return;
}

int main()
{
	return 0;
}
