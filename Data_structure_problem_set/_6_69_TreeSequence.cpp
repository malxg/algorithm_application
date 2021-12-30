/*
以二叉链表存储的二叉树中，每个结点所含数据元素均为单单字母，按树状打印二叉树的算法。 
*/
//观察序列 可以发现树状序列 等于 中序遍历的 逆序, 实际实现 中序遍历的逆序 
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

//递归，中序遍历 树
//保存 中序结果
char mid[101] = {'\0'};
int count = 0;//序列大小 
void midorder(blink a)
{
	
	//递归出口 
	if(a == NULL)
	{
		return;
	}
	//中序遍历树 
	midorder(a->lchild);
	mid[count ++] = a->data;
	midorder(a->rchild);
	
	return;
}

//测试函数 
int main()
{
	blink T;
	//构建二叉树 
	T = create_binary();
	//先序遍历 树 同时用count统计叶子结点(count定义成全局变量)
	midorder(T);
	//逆序 输出 中序序列,即题目要求 
	for(int i = count - 1;i >= 0;i --)
	{
		printf("%c ",mid[i]);
	} 
	
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
    
    /*   输入abc##d##ef##g##  或 AB#D##CE#F### 
    
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
