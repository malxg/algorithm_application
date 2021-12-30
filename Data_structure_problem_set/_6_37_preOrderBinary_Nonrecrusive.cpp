/*
用栈的基本操作实现先序遍历的非递归形式的算法。 
*/

#include <stdio.h>
#include <malloc.h>//用来申请二叉树结点空间 
#include <stack>
using namespace std;//std空间 

typedef struct node{
	char data;
	struct node* lchild;
	struct node* rchild;
}node,*pnode;
//层序 建立 二叉数 
pnode add(pnode bt,char ch);
//先序 非递归,栈实现 
void preOrder(pnode root)//根结点 
{
	if(root == NULL)
	{
		printf("root is null!");
		return;
	}
	
	//初始 结构体 指针栈 
	stack<pnode> s;
	s.push(root);//根节点 的结构体指针入栈 
	
	//开始遍历 root 
	pnode p;//游标 
	while(!s.empty())//等价s.empty() == 0,s.empty()栈为空返回1，不为空返回0 
	{
		p = s.top();//p初始化为栈顶 元素(第一次为根结点)
		//按照先序顺序打印数值
		printf("%c ",p->data);//打印根节点 
		s.pop();//当前根 出栈
		//由于栈是先处理后入栈的，故右孩子先于左孩子入栈（即之后实现先处理左孩子） 
		if(p->rchild != NULL)//处理右孩子 
		{
			s.push(p->rchild);//若有，则右孩子入栈 
		}
		if(p->lchild != NULL)//处理左孩子 
		{
			s.push(p->lchild);//若有，则左孩子入栈 
		}
	}
	printf("\n");//Enter
	return;
}

int main()
{
	pnode root = NULL;
	char ch;
	//层序 建立 二叉数 
	//建树
	printf("以空格键 + 回车结束输入:\n");
	while(1)
	{
		ch = getchar();//输入 字符 getchar，它从标准输入里读取下一个字符，相当于getc(stdin)。
		if(ch == ' ')
		{
			break;
		}
		root = add(root,ch);// 开始建树
	}
	
	//先序 非递归,栈实现 
	preOrder(root);//参数 根结点 结构体指针 
	
	return 0;
}

//二叉排序 方式 建立 二叉数 
int size = sizeof(node);
pnode add(pnode bt,char ch)
{
	if(bt == NULL)
	{
		bt = (pnode)malloc(size);
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
	test_one输入 dbfaceg(类似二叉排序树 的层序 遍历 输入)
	              d
	           b     f
	         a  c  e  g
	*/
	return bt;
} 
