/*
ͳ�� ѡƱ �������� ���ѡƱ ��� 1,2,3,...,N,�� һ�� ֻ�� һƱ 
*/
#include <stdio.h> //���� scanf() printf() ��������� ���� 
#include <stdlib.h>//���� ��� ���� rand() 
#include <time.h>  //��tiem()���� ��ȡ ��ǰ ʱ�� 
#include <malloc.h>  //��malloc() ���붯̬�ռ� ���� 
#define N 5
#define M 100

typedef struct candidate{
	int vote;
	struct candidate * next;
}candidate,*cand;

//ģ�� ͶƱ  
int sum_vote = M;//ѡƱ ���� �� sum_vote�� ���� sum_voteƱ 
cand simulation_vote()
{
	cand match;
	candidate *q,*p;
	q = (candidate *)malloc(sizeof(candidate));
	
	srand(time(NULL));
	q->vote = rand()%(M/2 + 1);
    q->next = NULL;
	match = q;//match ��Ϊ �� ָ�� 
	
	sum_vote = sum_vote - q->vote;//��ȥ �Ѿ� ѡ�� ��һλ���� 
	//ģ�� N λ ��ѡ�� ͶƱ ��� 
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



//��� ͶƱ ��� 
void print_candidate(candidate *head)
{
	cand a = head;
	while(a != NULL)
	{
		printf("%d ",a->vote);
		a = a->next;
	}
	printf("��Ȩ:%d",sum_vote);
	printf("\n");
	return;
}


//�ͷ� �ռ� 
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
	
	//��ӡ ��Ʊ��� ���ն� 
	print_candidate(head);
	
	//free �ռ� 
	release_link(head);
	
	return 0;
} 
