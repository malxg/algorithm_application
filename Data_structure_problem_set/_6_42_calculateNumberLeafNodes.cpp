/*
编写递归算法，计算二叉树叶子结点的数目。 
*/

#include "stdio.h"//包含 getchar() scanf() printf() 
#include "malloc.h"//malloc()动态申请空间 函数
//二叉树 结点 
struct node{
	char data;
	struct node *lchild,*rchild;
}bnode;
typedef struct node * blink;

//计算二叉树叶子结点的数目 
//先序 建立 二叉数 
blink create_binary();
//释放二叉树 
void FreeTree(blink T);

//找叶子结点个数

//递归，先序遍历 树 同时统计叶子结点 
int count = 0;//叶子结点个数 
void preorder(blink a)
{
	
	//递归出口 
	if(a == NULL)
	{
		return;
	}
	//先序遍历树 
	printf("%c ",a->data);
	preorder(a->lchild);
	preorder(a->rchild);
	//统计叶子 结点 
	if(a->lchild == NULL && a->rchild == NULL)
	{
		count ++;
	}
	
	return;
}

//测试函数 
int main()
{
	blink T;
	//构建二叉树 
	T = create_binary();
	//先序遍历 树 同时用count统计叶子结点(count定义成全局变量)
	preorder(T);
	printf("\n");
	//打印count叶子结点的数量
	printf("The number of leaf nodes is %d \n",count);
	
	//释放二叉树 
	FreeTree(T);
	return 0;
}
//先序 建立 二叉数 
blink create_binary()
{
    blink bt;
    char ch;
    ch = getchar();
    if (ch == '#')
    {
        bt = NULL;
    }
    else
    {
        bt = (blink)malloc(sizeof(bnode));
        
        bt->data = ch;
        bt->lchild = NULL;
        bt->rchild = NULL;
        bt->lchild = create_binary();
        bt->rchild = create_binary();
        
    }
    
    /*   输入abc##d##ef##g## 
    
				    	a
				    b       e
				c     d   f    g
    */
    return bt;
}
//释放二叉树 
void FreeTree(blink T)
{
	if(T)
	{
		FreeTree(T->lchild);            //递归释放其左子树 
		FreeTree(T->rchild);           //递归释放其右子树 
		
		free(T);                      //释放根节点 
		T = NULL;                     //释放指向根节点的指针 
	}
	
	return;          

}
