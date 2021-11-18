/*
建立一个二叉树 并 
中序遍历二叉树
*/
#include "stdio.h"//包含 getchar() scanf() printf() 
#include "malloc.h"//malloc()动态申请空间 函数

//二叉树 结点 
struct node{
	char data;
	struct node *lchild,*rchild;
}bnode;

typedef struct node * blink;

//建立 二叉数 
blink add(blink bt,char ch)
{
	if(bt == NULL)
	{
		bt = (blink)malloc(sizeof(bnode));
		bt->data = ch;
		bt->lchild = bt->rchild = NULL;
	}
	//类似于 二叉排序数 的构建 过程,大于根结点 在左边否则右边 
	else
	{
		if(ch < bt->data)
		{
			bt->lchild = add(bt->lchild,ch);
		}
		else
		{
			bt->rchild = add(bt->rchild,ch);
		}
	}
	/*
	test_one输入 dbfaceg(按 层序 遍历 输入) 
	              d
	           b     f
	         a  c  e  g
	
	*/
	return bt;
} 

void inorder(blink bt)
{
	/*
	依照test_one
	结果 为 abcdefg(当然这里 也可以发现,中序遍历 二叉排序树实际是 递增序列) 
	*/
	
	if(bt != NULL)//中序 左根右 
	{
		inorder(bt->lchild); //左
		printf("%c",bt->data);//根
		inorder(bt->rchild); //右 
	}
	
	return;
}

int main()
{
	blink root = NULL;//根 结点
	int i = 0;
	char x = '\0';
	
	//建树 
	printf("以空格键 + 回车结束输入:\n");
	while(1)
	{
		x = getchar();//输入 字符 getchar，它从标准输入里读取下一个字符，相当于getc(stdin)。
		if(x == ' ')
		{
			break;
		}
		root = add(root,x);// 开始建树
	} 
	
	inorder(root);//中序遍历 
	printf("\n");
	
	return 0;
}
