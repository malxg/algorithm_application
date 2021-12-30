/*
以孩子-兄弟链表为树的存储结构，按凹入表方式打印一颗树的算法。 
*/

/*如有树 按孩子兄弟法转化 
					   A        -->孩子兄弟表示法   A 
				 B     C     D                    B
		       E   F   G                        E    C
		                                         F  G  D
//观察序列 可以发现对原树进行 凹入表方式打印 等于 先序遍历孩子兄弟法后的树, 实际实现 孩子兄弟的先序遍历 
*///如按先序构建树时 输入ABE#F##CG##D### 则按先序再输出ABEFCGD 
#include "stdio.h"//包含 getchar() scanf() printf() 
#include "malloc.h"//malloc()动态申请空间 函数

//二叉树 结点 孩子-兄弟表示 法 
struct node{
	char data;
	struct node *lchild,*rchild;//左指针指向 长子，右指针指向 右边兄弟 
}bnode;
typedef struct node * blink;

//计算二叉树叶子结点的数目 
//先序 建立 二叉数 
blink create_binary();
//释放二叉树 
void FreeTree(blink T);

//找叶子结点个数

//递归，先序遍历 孩子兄弟结构 
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
