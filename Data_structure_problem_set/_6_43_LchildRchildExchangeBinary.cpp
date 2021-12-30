/*
将二叉树中所有结点的左右子树相互交换。 
*/

#include "stdio.h"//包含 getchar() scanf() printf() 
#include "malloc.h"//malloc()动态申请空间 函数
//二叉树 结点 
struct node{
	char data;
	struct node *lchild,*rchild;
}bnode;
typedef struct node * blink;

//先序 建立 二叉数 
blink create_binary();
//递归 中 序遍历 树
void midOrder(blink a);
//释放二叉树 
void FreeTree(blink T);

//递归,交换左右子树 
void exchage(blink a)
{
	
	//递归出口 
	if(a == NULL)
	{
		return;
	}
	//递归 左右子树 
	exchage(a->lchild);
	exchage(a->rchild);
	//交换当前 左右子树
	blink t = NULL;
	t = a->lchild; 
	a->lchild = a->rchild;
	a->rchild = t;
	
	return;
}
/*
输入abc##d##ef##g## 
    
				    	a         -->交换后       a 
				    b       e                  e     b
				c     d   f    g             g   f  d  c
*/
//测试函数 
int main()
{
	blink T;
	//构建二叉树 
	T = create_binary();
	midOrder(T);//查看构建结果
	printf("\n");
	//交换左右子树 
	exchage(T);
	//查看交换后结果
	midOrder(T); 
	printf("\n");
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

//递归 中 序遍历 树
void midOrder(blink a)
{
	
	//递归出口 
	if(a == NULL)
	{
		return;
	}
	//先序遍历树 
	
	midOrder(a->lchild);
	printf("%c ",a->data);
	midOrder(a->rchild);
	
	return;
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
