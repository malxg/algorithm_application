/*
��˳���va�е�����Ԫ�ص���������ʵ�ֽ�x����
��˳�����ʵ�λ���ϣ�����ñ�������ԡ� 
*/
#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10
#include <stdio.h>

typedef struct{
	int *elem;//�洢�ռ�Ļ�ַ 
	int length;//��ǰ���� 
	int listsize;//��ǰ����Ĵ洢���� 
}SqList;//˳������� 
 
//��ӡ���Ա� 
void print_sq(SqList a);

//����λ�ò���Ԫ��x 
void insert(SqList &a,int x)
{
	//����
	for(int i = 0;i < a.length;i ++)
	{
		//printf("1");
		if(*(a.elem + i) > x || i == a.length - 1)
		{
			if(i == a.length - 1 && *(a.elem + i) < x)//������Ҫ ��λ����� 
			{
				*(a.elem + a.length) = x;//ֱ�Ӳ��뵽ĩβ����һ���ռ� 
			}
			else//���� ��һ�� ����x��Ԫ�أ�˵��������ǲ����
			{
			//	printf("2");
				//��λ�õ�Ԫ��ȫ������ƶ�һ��λ�� 
				for(int j = a.length;j > i;j --)
				{
					*(a.elem + j) = *(a.elem + j - 1);
				}
			//	printf("3");
				//��λ��� ���� 
				*(a.elem + i) = x;
			//	printf("4");
			}
			
			a.length = a.length + 1;//����һ��Ԫ�� ����+1 
			break; //����x��� �˳� 
		}
		//������  
	} 
	
	return;
}


int main()
{
	SqList a;
	//��ʼ�� 
	a.length = 5;
	a.listsize = LIST_INIT_SIZE;
	for(int i = 0;i < a.length;i ++)
	{
		*(a.elem + i) = i;//��ֵ 
	}
	//��ӡ 
	print_sq(a);
	
	//����
	int x = 0;
	while(1)
	{
		printf("���� ��0 Ϊ������\n");
		scanf("%d",&x);
		if(x == 0)
		{
			break;
		}
		insert(a,x);
		//�ٴδ�ӡ
		print_sq(a);
	}

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
