/*
һ���������ѧ�š��������Ա����䡣����һ�����䣬��������еĽ��������������ڴ�������ɾ���ý�㡣 
*/
/*
������������a��b��������ѧ�š���������a����ɾ����b����ͬ��ͬѧ�ŵĽ�㡣 
*/

#include <stdio.h>
#include <malloc.h>//���붯̬�ռ� 
typedef struct node{ 
	int num;//ѧ��
	char name[30];//����
	char sex[20];//�Ա�
	int age;//���� 
	struct node *next;
}node,*stu;

//ɾ����ͬѧ�ŵĽ�� 
void deleteAge(stu a,int ages)//���� ͷ��� 
{
	stu p = a,q = NULL;//pָ�� ͷ���(������Ԫ��)
	while(p->next != NULL)
	{
		//Ѱ�� 
		if(p->next->age == ages)
		{
			//�ҵ���ɾ��
			q = p->next;//ָ��Ҫɾ����� 
			p->next = p->next->next;//�޳�Ҫ��ɾ���Ľ�� 
			free(q);//�ͷŸý�� 
		}//�ҵ���ͬʱ����ʹ p->next = p->next->next,���൱������ �����ˣ������ظ�ִ��p = p->next 
		else
		{
			p = p->next;//û���ҵ� ����Ҫp = p->next�������±��� 
		}
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
	stu a;//a,b�������� 
	int n = 0,ages = 0;//Ҫɾ���ĵ���ages�Ľ�� 
	printf("����೤:\n");
	scanf("%d",&n);
	//��ʼ��
	a = InitLink(a,n,1);//flag == 1�ֶ�¼�� 
	//�鿴��ʼ�����
	printf("a:\n");
	prinLink(a);
	//�鿴ɾ�����
	printf("To delete ages:\n");
	scanf("%d",&ages);
	deleteAge(a,ages);
	prinLink(a);//��ӡɾ�����a 
	//�ͷ�a,b,c����
	freeLink(a);
	
	return 0;
}
//��ʼ������,������n���
stu InitLink(stu a,int n,int flag)//flag Ϊ1ʱ˵����Ҫ�ֶ���ֵ��Ϊ0˵������Ҫ��ֵ 
{
	int size = sizeof(node);
	//����ͷ��� ������Ԫ�� 
	stu head;
	head = (stu)malloc(size);
	head->next = NULL;
	//�����������ݵ�n����� 
	stu p = head,q = NULL;
	for(int i = 0;i < n;i ++)
	{
		//����һ����� 
		q = (stu)malloc(size);
		q->num = 0;
		q->age = 0;
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
		printf("ѧ�š��������Ա�����\n"); 
		while(p != NULL)
		{
			scanf("%d%s%s%d",&p->num,&p->name,&p->sex,&p->age); 
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
		printf("%d %s %s %d\n",p->num,p->name,p->sex,p->age);
		p = p->next;
	}
	printf("----\n");
	return;
}
