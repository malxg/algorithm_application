/*
��� Լɪ�� ���⡣
��39����̫�˾�����Ը��Ҳ��Ҫ������ץ�������Ǿ�����һ����ɱ��ʽ��41�����ų�һ��ԲȦ���ɵ�1���˿�ʼ������
ÿ��������3�˸��˾ͱ�����ɱ��Ȼ��������һ�����±�����ֱ�������˶���ɱ����Ϊֹ��Ȼ��Josephus ���������Ѳ�������ӡ�
���ȴ�һ���˿�ʼ��Խ��k-2���ˣ���Ϊ��һ�����Ѿ���Խ��������ɱ����k���ˡ����ţ���Խ��k-1���ˣ���ɱ����k���ˡ�
�����������ԲȦһֱ���У�ֱ������ֻʣ��һ�������£�����˾Ϳ��Լ������š�
�����ǣ������˺ͣ�һ��ʼҪվ��ʲô�ط����ܱ��ⱻ������JosephusҪ���������ȼ�װ��ӣ�
�����������Լ������ڵ�16�����31��λ�ã������ӹ����ⳡ������Ϸ���� 

���� ��� Լɪ�� ����(�ظ� ֱ�������� ���� )
��n=8,m=4,s=1 �����У�4,8,5,2,1,3,7,6 
*/
//#include <iostream>
//using namespace std;

#include <stdio.h>
#include <malloc.h>//���� malloc ���� 

typedef struct person{
	int index;
	struct person *next;
}person;//���� �� �� �����ԣ����ж����� �͹��� ���ٸ� ��� 

//���� ������ 
person* generate_link(int n)
{
	printf("star: \n");
	person *q,*p1,*head;
	
	p1 = (person *)malloc(sizeof(person));//�����һ�� Ԫ�صĿռ� 
	p1->index = 1;
	int i = 2;
	
	
	head = p1;//���� �׽���ַ ����� ָ��ʼ�� ָ���׽�� 
	
	n = n - 1;
	while(n --)
	{

		//�� q��� 
		q = (person *)malloc(sizeof(person));//����Ԫ�صĿռ� 
		
		q->index = i ++;
		q->next = NULL;
		
		//���� q��� 
		p1->next = q;
		p1 = q;
		q = q->next;
	}
	
	//��λ ��� ̰���� ѭ�������� 
	p1->next = head;
	printf("end: \n");
	return head;
}
void josephus_solve(person *head,int m,int s)
{
	int count = 1;
	person *begin = head;
	
	while(begin->index != s)
	{
		begin = begin->next;
	}
	
	printf("����: ");
	person *q;//��¼ Ҫ���� ���� ���� �ͷſռ� 
	while(begin != NULL)
	{
	    
		count ++; //���� 
		
		//���� count �Ѿ� ������ ǰ�� ��count ++ ʵ�� ����һλ �� ������ 
		if(count == m)//��������� ��һ���� �Ƿ��� m���� ֱ������һ���˳��� 
		{
			count = 1;//��ʼ ��һ��Ϊ ��� 
			printf("%d ",begin->next->index);
			q = begin->next;
			begin->next = begin->next->next;
			free(q);
		}
		
		begin = begin->next;
		
		//ֻ��һ�� ���,ֱ�� ���� 
		if(begin->next == begin)//(ѭ�� ������ ָ�� �Լ� ˵�� û���������)
		{
			printf("%d ",begin->index);
			break; 
		}
		
	}
	
	printf("\n");
	return;
}

int main()
{
	int n = 0,m = 0,s = 0;
	person *p1;
	printf("n,m,s :");
	scanf("%d%d%d",&n,&m,&s);
	
	//���� ������ 
    p1 = generate_link(n);
	//��ʼ ���� �� �� ���� 
	josephus_solve(p1,m,s);
	
	return 0;
}
