/*
以带头结点的循环链表表示队列，并且只设一个指针指向队尾元素结点（不设头指针），
实现队列的初始化，入队和出队。 
*/

#include <stdio.h>
#include <malloc.h>
#define N 10

typedef struct node{
	int data;
	struct node* next;
}node,*pnode;
//打印 循环链表（从头结点开始） 
void print_pnode(pnode a);
//构建循环队列 最初数据都为0 为空 
pnode tail;//指向队尾的指针
pnode create_round_queue()
{
	node *a;//头结点不保存数据非头指针 
	int size = sizeof(node);//结点大小 
	//头结点初始化 
	a = (pnode)malloc(size);
	a->next = NULL;
	a->data = 0;
	
	pnode q;
	tail = a;//起始指向头结点 
	for(int i = 0;i < N;i ++)
	{
		//初始一个结点 
		q = (pnode)malloc(size);
		q->next = NULL;
		q->data = 0;//0表示没有数据 
		//链接结点 
		tail->next = q;
		tail = q;
	}
	//tail作为队尾元素指针 
	tail->next = a;//然后头尾相连 形成循环链表 
	tail = a->next;//初始化尾指针指向 第一个空位，初始都为空所以指向头结点后一个位置 
	
	
	return a;
}

//入队 成功返回1，否则-1 
int push(pnode a,int elem)
{	
	if(tail == a)//头指针不保存数据 
	{
		tail = tail->next;//跳过头指针 
	}
	if(tail->data == 0)//为空
	{
		//由于空间已经申请完毕，只需要填入值 
		tail->data = elem;
		tail = tail->next;
	}
	else//队满 入队失败 
	{
		return -1;
	}
	
	
	return 1;
}
//出队 不返回出队元素 出队失败返回-1 成功返回0 
int pop(pnode a)
{
	//由于没有设置头指针 只能从头结点开始 往后查询第一个元素 
	pnode head = a;
	//查询 
	head = head->next;//后移 
	while(head->data == 0)
	{
		head = head->next;//后移
		if(head == a)//绕了一圈 全是0，说明出队失败 
		{
			return -1;//返回 -1 
		} 
	}
	//找到
	head->data = 0;//置为0 视为删除数据 
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
	
	pnode head = a->next;//从头结点开始 
	
	while(head->next != a)//如果下一个结点是头结点 说明走了一圈，结束 
	{
		
		printf("%d ",head->data);
		head = head->next;//后移 
	}
	printf("\n");
	return;
}
 
