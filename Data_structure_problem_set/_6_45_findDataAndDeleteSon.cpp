/*
对于一个二叉树中每一个结点值为x的结点，删去以它为根的子树并释放空间。 
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

//递归,查找目标值为x的结点 并删除其子树 
void find_dataFree(blink a,char x)
{
	
	//递归出口 
	if(a == NULL)
	{
		return;
	}
	//judgement
	if(a->data == x)
	{
		//删除该结点的子树，需保留该根节点 
		FreeTree(a->lchild);//找到 调用释放以该结点为根的全部结点
		FreeTree(a->rchild);
		a->lchild = a->rchild = NULL;//初始  防止出现非法指针 中序遍历时候报错 
		return;//已经释放了 子树 不用递归子树 
	}
	
	//递归 左右子树 
	find_dataFree(a->lchild,x);
	find_dataFree(a->rchild,x);
	
	
	
	return;
}
//测试函数 
    /*   如输入abc##d##ef##g## 
    
				    	a
				    b       e
				c     d   f    g
    */
int main()
{
	blink T;
	//构建二叉树 
	T = create_binary();
	midOrder(T);//查看构建结果
	printf("\n");
	char eat = '\0';//吃掉创建二叉树后的 回车符，避免影响x的定义(如果x不是字符型可以不用加)
	scanf("%c",&eat);
	
	
	printf("please,enter the data to delete: \n");
	char x = '\0';
	scanf("%c",&x);
	//删除指定 包含x元素结点 的左右子树 
	find_dataFree(T,x);
	//查看删除后结果
	midOrder(T);
	printf("\n");
	
	//处理完毕，释放所有树结点 
	FreeTree(T);
	T = NULL;//初始T指针的指向 
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
