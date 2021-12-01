/*
�Դ�ͷ����ѭ�������ʾ���У�����ֻ��һ��ָ��ָ���βԪ�ؽ�㣨����ͷָ�룩��
ʵ�ֶ��еĳ�ʼ������Ӻͳ��ӡ� 
*/

#include <stdio.h>
#include <malloc.h>
#define N 10

typedef struct node{
	int data;
	struct node* next;
}node,*pnode;
//��ӡ ѭ��������ͷ��㿪ʼ�� 
void print_pnode(pnode a);
//����ѭ������ ������ݶ�Ϊ0 Ϊ�� 
pnode tail;//ָ���β��ָ��
pnode create_round_queue()
{
	node *a;//ͷ��㲻�������ݷ�ͷָ�� 
	int size = sizeof(node);//����С 
	//ͷ����ʼ�� 
	a = (pnode)malloc(size);
	a->next = NULL;
	a->data = 0;
	
	pnode q;
	tail = a;//��ʼָ��ͷ��� 
	for(int i = 0;i < N;i ++)
	{
		//��ʼһ����� 
		q = (pnode)malloc(size);
		q->next = NULL;
		q->data = 0;//0��ʾû������ 
		//���ӽ�� 
		tail->next = q;
		tail = q;
	}
	//tail��Ϊ��βԪ��ָ�� 
	tail->next = a;//Ȼ��ͷβ���� �γ�ѭ������ 
	tail = a->next;//��ʼ��βָ��ָ�� ��һ����λ����ʼ��Ϊ������ָ��ͷ����һ��λ�� 
	
	
	return a;
}

//��� �ɹ�����1������-1 
int push(pnode a,int elem)
{	
	if(tail == a)//ͷָ�벻�������� 
	{
		tail = tail->next;//����ͷָ�� 
	}
	if(tail->data == 0)//Ϊ��
	{
		//���ڿռ��Ѿ�������ϣ�ֻ��Ҫ����ֵ 
		tail->data = elem;
		tail = tail->next;
	}
	else//���� ���ʧ�� 
	{
		return -1;
	}
	
	
	return 1;
}
//���� �����س���Ԫ�� ����ʧ�ܷ���-1 �ɹ�����0 
int pop(pnode a)
{
	//����û������ͷָ�� ֻ�ܴ�ͷ��㿪ʼ �����ѯ��һ��Ԫ�� 
	pnode head = a;
	//��ѯ 
	head = head->next;//���� 
	while(head->data == 0)
	{
		head = head->next;//����
		if(head == a)//����һȦ ȫ��0��˵������ʧ�� 
		{
			return -1;//���� -1 
		} 
	}
	//�ҵ�
	head->data = 0;//��Ϊ0 ��Ϊɾ������ 
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
	
	pnode head = a->next;//��ͷ��㿪ʼ 
	
	while(head->next != a)//�����һ�������ͷ��� ˵������һȦ������ 
	{
		
		printf("%d ",head->data);
		head = head->next;//���� 
	}
	printf("\n");
	return;
}
 
