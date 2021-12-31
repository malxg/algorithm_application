/*
����a,b��������,ÿ���������ѧ�š��ɼ���Ҫ��ϲ�����������ѧ���������С� 
*/
#include <stdio.h>
#include <malloc.h>//���붯̬�ռ� 
typedef struct node{
	int num;//ѧ��
	float grade;//�ɼ�
	struct node *next;
}node,*stu;

//��ʼ������,������n���
stu InitLink(stu a,int n,int flag)//flag Ϊ1ʱ˵����Ҫ�ֶ���ֵ��Ϊ0˵������Ҫ��ֵ 
{
	int size = sizeof(node);
	//����ͷ��� ������Ԫ�� 
	stu head;
	head = (stu)malloc(size);
	head->grade = 0;
	head->num = 0;
	
	//�����������ݵ�n����� 
	stu p = head,q = NULL;
	for(int i = 0;i < n;i ++)
	{
		//����һ����� 
		q = (stu)malloc(size);
		q->grade = 0;
		q->num = 0;
		q->next = NULL;
		//�ѽ���������ͷ�巨��
		p->next = q;
		p = q;
		q = NULL; 
	}
	p->next = NULL;
	
	//flagΪ1˵���ֶ���ֵ 
	if(flag == 1)
	{
		//����̨¼�� ��ֵ,�ֶ���ֵ(β�巨 ����Ԫ��)
		p = head->next;
		while(p != NULL)
		{
			scanf("%d%f",&p->num,&p->grade); 
			p = p->next;
		}
		printf("\n");
	} 
	
	return head;
}

//��Ascending����ϲ� ��������,���غϲ�������ͷ���c 
stu mergeLink(stu a,stu b)//����a,b�����ͷ���ָ�� 
{
	int size = sizeof(node);
	//��ʼ�ϲ� 
	//����һ��cͷ��㱣��ϲ���� 
	stu c = NULL;
	c = (stu)malloc(size);
	c->grade = 0;
	c->num = 0;
	//a,b����һ��ʼ������ 
	//�Ƚ�a���������򲢲�����ͷָ��Ϊc��
	stu t = NULL,q = NULL;
	q = a->next;//ָ���һ�� �Ž�c���Ľ��
	a->next = a->next->next;//�޳�Ҫ�Ž�c���Ľ�� 
	
	c->next = q;//��ֵ��һ�� ����c��
	q->next = NULL;//ע�� �¼���c��β�ĵĽ��һ���ó�ʼ��nextָ��
	t = c;//ÿ�ζ���c��ͷ���� 
	while(a->next != NULL)
	{
		
		//Ѱ�Ҳ���� 
		if(a->next->num > t->next->num)
		{
			t = t->next;
			if(t->next == NULL)//˵����һ��ѭ�����������c����ĩβ 
			{
				//���ý�����c�������н�㣬Ӧ�ò��� c����ĩβ
				//��a�����޳��ý��
				q = a->next;
				a->next = a->next->next;
				//�Ѹý�����c����ĩβ 
				q->next = NULL;//ע�� �¼���c��β�ĵĽ��һ���ó�ʼ��nextָ��
				t->next = q;
				//�����˵�� �ý�������ϣ���һ�ν�� ��ʼ����ͷ 
				t = c;//ÿ�ζ���c��ͷ���� 
			}
		}
		else//�ҵ� 
		{
			//��a�����޳��ý�� 
			q = a->next;
			a->next = a->next->next;
			//�Ѹý�����c���к���λ��
			q->next = t->next; 
			t->next = q;
			
			//�����˵�� �ý�������ϣ���һ�ν�� ��ʼ����ͷ 
			t = c;//ÿ�ζ���c��ͷ���� 
		}
	}
	
	//�� ��b������ ѧ��������뵽c�� 
	q = NULL;//��ʼ 
	t = c;//ÿ�ζ���c��ͷ���� 
	while(b->next != NULL)
	{
		
		//Ѱ�Ҳ���� 
		if(b->next->num > t->next->num)
		{
			t = t->next;
			if(t->next == NULL)//˵����һ��ѭ�����������c����ĩβ 
			{
				//���ý�����c�������н�㣬Ӧ�ò��� c����ĩβ
				//��b�����޳��ý��
				q = b->next;
				b->next = b->next->next;
				//�Ѹý�����c����ĩβ 
				q->next = t->next; 
				t->next = q;
				
				//�����˵�� �ý�������ϣ���һ�ν�� ��ʼ����ͷ 
				t = c;//ÿ�ζ���c��ͷ���� 
			}
		}
		else//�ҵ� 
		{
			//��b�����޳��ý�� 
			q = b->next;
			b->next = b->next->next;
			//�Ѹý�����c���к���λ��
			q->next = t->next; 
			t->next = q;
			
			//�����˵�� �ý�������ϣ���һ�ν�� ��ʼ����ͷ 
			t = c;//ÿ�ζ���c��ͷ���� 
		}
	}
	return c;
}

//��ӡ������Ԫ�� 
void prinLink(stu a);
//�ͷ�����(����ͷָ��) 
void freeLink(stu head);
int main()
{
	stu a,b,c;//a,b�������� 
	int n,m,i = 0;//a��b��������Ĵ�С
	
	//����̨¼��a������ʼ�� a����
	scanf("%d",&n);
	a = InitLink(a,n,1);//�ֶ���ֵ 
	//��ʼb 
	scanf("%d",&m);
	b = InitLink(b,m,1);//�ֶ���ֵ 
	
	
	//�鿴��ʼ�����
	printf("a:\n");
	prinLink(a);
	printf("b:\n");
	prinLink(b);
	//�鿴�ϲ����
	c = mergeLink(a,b);
	printf("c:\n");
	prinLink(c);
	
	//�ͷ�a,b,c����
	freeLink(a);
	freeLink(b); 
	freeLink(c); 
	
	return 0;
}
//�ͷ�����(����ͷָ��) 
void freeLink(stu head)
{
	stu q = NULL;
	//ͷ�巨 �ͷ�Ԫ�� 
	while(head->next != NULL)
	{
		q = head->next;//Ҫ�ͷŽ�� 
		head->next = head->next->next;//�޳��ý�� 
		free(q);//�ͷ�������޳��� ��� 
	}
	free(head);//�ͷ�ͷָ�� 
	q = head = NULL;//��ʼ�� ָ�� 
	return;
}
//��ӡ������Ԫ�� 
void prinLink(stu a)
{
	stu p = a->next;
	while(p != NULL)
	{
		printf("%d %.2f\n",p->num,p->grade);
		p = p->next;
	}
	printf("----\n");
	return;
}
