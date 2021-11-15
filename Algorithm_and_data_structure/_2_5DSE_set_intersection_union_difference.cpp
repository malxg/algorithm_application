/*
A和B 单链表表示 集合的 交集 并集 差集 
*/
//#include <iostream>
//using namespace std;

#include <stdio.h>
#include <stdlib.h>//包含 随机 函数 rand() 
#include <time.h>  //含tiem()函数 获取 当前 时间 
#include <malloc.h>  //含malloc() 申请动态空间 函数 
#define N 5

int M = rand()%101;//随机 变量范围 

typedef struct set{
	int data;
	struct set* next;	
}set;

//打印 集合 
void print_set(int a[])
{
	for(int i = 0;i < 2 * N;i ++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
	
	return;
}

//生成 两个 集合 A 和 B
set* generate_set()
{

	set *q,*p,*head;
	q = (set *)malloc(sizeof(set));
	
	
	//以当前时间 为种子，随机模拟 N 个 集合 元素 (range(0,M))
	srand(time(NULL));
	q->data = rand()%(M + 1);
	printf("data:%d ",q->data);
    q->next = NULL;
	head = q;//head 作为 首 指针(该指针 下 有数据) 
	
	for(int i = 0;i < N - 1;i ++)
	{
		p = (set *)malloc(sizeof(set));
		
	    p->data = rand()%(M + 1);
		printf("%d ",p->data);
		p->next = NULL;
		
		q->next = p;
		q = p;
		p = p->next;
	}
	printf("\n");
	return head;
}

//求 交集(A,B集合 中 相同的 元素)
void _intersection(set *A,set *B)
{
	set *q1 = A,*q2 = B;
	int sect[2*N] = {0};
	int i = 0;
	
	do//一一 比对 比对成功 则为相同 元素 
	{
		q2 = B;
		while(q2 != NULL)
		{
			if(q1->data == q2->data)//进行 比对 
			{
				sect[i ++] = q1->data;//比对 成功 保存在 交集数组 
			}
			else;
			
			q2 = q2->next;
		}
		q1 = q1->next;
		
	}while(q1 != NULL);
	//printf
	printf("交集:");
	print_set(sect);
	return;
} 

//求 并集(两个集合内的所有元素合并在一起组成的集合叫做“集合A和集合B的并集”)
void _union(set *A,set *B)
{
	set *q1 = A,*q2 = B;
	int uni[2 * N] = {0};
	int i = 0;
	
	while(q1 != NULL)
	{
		uni[i ++] = q1->data;
		q1 = q1->next;
	}
	while(q2 != NULL)
	{
		uni[i ++] = q2->data;
		q2 = q2->next;
	}
	//打印 
	printf("并集:");
	print_set(uni);
	return;
} 

//求 差集(所有属于A且不属于B的元素组成的集合,叫做集合A减集合B (或集合A与集合B之差),类似地,对于集合A.)
//这里 采取  集合A减集合B
void _difference(set *A,set *B)
{
	set *q1 = A,*q2 = B;
	int diff[2 * N] = {0};
	int i = 0;
	int flag = 0;//标识，有相同 元素 flag 变为 1,否则 0 
	
	do//一一 比对 
	{
		q2 = B;
		flag = 0;// 初始 标识 
		
		while(q2 != NULL)
		{
			if(q1->data == q2->data)//进行 比对 
			{
				flag = 1;//比对 成功 标识 为 1
				break;//退出 排除  该 元素  
			}
			else;
			
			q2 = q2->next;
		}
		
		if(flag == 0)//为 0 则无相同元素  
		{
			diff[i ++] = q1->data;
		}
		else;
		
		q1 = q1->next;
		
	}while(q1 != NULL);
	//打印 
	printf("差集:");
	print_set(diff);
	return;
} 


//释放 空间 
void release_link(set *head)
{
	set *q,*p;
	q = p = head;
	while(q->next != NULL)
	{
		p = q->next;
		q->next = q->next->next;
		free(p);
	}
	free(head);
}

int main()
{
	set *A,*B;
	int *sect,*uni,*diff;
	//生成 两个 集合 
	A = generate_set();
	M = 200;
	B = generate_set();
	
	//交集
	_intersection(A,B);
	//并集
	_union(A,B);
	//差集 A - B
	_difference(A,B); 
	
	//释放 A,B单链表 空间 
	release_link(A);
	release_link(B);
	return 0;
}
