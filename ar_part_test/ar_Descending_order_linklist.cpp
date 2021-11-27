/*
Unidirectional linked list
Descending order
(1)数重复 保留一个 
(2)以 出现次数 降序 
*/

#include <stdio.h>
#include <iostream>
#include <malloc.h>
using namespace std;

typedef struct node{
	int data;
	int count;
	struct node *next;
}Node,*Ntree;

void Create_List()
{
	
	Ntree p,pre,Head;
	int a;
	
	Head = (Ntree)malloc(sizeof(Node));
	Head->next = NULL;
	while(1)//建立n各结点 的链表 
	{
		cin >> a;//scanf("%d",&a); 
	
		if(a == 0)//count 0 end process
		{
			
			printf("printf zero --> process end!");
			return;
			
		}
		
		pre = Head;//默认 头结点 
		p = pre->next;
		
		while(p != NULL && a != p->data)
		{
			
			pre = p;
			p = p->next;
		
		}
		
		if(p == NULL)//while 循环 没有找到重复值，是新 值 
		{
			
			p = (Ntree)malloc(sizeof(Ntree));
			p->count = 1;//第一次出现
			p->data = a;//赋值为 a
			p->next = NULL;//链尾 置为空 
			
			pre->next = p;//先驱 指向它 
			
		}
		else//while  由于 找到了 相同的 a数值 
		{
			
			p->count = p->count + 1;//整数重复出现 ，频度 + 1 
			
			pre->next = p->next;//改了 值后 把它 取出来，按 频度 重调次序
			
			pre = Head;//初始 回 头结点 
			Ntree q = Head->next;//定义 为头结点后 第一个 结点 
			
			//找到了比 p->count 小的位置，插入到 其前面 
			while(q != NULL && p->count < q->count)
			{
				pre = p;
				q = q->next;
			} 
			
			//pre 为 上一轮 比p->count 大的值,q为 没有p->count大的值 
			pre->next = p;
			p->next = q;
			
		}
	}
	
	return;
}

int main()
{
	return 0;
}
