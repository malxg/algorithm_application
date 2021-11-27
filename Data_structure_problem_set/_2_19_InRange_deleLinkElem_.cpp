/*
��֪���Ա��е�Ԫ����ֵ�����������У����Ե�������Ϊ�洢�ṹ��
����ɾ����������ֵ����mink��С��maxk��Ԫ�أ����ͷš� 
*/

#include <stdio.h>
#include "malloc.h"

typedef struct LNode{
	int data;
	struct LNode *next;
}LNode,*LinkList;//������������

//��ӡ ������ Ԫ�� 
void prin_Link(LinkList a);
//�ͷ����� 
void free_link(LinkList a);
//����һ�������� 
LNode * create_list();//����ͷ����ַ 
//ɾ����Χ��Ľ�㣬�������ڷ�Χ��  
void del_element(LinkList a,int mink,int maxk)
{
	LinkList p,q,pre = a;//pre ��ʼָ�� ͷ���
	p = pre->next; 
	while(p != NULL)
	{
		if(p->data < mink || p->data > maxk)//�ҵ��ڷ�Χ�� 
		{
			//�ҵ���� ��ʼɾ��
			pre->next = p->next;//�޳� Ҫɾ���� pָ��Ľ�� 
			//�ͷ� pָ��Ľ�� ���ָ�pָ�� 
			free(p);
			p = pre->next;//pʼ�ձ���ǰһ�� �����preָ�� 
		}
		else//û���ҵ� ���������� 
		{
			pre = p;
			p = p->next;
		} 
		
	}
	
	return;
} 
int main()//main* 
{
	LNode * a;//ָ���׽��� ָ�� 
	
	//���쵥������������� 
	a = create_list();//a���� �׽�� 
	
	//�鿴������
	prin_Link(a); 
	
	//ɾ�� ��mink < k < maxk ֮���Ԫ�� 
	int mink = 0,maxk = 0;
	scanf("%d%d",&mink,&maxk);
	//��ʼɾ��
	del_element(a,mink,maxk);//�Σ����׵�ַ,���ߣ����� 
	
	//�鿴ɾ����Ч��
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
