/*
后序遍历的非递归形式的算法。 
*/

#include <stdio.h>
#include <malloc.h>//用来申请二叉树结点空间 
#include <stack>
using namespace std;//std空间 

typedef struct node{
	char data;
	int flag;//结点是否入过栈 标识 ，初始为0 
	struct node* lchild;
	struct node* rchild;
}node,*pnode;
//层序 建立 二叉数 
pnode add(pnode bt,char ch);
//后序 非递归,栈实现 
void postOrder(pnode root)//根结点 
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
	pnode p = s.top();//游标p初始化为栈顶 元素(第一次为根结点)
	while(!s.empty())//等价s.empty() == 0,s.empty()栈为空返回1，不为空返回0 
	{
		//按照后序顺序打印数值
		//由于栈是先处理后入栈的，故右孩子先于左孩子入栈（即之后实现先处理左孩子） 
		if(p->rchild != NULL && p->rchild->flag == 0)//处理右孩子 
		{
			s.push(p->rchild);//若有 且 之前没有入过栈，则右孩子入栈 
			p->rchild->flag = 1;//入栈标识
		}
		if(p->lchild != NULL && p->lchild->flag == 0 )//处理左孩子 
		{
			s.push(p->lchild);//若有 且 之前没有入过栈，则左孩子入栈 
			p->lchild->flag = 1;//入栈标识
		}
		
		p = s.top();//p初始化为栈顶 元素
		//如果没有孩子，或者孩子都已经处理过，出栈 并 打印 
		if( (p->lchild == NULL && p->rchild == NULL) || (p->lchild->flag == 1 && p->rchild->flag == 1) )
		{
			printf("%c ",p->data);//打印此时栈顶结点
			s.pop();//并出栈 
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
	
	//后序 非递归,栈实现 
	postOrder(root);//参数 根结点 结构体指针 
	
	return 0;
}

//二叉排序 方式 建立 二叉数 
int size = sizeof(node);
pnode add(pnode bt,char ch)
{
	if(bt == NULL)
	{
		bt = (pnode)malloc(size);
		bt->data = ch;//赋值数据 
		bt->flag = 0;//初始标识 
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
