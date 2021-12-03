/*
以域变量rear和length分别指示循环队列中队尾
元素的位置和内含元素的个数。给出队满条件和相应的如对和出队算法。 
*/

#include <stdio.h>
#include <malloc.h>
#define N 10

typedef struct node{
	int data;
	struct node *rear,*front;//域变量 
	int lenth;
	struct node* next;
}node,*pnode;
//打印 循环链表（从头结点开始） 
void print_pnode(pnode a);
//构建循环队列 最初数据都为0 为空 

pnode create_round_queue()
{
	node *a;//头结点不保存数据非头指针 
	pnode tail;//指向队尾的指针
	int size = sizeof(node);//结点大小 
	//头结点初始化 
	a = (pnode)malloc(size);
	a->next = NULL;
	a->data = 0;
	
	pnode q;
	tail = a;//起始指向头结点 
	for(int i = 0;i < N;i ++)
	{//初始一个结点
		// 
		q = (pnode)malloc(size);
		q->next = NULL;
		q->data = 0;//0表示没有数据 
		//链接结点 
		tail->next = q;
		tail = q;
	}
	//tail作为队尾元素指针
	tail->next = a;//然后头尾相连 形成循环链表
	
	a->front = a->rear = a->next;//初始化头指针，尾指针指向 第一个空位，初始都为空所以指向头结点后一个位置 
	return a;
}

//入队 成功返回1，否则-1 
int push(pnode a,int elem)
{	
	
	if(a->rear->next == a->front)//尾指针的下一个结点是头指针指向的则 说明队满（留一个空间不存储） 
	{
		return -1;
	}
	else//开始入队 
	{
		a->rear->data = elem;
		a->lenth ++;
		a->rear = a->rear->next;
	}
	
	return 1;
}
//出队 不返回出队元素 出队失败返回-1 成功返回0 
int pop(pnode a)
{
	//如果尾指针 等于头指针，则为空 
	if(a->rear == a->front)
	{
		return -1;
	}
	//从队头出队 
	a->front->data = 0;
	a->lenth --;//队列元素 减一 
	a->front = a->front->next;//队头向后移 
	
	return 0;//成功返回0 
}

//主函数 
int main()
{
	pnode a;
	//构建循环队列长度为宏定义N 
	a = create_round_queue(); 
	//查看构建
	print_pnode(a);//查看构建结果 
	//push
	push(a,3);
	push(a,13);
	push(a,-3);
	push(a,3);
	push(a,13);
	push(a,-3);
	push(a,3);
	push(a,13);
	push(a,-3);
	print_pnode(a);
	//pop
	pop(a);
	pop(a);
	print_pnode(a);
	
	return 0;
}
//打印 循环链表（从头指针开始） 
void print_pnode(pnode a)
{
	
	pnode head = a;//从头结点开始 
	
	while(head->next != a)//如果下一个结点是头结点 说明走了一圈，结束 
	{
		
		printf("%d ",head->data);
		head = head->next;//后移 
	}
	printf("\n");
	return;
}
  
