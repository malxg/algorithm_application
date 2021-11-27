/*
已知线性表中的元素以值递增有序排列，并以单链表作为存储结构。
现在删除表中所有值大于mink且小于maxk的元素，并释放。 
*/

#include <stdio.h>
#include "malloc.h"

typedef struct LNode{
	int data;
	struct LNode *next;
}LNode,*LinkList;//线性链表类型

//打印 单链表 元素 
void prin_Link(LinkList a);
//释放链表 
void free_link(LinkList a);
//构造一个单链表 
LNode * create_list();//返回头结点地址 
//删除范围外的结点，等于算在范围内  
void del_element(LinkList a,int mink,int maxk)
{
	LinkList p,q,pre = a;//pre 初始指向 头结点
	p = pre->next; 
	while(p != NULL)
	{
		if(p->data < mink || p->data > maxk)//找到在范围外 
		{
			//找到结点 开始删除
			pre->next = p->next;//剔除 要删除的 p指向的结点 
			//释放 p指向的结点 并恢复p指针 
			free(p);
			p = pre->next;//p始终保持前一个 结点有pre指针 
		}
		else//没有找到 继续向后遍历 
		{
			pre = p;
			p = p->next;
		} 
		
	}
	
	return;
} 
int main()//main* 
{
	LNode * a;//指向首结点的 指针 
	
	//构造单链表，并添加数据 
	a = create_list();//a接收 首结点 
	
	//查看构造结果
	prin_Link(a); 
	
	//删除 在mink < k < maxk 之外的元素 
	int mink = 0,maxk = 0;
	scanf("%d%d",&mink,&maxk);
	//开始删除
	del_element(a,mink,maxk);//参：表首地址,下线，上线 
	
	//查看删除后效果
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
