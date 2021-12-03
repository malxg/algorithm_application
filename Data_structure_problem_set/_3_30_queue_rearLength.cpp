/*
�������rear��length�ֱ�ָʾѭ�������ж�β
Ԫ�ص�λ�ú��ں�Ԫ�صĸ���������������������Ӧ����Ժͳ����㷨�� 
*/

#include <stdio.h>
#include <malloc.h>
#define N 10

typedef struct node{
	int data;
	struct node *rear,*front;//����� 
	int lenth;
	struct node* next;
}node,*pnode;
//��ӡ ѭ��������ͷ��㿪ʼ�� 
void print_pnode(pnode a);
//����ѭ������ ������ݶ�Ϊ0 Ϊ�� 

pnode create_round_queue()
{
	node *a;//ͷ��㲻�������ݷ�ͷָ�� 
	pnode tail;//ָ���β��ָ��
	int size = sizeof(node);//����С 
	//ͷ����ʼ�� 
	a = (pnode)malloc(size);
	a->next = NULL;
	a->data = 0;
	
	pnode q;
	tail = a;//��ʼָ��ͷ��� 
	for(int i = 0;i < N;i ++)
	{//��ʼһ�����
		// 
		q = (pnode)malloc(size);
		q->next = NULL;
		q->data = 0;//0��ʾû������ 
		//���ӽ�� 
		tail->next = q;
		tail = q;
	}
	//tail��Ϊ��βԪ��ָ��
	tail->next = a;//Ȼ��ͷβ���� �γ�ѭ������
	
	a->front = a->rear = a->next;//��ʼ��ͷָ�룬βָ��ָ�� ��һ����λ����ʼ��Ϊ������ָ��ͷ����һ��λ�� 
	return a;
}

//��� �ɹ�����1������-1 
int push(pnode a,int elem)
{	
	
	if(a->rear->next == a->front)//βָ�����һ�������ͷָ��ָ����� ˵����������һ���ռ䲻�洢�� 
	{
		return -1;
	}
	else//��ʼ��� 
	{
		a->rear->data = elem;
		a->lenth ++;
		a->rear = a->rear->next;
	}
	
	return 1;
}
//���� �����س���Ԫ�� ����ʧ�ܷ���-1 �ɹ�����0 
int pop(pnode a)
{
	//���βָ�� ����ͷָ�룬��Ϊ�� 
	if(a->rear == a->front)
	{
		return -1;
	}
	//�Ӷ�ͷ���� 
	a->front->data = 0;
	a->lenth --;//����Ԫ�� ��һ 
	a->front = a->front->next;//��ͷ����� 
	
	return 0;//�ɹ�����0 
}

//������ 
int main()
{
	pnode a;
	//����ѭ�����г���Ϊ�궨��N 
	a = create_round_queue(); 
	//�鿴����
	print_pnode(a);//�鿴������� 
	//push
	push(a,3);
	push(a,13);
	push(a,-3);
	push(a,3);
	push(a,13);
	push(a,-3);
	push(a,3);
	push(a,13);
	push(a,-3);
	print_pnode(a);
	//pop
	pop(a);
	pop(a);
	print_pnode(a);
	
	return 0;
}
//��ӡ ѭ��������ͷָ�뿪ʼ�� 
void print_pnode(pnode a)
{
	
	pnode head = a;//��ͷ��㿪ʼ 
	
	while(head->next != a)//�����һ�������ͷ��� ˵������һȦ������ 
	{
		
		printf("%d ",head->data);
		head = head->next;//���� 
	}
	printf("\n");
	return;
}
  
