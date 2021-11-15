/*
解决 约瑟夫 问题。
（39个犹太人决定宁愿死也不要被敌人抓到，于是决定了一个自杀方式，41个人排成一个圆圈，由第1个人开始报数，
每报数到第3人该人就必须自杀，然后再由下一个重新报数，直到所有人都自杀身亡为止。然而Josephus 和他的朋友并不想遵从。
首先从一个人开始，越过k-2个人（因为第一个人已经被越过），并杀掉第k个人。接着，再越过k-1个人，并杀掉第k个人。
这个过程沿着圆圈一直进行，直到最终只剩下一个人留下，这个人就可以继续活着。
问题是，给定了和，一开始要站在什么地方才能避免被处决。Josephus要他的朋友先假装遵从，
他将朋友与自己安排在第16个与第31个位置，于是逃过了这场死亡游戏。） 

现在 输出 约瑟夫 序列(重复 直到所有人 出列 )
如n=8,m=4,s=1 则序列：4,8,5,2,1,3,7,6 
*/
//#include <iostream>
//using namespace std;

#include <stdio.h>
#include <malloc.h>//包含 malloc 函数 

typedef struct person{
	int index;
	struct person *next;
}person;//构建 人 的 的属性，即有多少人 就构建 多少个 结点 

//构建 单链表 
person* generate_link(int n)
{
	printf("star: \n");
	person *q,*p1,*head;
	
	p1 = (person *)malloc(sizeof(person));//申请第一个 元素的空间 
	p1->index = 1;
	int i = 2;
	
	
	head = p1;//保存 首结点地址 ，这个 指针始终 指向首结点 
	
	n = n - 1;
	while(n --)
	{

		//造 q结点 
		q = (person *)malloc(sizeof(person));//申请元素的空间 
		
		q->index = i ++;
		q->next = NULL;
		
		//连接 q结点 
		p1->next = q;
		p1 = q;
		q = q->next;
	}
	
	//首位 相结 贪吃蛇 循环单链表 
	p1->next = head;
	printf("end: \n");
	return head;
}
void josephus_solve(person *head,int m,int s)
{
	int count = 1;
	person *begin = head;
	
	while(begin->index != s)
	{
		begin = begin->next;
	}
	
	printf("序列: ");
	person *q;//记录 要出列 的人 方便 释放空间 
	while(begin != NULL)
	{
	    
		count ++; //报数 
		
		//这里 count 已经 经过了 前面 的count ++ 实际 是下一位 该 报的数 
		if(count == m)//这里，即看他 下一个人 是否报数 m，是 直接让下一个人出列 
		{
			count = 1;//初始 下一个为 起点 
			printf("%d ",begin->next->index);
			q = begin->next;
			begin->next = begin->next->next;
			free(q);
		}
		
		begin = begin->next;
		
		//只有一个 结点,直接 出列 
		if(begin->next == begin)//(循环 单链表 指向 自己 说明 没有其他结点)
		{
			printf("%d ",begin->index);
			break; 
		}
		
	}
	
	printf("\n");
	return;
}

int main()
{
	int n = 0,m = 0,s = 0;
	person *p1;
	printf("n,m,s :");
	scanf("%d%d%d",&n,&m,&s);
	
	//构建 单链表 
    p1 = generate_link(n);
	//开始 处理 得 到 序列 
	josephus_solve(p1,m,s);
	
	return 0;
}
