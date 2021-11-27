/*
Unidirectional linked list
Descending order
(1)���ظ� ����һ�� 
(2)�� ���ִ��� ���� 
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
	while(1)//����n����� ������ 
	{
		cin >> a;//scanf("%d",&a); 
	
		if(a == 0)//count 0 end process
		{
			
			printf("printf zero --> process end!");
			return;
			
		}
		
		pre = Head;//Ĭ�� ͷ��� 
		p = pre->next;
		
		while(p != NULL && a != p->data)
		{
			
			pre = p;
			p = p->next;
		
		}
		
		if(p == NULL)//while ѭ�� û���ҵ��ظ�ֵ������ ֵ 
		{
			
			p = (Ntree)malloc(sizeof(Ntree));
			p->count = 1;//��һ�γ���
			p->data = a;//��ֵΪ a
			p->next = NULL;//��β ��Ϊ�� 
			
			pre->next = p;//���� ָ���� 
			
		}
		else//while  ���� �ҵ��� ��ͬ�� a��ֵ 
		{
			
			p->count = p->count + 1;//�����ظ����� ��Ƶ�� + 1 
			
			pre->next = p->next;//���� ֵ�� ���� ȡ�������� Ƶ�� �ص�����
			
			pre = Head;//��ʼ �� ͷ��� 
			Ntree q = Head->next;//���� Ϊͷ���� ��һ�� ��� 
			
			//�ҵ��˱� p->count С��λ�ã����뵽 ��ǰ�� 
			while(q != NULL && p->count < q->count)
			{
				pre = p;
				q = q->next;
			} 
			
			//pre Ϊ ��һ�� ��p->count ���ֵ,qΪ û��p->count���ֵ 
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
