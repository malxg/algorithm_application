/*
建立合法的表达式字符串只含二元操作符的非空表达式数
用二叉树遍历算法求该中缀表达式对应的后缀，前缀表达式
*/

#include "stdio.h"//包含 getchar() scanf() printf() 
#include "malloc.h"//malloc()动态申请空间 函数
//二叉树 结点 
struct node{
	char data;
	struct node *lchild,*rchild;
}bnode;

typedef struct node * blink;

//中缀 建立 二叉数 (这里 采用 括号 来识别 表达式 优先层级,最外层也需要加括号)
//递归实现
static int i = 0;//标记 数组中 下一个 要处理的 元素，静态变量 会继承上一次调用的值 
blink create_binary(char s[])
{
	
    char ch = s[i];//保存 本次 调用 要处理 的元素 
    
    //构建结点 
    blink bt;
	bt = (blink)malloc(sizeof(bnode));
    bt->data = '\0';
    bt->lchild = NULL;
    bt->rchild = NULL;
    
    //ch保存后，算作处理完毕 跳过 1中的左括号(不处理),或者跳过 2中的数据，无论那种 都得+1
    i ++; 
	
	//开始 真正处理 ch保存的元素 
    if(ch == '(')//如果ch保存的 元素 是'(' -----------1
    {	
    	bt->lchild = create_binary(s);//处理 操作符的左子树----左 
    	
		bt->data = s[i];//保存 操作符 为局部的 根 ----根 
    	i ++;//向后移动 处理下一个 元素 
    	
    	bt->rchild = create_binary(s);//处理 操作符的右子树---右 
		
		i ++;//处理完毕 跳过 结束的右括号(不处理) 
	}
	
	else//如果ch保存的 元素 是一个 值，直接赋值---------2 
	{
		bt->data = ch;
	} 
    
    /*   输入 ((4-5)*(1+2)) 
                        +
 					-      +
 				4      5  1   2
 	
				    	
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
	char s[50] = {'\0'};
	scanf("%s",s);//输入 中缀 表达式 
	//建树
	root = create_binary(s); 
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
