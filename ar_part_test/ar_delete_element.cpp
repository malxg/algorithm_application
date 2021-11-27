/*
试给出单链表类型定义，假定元素类型为整型，链表带有头结点，
编写函数实现对单链表中的指定元素值为e的结点删除操作，假定元素值为e的结点一定存在。
*/
#include <iostream>
#include <malloc.h>
#define size 10 
using namespace std;

typedef struct node{
	int e;
	struct node *next;
}node,*list;//style struct int e node *next


void create_single_list(list Head)//create linklist
{
	int i = size;//#define size 10
	node *q;
	q = (node*)malloc(sizeof(node));
	q->e = i --;
	q->next = NULL;
	
	Head->next = q;
	
	while( i > 0)
	{
		node *p;
		p = (node*)malloc(sizeof(node));
		p->e = i --;
		p->next = NULL;
		
		q->next = p;//链接 结点 
		q = p;

	}
	
	return;
}

void delete_element(node *Head,int data)//delete element
{
	list p = Head;
	node *q;
	for(int i = 0;i < size;i ++)
	{
		if(p->next->e == data)
		{
			q = p->next;//标记要 删除 的 结点，方便后面释放，一定在删除前，否则成僵尸结点 
			
			p->next = p->next->next;//把结点 从链表中删除 
			break;//结束循环 
		}
		else;
		
		p = p->next;
	}
	
	free(q);//释放 删除的结点 
	q = NULL;//注意free 释放后必须把无效指针 变为 空 
	return;
}

//print
void print_linklist_element(list Head)//printf
{
	node *p = Head->next;
	do
	{
		
		cout << p->e << " ";
		p = p->next;
		
	}while(p != NULL);
	
	cout << endl;
	
	return;
}

//main function
int main()
{
	node *Head;//头结点 
	Head->e = 0;//init zero
	Head->next = NULL;
	
	create_single_list(Head);//create link list
	print_linklist_element(Head);//print
	
	int e;
	cout << "delete value is :"; 
	cin >> e;
	
	delete_element(Head,e);//delete element
	
	print_linklist_element(Head);//print
	
	return 0;
}
