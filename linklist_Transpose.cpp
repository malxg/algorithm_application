/*
�� ���Ա� �� ������ �� �洢 �ṹ����ʵ�� ���Ա�� ת�� 
�����Ա�a0,a1,a2,......,an-1���͵�����
������ �ռ� O(1) 
*/

#include <stdio.h>
#include <malloc.h>
//������ 
typedef struct node{
	
	int data;//data ֵ 
	struct node *next;//next
	
}node,*list;

//transpose linklist
void transpose_list(list &head)
{
	
	list p = head,s;
	head = NULL;
	
	while(p != NULL)
	{
		//�� ���ڵ� ͷ��� ȡ���� 
		s = p;
		p = p->next;//pָ�� ��ǰ ͷ��� �ĺ�һλ 
		s->next = head;//Ȼ�� ��sָ�� ֮ǰȡ�����Ľ�㣬�൱�� ָ�� ԭ�ȵ� ǰ�� ��㣬 
		//��ת next ָ��ǰ�� 
		head = s; //��Ϊ�� ��� ͷ��� 
	} 
	
	return;
}

//�洢 �ṹ Ϊ ���Ա� �Ĵ��� 
typedef struct Sqlist{
	int *elem;//data ���� 
	int length;//current length
}Sqlist;

//Sqlist_one
void transpose_Sqlist_one(Sqlist &L)
{
	
	int temp;
	//����  ������ ˫������ ����ͷ ���м� �� 
	for(int i = 0;i < L.length / 2;i ++)//nΪl.lenght 
	{
		
		temp = L.elem[i];
		L.elem[i] = L.elem[L.length - i - 1];
		L.elem[L.length - i - 1] = temp;
		
	}
	return;
}

//Sqlist_two
void transpose_Sqlist_two(Sqlist &L)
{
	int i = 0,j = L.length - 1,temp = 0;
	
	//������ ˫������ ����ͷ ���м� �� 
	while(i < j)
	{
		temp = L.elem[i];
		L.elem[i] = L.elem[j];
		L.elem[j] = temp;
		
		i ++;j --;
	}
	return;;
}

void print_list(list L)
{
	
	L = L->next;
	printf("linklist :");
	while(L->data != NULL)
	{
		printf("%d  ",L->data);
		L = L->next;
	}
	
	return;
}

void print_Sqlist(Sqlist L)
{
	printf("Sqlist :");
	for(int i = 0;i < L.length;i ++)
	{
		printf("%d  ",L.elem[i]);
	}
	printf("\n");
	return;
}

//main ���� ���� 
int main()
{
	
	/******************linklist test**************************/
	
	list head,q;
	head->next = NULL;
    head->data = 0;

	int list_length = 10;
	q = head;
	while(list_length != 0)//��ֵ9 8 7 6 5 4 3 2 1 0 
	{
		list_length --;
		
		list p = (list)malloc(sizeof(node));//���� ��� 
		p->next = NULL;
		p->data = list_length;//���� ������ 
		
		
		q->next = p;
		q = p;
	}
	
	transpose_list(head);//ת�� ������ 
	
	print_list(head);//print
	//�ͷ� ����Ľ�� �ռ䣨���� ���� ��� ��ӡ ���� �� 
	while(head != NULL)
	{
		head = head->next;
		delete head;
	}
	printf("\n");
	
	/******************linklist test**************************/
	
	//ע�� �������� ���� ��Ҫ ͬʱ ���� ������ ���� ��� ����һ�� ���� ������ӡ ���� ֵ������ ����ֱ� ���� 
	
	/******************Sqlist test**************************/
	/* 
	Sqlist L;
	L.length = 10;
	for(int i = L.length - 1;i >= 0;i --)//��ֵ 9 8 7 6 5 4 3 2 1 0 
	{
		L.elem[L.length - i - 1] = i; 
	}
	
	//transpose_Sqlist_one(L);//one method ת�� ���Ա� 
	transpose_Sqlist_two(L);//two method ת�� ���Ա� 
	
	print_Sqlist(L);
	
	/*****************Sqlist test***************************/
	
	return 0;
}
 
