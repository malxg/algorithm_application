/*
用 线性表 和 单链表 的 存储 结构，来实现 线性表的 转置 
将线性表（a0,a1,a2,......,an-1）就地逆置
即辅助 空间 O(1) 
*/

#include <stdio.h>
#include <malloc.h>
//单链表 
typedef struct node{
	
	int data;//data 值 
	struct node *next;//next
	
}node,*list;

//transpose linklist
void transpose_list(list &head)
{
	
	list p = head,s;
	head = NULL;
	
	while(p != NULL)
	{
		//把 现在的 头结点 取下来 
		s = p;
		p = p->next;//p指向 当前 头结点 的后一位 
		s->next = head;//然后 让s指向 之前取下来的结点，相当于 指向 原先的 前驱 结点， 
		//调转 next 指向前驱 
		head = s; //作为新 表的 头结点 
	} 
	
	return;
}

//存储 结构 为 线性表 的处理 
typedef struct Sqlist{
	int *elem;//data 数组 
	int length;//current length
}Sqlist;

//Sqlist_one
void transpose_Sqlist_one(Sqlist &L)
{
	
	int temp;
	//交换  类似与 双向链表 从两头 往中间 找 
	for(int i = 0;i < L.length / 2;i ++)//n为l.lenght 
	{
		
		temp = L.elem[i];
		L.elem[i] = L.elem[L.length - i - 1];
		L.elem[L.length - i - 1] = temp;
		
	}
	return;
}

//Sqlist_two
void transpose_Sqlist_two(Sqlist &L)
{
	int i = 0,j = L.length - 1,temp = 0;
	
	//类似与 双向链表 从两头 往中间 找 
	while(i < j)
	{
		temp = L.elem[i];
		L.elem[i] = L.elem[j];
		L.elem[j] = temp;
		
		i ++;j --;
	}
	return;;
}

void print_list(list L)
{
	
	L = L->next;
	printf("linklist :");
	while(L->data != NULL)
	{
		printf("%d  ",L->data);
		L = L->next;
	}
	
	return;
}

void print_Sqlist(Sqlist L)
{
	printf("Sqlist :");
	for(int i = 0;i < L.length;i ++)
	{
		printf("%d  ",L.elem[i]);
	}
	printf("\n");
	return;
}

//main 测试 函数 
int main()
{
	
	/******************linklist test**************************/
	
	list head,q;
	head->next = NULL;
    head->data = 0;

	int list_length = 10;
	q = head;
	while(list_length != 0)//赋值9 8 7 6 5 4 3 2 1 0 
	{
		list_length --;
		
		list p = (list)malloc(sizeof(node));//申请 结点 
		p->next = NULL;
		p->data = list_length;//构建 单链表 
		
		
		q->next = p;
		q = p;
	}
	
	transpose_list(head);//转置 单链表 
	
	print_list(head);//print
	//释放 申请的结点 空间（否则 可能 造成 打印 不出 ） 
	while(head != NULL)
	{
		head = head->next;
		delete head;
	}
	printf("\n");
	
	/******************linklist test**************************/
	
	//注意 两个测试 程序 不要 同时 运行 ，否则 可能 造成 其中一个 测试 函数打印 不出 值，两种 情况分别 测试 
	
	/******************Sqlist test**************************/
	/* 
	Sqlist L;
	L.length = 10;
	for(int i = L.length - 1;i >= 0;i --)//赋值 9 8 7 6 5 4 3 2 1 0 
	{
		L.elem[L.length - i - 1] = i; 
	}
	
	//transpose_Sqlist_one(L);//one method 转置 线性表 
	transpose_Sqlist_two(L);//two method 转置 线性表 
	
	print_Sqlist(L);
	
	/*****************Sqlist test***************************/
	
	return 0;
}
 
