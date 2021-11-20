/*
���ڽӱ���Ϊ�洢�ṹ��ͼG��
1 ��ͼ��ÿ������ĳ���
2 ����ͼ�г���Ϊ0�Ķ����� 
*/

#include <stdio.h>
#include <malloc.h>
#define N 6
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

//�жϽ��� �����������Ϊ 1����� 
void judge(listnode a[])
{
	int count = 0;
	for(int i = 0;i < N;i ++)//���� ����ĳ���ֵ 
	{
		if(a[i].outdegree == 0)
		{
			printf("����Ϊ0��㣺v%d ",a[i].index); 
			count ++;
		}
		else;
	}
	
	printf("\n����Ϊ0�Ľڵ��� %d",count);
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
	listnode a[N];
	
	//���� �ڽӱ�,ͬʱͳ�� ÿ������ ���� 
	create_list(a);
	
	//�жϽ��� �����������Ϊ 1����� 
	judge(a);
	
	return 0;
}
