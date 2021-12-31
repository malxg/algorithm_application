/*
������������a��b��������ѧ�š���������a����ɾ����b����ͬ��ͬѧ�ŵĽ�㡣 
*/

#include <stdio.h>
#include <malloc.h>//���붯̬�ռ� 
typedef struct node{
	int num;//ѧ��
	float grade;//�ɼ�
	struct node *next;
}node,*stu;

//��a����ɾ����b����ѧ����ͬ��� 
void DeleteSame(stu a,stu b)
{
	stu p = a,q = b->next,t = NULL;//ָ��Ԫ�ؽ��
	//�ж������Ƿ�Ϸ� 
	if(p->next == NULL || q == NULL)
	{
		printf("p or qû��Ԫ�أ�");
		return;
	}
	//����Ϸ� 
	while(p->next != NULL)
	{
		//����ͬ���
		q = b->next;//��ʼ��b�������ָ�룬a��Ԫ���ж�ÿ�δ�b����Ԫ��㿪ʼ����һ��Ԫ�ؽ�㣬������ͷ��㣩  
		while(q != NULL)
		{

			//�� ���󣬳�ʼ��b����ָ�룬Ȼ���������ѭ�� 
			if(p->next->num == q->num)//-------------------------------------32��****
			{
				
				//�ҵ���ɾ��a����㣬���ͷ�
				t = p->next;//tָ��Ҫɾ����㣬�����ͷ�
				p->next = p->next->next;//��a�������޳��ý��
				free(t);//�ͷű��޳����
				break;
			}
			//���û���ҵ�����������b����
			q = q->next;
		}
		//�ж�a����һ��Ԫ����ϣ������ж���һ��Ԫ�ؽ��
		if(q == NULL)//���������û���ҵ���Ԫ�أ����˳�
		{
			p = p->next;//����һ���жϵ� Ԫ�أ�Ϊp->next->next(��Ϊÿһ���ж� �����ж�pָ�������һ������32��****)
		}
		else;//������break,ɾ��һ��Ԫ�ض��˳����� ���䣬��һ��Ԫ������p->next(��Ϊÿһ���ж� �����ж�pָ�������һ������32��****)
		 
	}
	
	return;
}
//��ʼ������,������n���
stu InitLink(stu a,int n,int flag);//flag Ϊ1ʱ˵����Ҫ�ֶ���ֵ��Ϊ0˵������Ҫ��ֵ 
//��ӡ������Ԫ�� 
void prinLink(stu a);
//�ͷ�����(����ͷָ��) 
void freeLink(stu head);
int main()
{
	stu a,b;//a,b�������� 
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
	//�鿴ɾ�����
	DeleteSame(a,b);//ɾ�� 
	printf("ɾ����aΪ:\n");
	prinLink(a);//�ٴο�ɾ�����a 
	
	//�ͷ�a,b,c����
	freeLink(a);
	freeLink(b); 
	
	return 0;
}
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
