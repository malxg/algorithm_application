//���ڹ�������������б����ڽӱ�ʽ�洢������ͼ�Ƿ��ж���v������u��·����
 
#include <stdio.h>
#include <malloc.h>
#include <queue>//����ʵ�ֹ������ 
using namespace std;
#define N 11
typedef struct node{
	int aimdex;//��ͷָ����ı�� 
	struct node *next;//ָ����һ����� 
}node;
 
typedef struct listnode{
	int index;   //����� 
	int outdegree;//����
	node *first; //��һ�� �߽�� (�� ͷ�巨 ����)
}listnode;
 
//���� �ڽӱ�,ͬʱͳ�� ÿ������ ���� 
int len = sizeof(node);//���� ���� ���ռ� 

void create_list(listnode a[]);

//������� Ŀ��߱��(���� �������)
int node_flag[N + 1] = {0};//��� ��� ��ӱ�ʶ 
int flag = 0;//�ҵ���ʶ 
void bfs(listnode a[],int v,int w)
{	
	if(v == w)//�Լ��ж��Լ� ���ﲻ�ٿ��Ƿ�Χ(��ȻҲ���ԸĽ� �����л�) 
	{
		printf("v��wһ����");
		return;
	}
	
	queue<node*> q1;//����
	node *p = a[v - 1].first;//������ʱ�� v - 1�����-1Ϊ ����λ�ã� 
	//��v���� ���б߽�����  
	while(p != NULL)
	{
		q1.push(p);
		node_flag[p->aimdex] = 1;//��ʶ��� 
		p = p->next;
	}
	
	node *q;
	while(q1.empty() == 0)//��Ϊ�� 
	{
		p = q1.front();//pָ����� ��� 
		q1.pop();//���� ����
		if(p->aimdex == w)//�Ƿ���Ҫ�ҵ� ��� 
		{
			printf("����");
			flag = 1;//�ҵ���ʶ 
			break;//�ж� ѭ�� 
		}
		
		//���� �Զ��׽�� Ϊ�������ı߽�����,����Ѱ�� 
		q = a[p->aimdex - 1].first;
		
		while(q != NULL)
		{
			//���֮ǰ�ñ�ű߽�� ����ӣ������ý�� 
			if(node_flag[q->aimdex] == 1)
			{
				q = q->next;
				continue;
			}
			//���� ���
			q1.push(q);
			q = q->next; 
		}
	}
	
	return;
}
/*
test
����� ���� �߽�� 
v1        3   -->4-->3-->2
v2        0         
v3        2   -->5-->2
v4        1   -->5
v5        0
v6        2   -->5-->4
*/
int main()
{
	listnode a[N] = {0,0,NULL};
	//���� �ڽӱ�,ͬʱͳ�� ÿ������ ���� 
	create_list(a);
	//����Ҫ�ж� ���� �ı�
	int v,w;
	v = w = 0;
	printf("v,w: ");
	scanf("%d%d",&v,&w);
	//�ҵ� ��Ӧ�߽��� ��ͷ������� 
	bfs(a,v,w);
	
	if(flag == 0)
	{
		printf("�����ڣ�");
	}
	return 0;
}
//���� �����ڽӱ� 
void create_list(listnode a[])
{
	listnode *p = a;//���� 
	node *q;//ָ��߽�� 
	//��ʼ N�� ���� 
	for(int i = 0;i < N;i ++)
	{
		p[i].index = i + 1;//1~n���
		p[i].outdegree = 0;
		p[i].first = NULL;
	}
	
	//���� �߽�� 
	printf("\nplease input the edge node(��ͷβ��&ͷ��(���)(0,0)Ϊ����):\n");
	int k = 0,m = 0;
	scanf("%d%d",&k,&m);//kΪ ����ߣ���ͷβ����mΪ ͷ������� 
	
	while(k != 0 && m != 0)//����(0,0)����
	{
		
		q = (node*)malloc(len);
		
		q->aimdex = m;//��ʶ��ָ �����
		//ͷ�巨 ˼��
		q->next = p[k - 1].first;//���ν��next ָ���ϴβ�����Ǹ���㣨û�о�ָ�� NULL�� 
		p[k - 1].first = q;//ͷ�巨 �µ� �߽�� ���뵥����ı�ͷ 
		
		p[k - 1].outdegree ++;//���� ����
		
		scanf("%d%d",&k,&m);
	}
	return;
}
