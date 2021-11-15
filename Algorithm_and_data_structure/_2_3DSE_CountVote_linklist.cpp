/*
统计 选票 按单链表 存放选票 编号 1,2,3,...,N,且 一人 只有 一票 
*/
#include <stdio.h> //包含 scanf() printf() 等输入输出 函数 
#include <stdlib.h>//包含 随机 函数 rand() 
#include <time.h>  //含tiem()函数 获取 当前 时间 
#include <malloc.h>  //含malloc() 申请动态空间 函数 
#define N 5
#define M 100

typedef struct candidate{
	int vote;
	struct candidate * next;
}candidate,*cand;

//模拟 投票  
int sum_vote = M;//选票 人数 有 sum_vote个 即有 sum_vote票 
cand simulation_vote()
{
	cand match;
	candidate *q,*p;
	q = (candidate *)malloc(sizeof(candidate));
	
	srand(time(NULL));
	q->vote = rand()%(M/2 + 1);
    q->next = NULL;
	match = q;//match 作为 首 指针 
	
	sum_vote = sum_vote - q->vote;//减去 已经 选了 第一位的人 
	//模拟 N 位 候选人 投票 结果 
	for(int i = 0;i < N - 1;i ++)
	{
		p = (candidate *)malloc(sizeof(candidate));
		do
		{
			p->vote = rand()%(M + 1);
			if(p->vote < sum_vote)
			{
				break;
			}
		}while(1);
		
		sum_vote = sum_vote - p->vote;
		
		p->next = NULL;
		
		q->next = p;
		q = p;
		p = p->next;
	}
	
	return match;
}



//输出 投票 结果 
void print_candidate(candidate *head)
{
	cand a = head;
	while(a != NULL)
	{
		printf("%d ",a->vote);
		a = a->next;
	}
	printf("弃权:%d",sum_vote);
	printf("\n");
	return;
}


//释放 空间 
void release_link(candidate *head)
{
	candidate *q,*p;
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
	cand head;
	head = simulation_vote();
	
	//打印 得票结果 到终端 
	print_candidate(head);
	
	//free 空间 
	release_link(head);
	
	return 0;
} 
