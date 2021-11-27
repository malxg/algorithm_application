/*
ʵ��˳���ľ͵�����,������ԭ��Ĵ洢�ռ佫���Ա����á� 
*/
#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10
#include <stdio.h>

typedef struct{
	int elem[LIST_INIT_SIZE];//�洢�ռ�Ļ�ַ 
	int length;//��ǰ���� 
	int listsize;//��ǰ����Ĵ洢���� 
}SqList;//˳������� 
 
//���� 
void inverse(SqList &a)
{
	int e = 0;//��Ϊ�н�
	for(int i = 0;i < a.length/2;i ++)
	{
		//���� 
		e = a.elem[a.length - 1 - i];
		a.elem[a.length - 1 - i] = a.elem[i];
		a.elem[i] = e;
	} 
	return;
}
//��ӡ���Ա� 
void print_sq(SqList a);


int main()
{
	SqList a;
	//��ʼ�� 
	a.length = 5;
	a.listsize = LIST_INIT_SIZE;
	for(int i = 0;i < a.length;i ++)
	{
		a.elem[i]= i;//��ֵ 
	}
	//��ӡ 
	print_sq(a);
	
	//���� 
	inverse(a);
	//��ӡ 
	print_sq(a);
	
	return 0;
}

//��ӡ���Ա� 
void print_sq(SqList a)
{
	for(int i = 0;i < a.length;i ++)
	{
		printf("%d ",*(a.elem + i));
	}
	printf("\n");
	return;
}
