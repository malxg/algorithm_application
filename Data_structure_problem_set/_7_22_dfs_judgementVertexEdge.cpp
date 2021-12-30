/*
����������ȣ��б����ڽӱ�ʽ�洢������ͼ�Ƿ��ж���v������u��·���� 
*/

 
#include <stdio.h>
#include <malloc.h>
 
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

//������� Ŀ��߱��(����ջ)
int node_flag[N + 1] = {0};//��� ��� ���ʱ�ʶ 
int flag = 0;//�ҵ���ʶ 
void dfs(listnode a[],node *p,int w)
{	

	if(p == NULL)
	{
		return;
	}

	if(p->aimdex == w)
	{
		printf("����");
		flag = 1;
		return;
	}
	//�ҵ� ��Ӧ�߽��� ��ͷ������� 
	int i = 0;
	for(i = 0;i < N;i ++)
	{
		if(a[i].index == p->aimdex)
		{
			break;
		}
	}

	//�ҵ���ͷ ��ͬ���������� �߽��
	listnode * t = &a[i];
	node_flag[t->index] = 1;//��ʶΪ���� 
	node *q = t->first;
	//�˳�ѭ��������qΪNULL,����flag = 1,�Ѿ��ҵ� ����������
	while(q != NULL || flag == 1)
	{
		if(node_flag[q->aimdex] == 1)//�ñ�Ž���Ѿ������� 
		{
			q = q->next;//���� �ñ�Ž�� 
			continue;
		}
		//����ݹ鴦�� 
		dfs(a,q,w);
		q = q->next;
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
	int i = 0;
	for(i = 0;i < N;i ++)
	{
		if(a[i].index == v)
		{
			break;
		}
	}

	//�ݹ�Ѱ�� 
	//�ҵ���ͷ ���� �߽��
	listnode * t = &a[i];
	node_flag[t->index] = 1;//��ʶΪ���� 
	node *q = t->first;
	//�˳�ѭ��������qΪNULL,����flag = 1,�Ѿ��ҵ� ����������
	while(q != NULL || flag == 1)
	{
		if(node_flag[q->aimdex] == 1)//�ñ�Ž���Ѿ������� 
		{
			q = q->next;//���� �ñ�Ž�� 
			continue;
		}
		//����ݹ鴦�� 
		dfs(a,q,w);
		q = q->next;
	}
	
	if(flag == 0)
	{
		printf("������!");
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
