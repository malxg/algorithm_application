/*
由先缀表达式建立二叉树，
求该 表达式对应的后缀，中缀表达式
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
    
    /*   输入*-4##5##+1##2## 
    
				    	*
				    -       +
				4     5   1    2
    */
    return bt;
}

//中序 遍历  中序 注意要 加括号，前缀表达式 后缀 表达式 必须 意思一致 
void inorder(blink bt)
{
	/*
	依照test_one
	结果 为 abcdefg(当然这里 也可以发现,中序遍历 二叉排序树实际是 递增序列) 
	*/
	
	if(bt != NULL)//中序 左根右 
	{
		printf("(");
		inorder(bt->lchild); //左
		printf("%c",bt->data);//根
		inorder(bt->rchild); //右 
		printf(")");
	}
	
	return;
}

//先序遍历 
void preorder(blink bt)
{
	/*
	依照test_one
	*/
	
	if(bt != NULL)//中序 左根右 
	{
		printf("%c",bt->data);//根
		preorder(bt->lchild); //左
		preorder(bt->rchild); //右
		
	}
	
	return;
}

//后序遍历 
void postorder(blink bt)
{
	/*
	依照test_one
	*/
	
	if(bt != NULL)//中序 左根右 
	{
		postorder(bt->lchild); //左
		postorder(bt->rchild); //右
		printf("%c",bt->data);//根
	}
	
	return;
}



blink FreeTree(blink T)
{
	if(T)
	{
		FreeTree(T->lchild);            //递归释放其左子树 
		FreeTree(T->rchild);           //递归释放其右子树 
		
		free(T);                      //释放根节点 
		T = NULL;                     //释放指向根节点的指针 
	}
	
	return T;           //返回释放后的根节点NULL 

}

int main()
{
	blink root = NULL;//根 结点

	//建树
	root = create_binary(); 
	//遍历 
	printf("\n先 中 后序遍历  二叉树\n");
	preorder(root);//先序遍历  二叉树 
	printf("\n");
	inorder(root);//中序遍历  二叉树 
	printf("\n");
	postorder(root);//后序 遍历 二叉树 
	
	printf("\n");
	free(FreeTree(root));//释放 空间
	 
	return 0;
}
