/*
13��Χ��һȦ���ӵ�һ���˿�ʼ˳�򱨺�1��2��3������3�˳����ҳ��������Ȧ���е���ԭ������š�������ʵ�֡� 
*/
#include <stdio.h>
#include <malloc.h>//����ռ� 
//�� ��� 
typedef struct node{
	int order;
	struct node *next;
}node,*people;

//����n����ΪһȦ�������α�� 
people create_link(people one,int n)
{
	int size = sizeof(node);//Ҫ����Ľ��ռ��С
	//��ʼ��һ���˿ռ� 
	one = (people)malloc(size);
	one->order = 1;
	one->next = NULL;
	people p = one,q = NULL;//��ʼ����ʣ�µ��� 
	
	for(int i = 2;i <= n;i ++)//��1��ʼ���
	{
		//����һ��'��' 
		q = (people)malloc(size);
		q->order = i;
		q->next = NULL;
		//���˼���Ȧ�� 
		p->next = q;
		p = q;
		//��ʼqָ�� 
		q = NULL;
	}
	//ע����һ��Ȧ Ҫ�γ�ѭ�� ����
	p->next = one;//���һ�����ˡ�ָ���һ��
	
	return one;//���ص�һ���� 
}

//��ʼѰ�� 
void find_LastOrder(int n)
{
	people one;//ָ����ʼ��һ����
	//�������� 
	one = create_link(one,n);
	if(one == NULL)
	{
		printf("��������ʧ�ܣ�");
		return;
	}
	
	//�����ɹ� 
	//��ʼѰ��
	people p = one,q;
	int i = 0;
	while(1)//�ҵ�Ϊֹ���ҵ���ֱ��break�ͷŵ� 
	{
		i = 1;
		//ɾ����3�ںŵ��ˣ�˵����ɾ����2�ں��˵� ��һλ 
		while(i != 2)//�ҵ����ں�Ϊ2���� 
		{
			i ++;
			p = p->next;
		}
		 
		if(p->next == p)//˵��ֻ��һ�����ˣ��Լ��ֱ��ں�2���ֵñ��ں�3����������һ�����ҵ��ɹ�
		{
			//��ӡ
			printf("���һ�������Ϊ%d\n",p->order);
			break; 
		}
		else//�����Ǹ��˳����� 
		{
			//ɾ�� ���˳�����
			q = p->next;//qָ��Ҫɾ���ģ���������ͷ� 
			p->next = p->next->next;//�޳�Ҫɾ�����ˣ�pָ��4����
			free(q);//�ͷ��޳����� 
		}
	}
	
	free(p);//�ͷ����һ���˵Ľ��
	one = q = p = NULL;//��ʼ��ָ��
	 
	return;	
}

int main()
{
	int n = 13;//�ж������ڶ��� 
	find_LastOrder(n);//�ҵ� ����ӡ��� 
	return 0;
}
