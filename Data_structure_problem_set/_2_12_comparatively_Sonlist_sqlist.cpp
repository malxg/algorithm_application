/*
��A,B����˳���a,b�ֱ�ΪA,B�г�ȥ���ͬǰ׺����ӱ�
��a==b==NULL,��A==B;��aΪ�գ���b��Ϊ�գ��������߶���Ϊ�գ�
��a����ԪС��b����Ԫ����A<B������A>B��дһ���Ƚ�A,B��С���㷨�� 
*/
#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10
#include <stdio.h>

typedef struct{
	char *elem;//�洢�ռ�Ļ�ַ 
	int length;//��ǰ���� 
	int listsize;//��ǰ����Ĵ洢���� 
}SqList;//˳������� 
 
//��ӡ���Ա� 
void print_sq(SqList a);
int mmax(int a,int b)
{
	return a > b ? a : b;
}
//����λ�ò���Ԫ��x 
void comparatively(SqList A,SqList B)
{
	//����
	int max = mmax(A.length,B.length);//�ó���������Ա� ���������� 
	int i = 0;
	for(i = 0;i < max;i ++)
	{
		
		if(*(A.elem + i) == *(B.elem + i))//1 
		{
			continue;
		}
		//������� �ӱ�ֱ�ӱ߶Աȱ߱Ƚ� 
		if(*(A.elem + i) > *(B.elem + i))//��� ǰ�� ���� ���� 
		{
			printf("A > B");
			break;
		}
		else
		{
			printf("A < B");
			break;
		}
		
	}
	if(i == max)//˵���Ա����ˣ�û�в��� 
	{
		printf("A = B"); 
	}
	
	return;
}


int main()
{
	SqList A,B;//A,B 
	//��ʼ�� 
	A.length = 6;
	A.listsize = LIST_INIT_SIZE;
	B.length = 8;
	B.listsize = LIST_INIT_SIZE;
	
	//��ʼA���� 
	printf("AԪ��\n");
	char *a = "xyyzxz";
	A.elem = a;//��ֵ A.length ��Ԫ�� 
	//��ӡ A
	print_sq(A);
	
	//��ʼB���� 
	printf("BԪ��:\n");
	char *b = "xyyzyxxz";
	
	B.elem = b;//��ֵ B.length ��Ԫ��
	//��ӡ B
	print_sq(B);
	
	//�Ƚ� 
	comparatively(A,B);

	return 0;
}

//��ӡ���Ա� 
void print_sq(SqList a)
{

	for(int i = 0;i < a.length;i ++)
	{
		printf("%c ",*(a.elem + i));
	}
	printf("\n");
	return;
}
