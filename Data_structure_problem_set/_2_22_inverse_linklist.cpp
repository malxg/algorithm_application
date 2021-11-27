/*
对单链表实现就地逆置 
*/
#include <stdio.h>
#include "malloc.h"

typedef struct LNode{
	int data;
	struct LNode *next;
}LNode,*LinkList;//线性链表类型

//逆置 
//先把头结点后一个结点i放在末尾，然后在之前末尾结点和当前末尾结点i之间插入结点如：1 2 3 4 -->2 3 4 1 --> 4 3 2 1 
void inverse(LinkList a)
{
	//注意有个 头结点这样就转化为 把第一个放在末尾知道，最后一个元素(标识)放到了头，形式上就逆置了
	LinkList head = a;//头结点
	LinkList p = head->next;
	//找到最后一个元素,并标识为p指向
	while(p->next != NULL)
	{
		p = p->next;
	}
	//把头结点后一个结点i放在末尾
 	LinkList q = head->next;
 	
 	head->next = q->next;//剔除头结点后一个结点 
 	q->next = NULL;//初始化这个被剔除结点
 	p->next = q;//链接到 末尾
 	LinkList tail = q;//tail指向插入点的后一个结点,p始终指向最开始的末尾结点4 
 	//开始进行剩余结点的逆置，插入到上述变为2 3 4 1则在4 1中插入首结点2为3 4 2 1然后4 2插入3为4 3 2 1逆置完成 
	while(1)//始终保持 在最初的尾结点p后插入结点 
	{
		//若q等于p了说明最后一个结点到了首结点,结束循环
		q = head->next;//初始化q指向当前 头结点后一个结点 
		if(q == p)//后一个结点 等于 最后一个结点 
		{
			break;//逆置完毕 退出 
		}
		//否则继续逆置
		head->next = q->next;//剔除当前 首结点(头结点后一个结点)
		q->next = tail;//首结点 指向插入点的后一个结点 
		p->next = q;   //前一个结点next指向该结点
		tail = q;//插入点下一个结点更新 
		
	}
 	
	return;
}

//打印 单链表 元素 
void prin_Link(LinkList a);
//释放链表 
void free_link(LinkList a);
//构造一个单链表 
LNode * create_list();//返回头结点地址 

int main()//main* 
{
	LNode * a;//指向首结点的 指针 
	
	//构造单链表，并添加数据 
	a = create_list();//a接收 首结点 
	
	//查看构造结果
	prin_Link(a); 
	
	//逆置 
	inverse(a);
	//查看逆置结果
	prin_Link(a); 
	
	//程序结束，释放链表 
	free_link(a);
	
	return 0;
}

//构造一个单链表 
LNode * create_list()
{
	LinkList a;
	LinkList q,p;
	int size = sizeof(LNode);//获取结点空间 
	a = (LinkList)malloc(size);//当作头结点 不保存数据,可以使删除算法统一 
	a->next = NULL;
	a->data = 0;
	 
	
	q = (LinkList)malloc(size);//当作头结点 不保存数据
	q->next = NULL;
	q->data = 3;
	a->next = q;//q这里作为第一个 有数据结点

	for(int i = 4;i < 13;i ++)
	{
		//初始一个结点 
		p = (LinkList)malloc(size);
		p->next = NULL;
		p->data = i;
		
		q->next= p;//q下一个结点指向新创建的p结点 
		q = p;   //q 移到p的位置 
		p = p->next;//p指向NULL 
	}
	return a;//返回 首结点 
} 

//打印 单链表 元素 
void prin_Link(LinkList a)
{
	LinkList p = a->next;
	
	while(p != NULL)
	{
		printf("%d ",p->data);
		p = p->next;
	}
	printf("\n");
	return;
}
//释放链表 
void free_link(LinkList a)
{
	LinkList p = a->next;
	while(p != NULL)
	{
		//从头结点后一个位置，开始释放 
		a->next = p->next;
		free(p);
		p = a->next;
	}
	
	//最后释放 头结点
	free(a); 
	a =NULL;//初始指针 
	return;
}
