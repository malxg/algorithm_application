/*
�Ե�����ʵ�־͵����� 
*/
#include <stdio.h>
#include "malloc.h"

typedef struct LNode{
	int data;
	struct LNode *next;
}LNode,*LinkList;//������������

//���� 
//�Ȱ�ͷ����һ�����i����ĩβ��Ȼ����֮ǰĩβ���͵�ǰĩβ���i֮��������磺1 2 3 4 -->2 3 4 1 --> 4 3 2 1 
void inverse(LinkList a)
{
	//ע���и� ͷ���������ת��Ϊ �ѵ�һ������ĩβ֪�������һ��Ԫ��(��ʶ)�ŵ���ͷ����ʽ�Ͼ�������
	LinkList head = a;//ͷ���
	LinkList p = head->next;
	//�ҵ����һ��Ԫ��,����ʶΪpָ��
	while(p->next != NULL)
	{
		p = p->next;
	}
	//��ͷ����һ�����i����ĩβ
 	LinkList q = head->next;
 	
 	head->next = q->next;//�޳�ͷ����һ����� 
 	q->next = NULL;//��ʼ��������޳����
 	p->next = q;//���ӵ� ĩβ
 	LinkList tail = q;//tailָ������ĺ�һ�����,pʼ��ָ���ʼ��ĩβ���4 
 	//��ʼ����ʣ��������ã����뵽������Ϊ2 3 4 1����4 1�в����׽��2Ϊ3 4 2 1Ȼ��4 2����3Ϊ4 3 2 1������� 
	while(1)//ʼ�ձ��� �������β���p������� 
	{
		//��q����p��˵�����һ����㵽���׽��,����ѭ��
		q = head->next;//��ʼ��qָ��ǰ ͷ����һ����� 
		if(q == p)//��һ����� ���� ���һ����� 
		{
			break;//������� �˳� 
		}
		//�����������
		head->next = q->next;//�޳���ǰ �׽��(ͷ����һ�����)
		q->next = tail;//�׽�� ָ������ĺ�һ����� 
		p->next = q;   //ǰһ�����nextָ��ý��
		tail = q;//�������һ�������� 
		
	}
 	
	return;
}

//��ӡ ������ Ԫ�� 
void prin_Link(LinkList a);
//�ͷ����� 
void free_link(LinkList a);
//����һ�������� 
LNode * create_list();//����ͷ����ַ 

int main()//main* 
{
	LNode * a;//ָ���׽��� ָ�� 
	
	//���쵥������������� 
	a = create_list();//a���� �׽�� 
	
	//�鿴������
	prin_Link(a); 
	
	//���� 
	inverse(a);
	//�鿴���ý��
	prin_Link(a); 
	
	//����������ͷ����� 
	free_link(a);
	
	return 0;
}

//����һ�������� 
LNode * create_list()
{
	LinkList a;
	LinkList q,p;
	int size = sizeof(LNode);//��ȡ���ռ� 
	a = (LinkList)malloc(size);//����ͷ��� ����������,����ʹɾ���㷨ͳһ 
	a->next = NULL;
	a->data = 0;
	 
	
	q = (LinkList)malloc(size);//����ͷ��� ����������
	q->next = NULL;
	q->data = 3;
	a->next = q;//q������Ϊ��һ�� �����ݽ��

	for(int i = 4;i < 13;i ++)
	{
		//��ʼһ����� 
		p = (LinkList)malloc(size);
		p->next = NULL;
		p->data = i;
		
		q->next= p;//q��һ�����ָ���´�����p��� 
		q = p;   //q �Ƶ�p��λ�� 
		p = p->next;//pָ��NULL 
	}
	return a;//���� �׽�� 
} 

//��ӡ ������ Ԫ�� 
void prin_Link(LinkList a)
{
	LinkList p = a->next;
	
	while(p != NULL)
	{
		printf("%d ",p->data);
		p = p->next;
	}
	printf("\n");
	return;
}
//�ͷ����� 
void free_link(LinkList a)
{
	LinkList p = a->next;
	while(p != NULL)
	{
		//��ͷ����һ��λ�ã���ʼ�ͷ� 
		a->next = p->next;
		free(p);
		p = a->next;
	}
	
	//����ͷ� ͷ���
	free(a); 
	a =NULL;//��ʼָ�� 
	return;
}
