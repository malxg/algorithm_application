/*
�Ը������������Ͷ��壬�ٶ�Ԫ������Ϊ���ͣ��������ͷ��㣬
��д����ʵ�ֶԵ������е�ָ��Ԫ��ֵΪe�Ľ��ɾ���������ٶ�Ԫ��ֵΪe�Ľ��һ�����ڡ�
*/
#include <iostream>
#include <malloc.h>
#define size 10 
using namespace std;

typedef struct node{
	int e;
	struct node *next;
}node,*list;//style struct int e node *next


void create_single_list(list Head)//create linklist
{
	int i = size;//#define size 10
	node *q;
	q = (node*)malloc(sizeof(node));
	q->e = i --;
	q->next = NULL;
	
	Head->next = q;
	
	while( i > 0)
	{
		node *p;
		p = (node*)malloc(sizeof(node));
		p->e = i --;
		p->next = NULL;
		
		q->next = p;//���� ��� 
		q = p;

	}
	
	return;
}

void delete_element(node *Head,int data)//delete element
{
	list p = Head;
	node *q;
	for(int i = 0;i < size;i ++)
	{
		if(p->next->e == data)
		{
			q = p->next;//���Ҫ ɾ�� �� ��㣬��������ͷţ�һ����ɾ��ǰ������ɽ�ʬ��� 
			
			p->next = p->next->next;//�ѽ�� ��������ɾ�� 
			break;//����ѭ�� 
		}
		else;
		
		p = p->next;
	}
	
	free(q);//�ͷ� ɾ���Ľ�� 
	q = NULL;//ע��free �ͷź�������Чָ�� ��Ϊ �� 
	return;
}

//print
void print_linklist_element(list Head)//printf
{
	node *p = Head->next;
	do
	{
		
		cout << p->e << " ";
		p = p->next;
		
	}while(p != NULL);
	
	cout << endl;
	
	return;
}

//main function
int main()
{
	node *Head;//ͷ��� 
	Head->e = 0;//init zero
	Head->next = NULL;
	
	create_single_list(Head);//create link list
	print_linklist_element(Head);//print
	
	int e;
	cout << "delete value is :"; 
	cin >> e;
	
	delete_element(Head,e);//delete element
	
	print_linklist_element(Head);//print
	
	return 0;
}
