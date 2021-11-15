/*
������������ʽPA PB����PA��PB֮�ͣ���� ���Ͷ���ʽ�� 
*/
//#include <iostream>
//using namespace std;

#include <stdio.h>
#include <malloc.h>//���� malloc ���붯̬�ռ� ���� 
//�ṹ�� 
typedef struct PNode
{
    double coef;            //ϵ��
    int expn;              //ָ��
    struct PNode *next;    //ָ����
}PNode,*Plink;
 
//���� ������ 
Plink generate_polynomial()
{
	printf("build star: \n");
	PNode *q,*p1,*head;
	
	// ע�� ������ ���� ���룡���� ���� ���� �ȶ� ָ����ʡȥ �鲢 ����� ��ָ�� ���� ��һ���� 
	
	p1 = (PNode *)malloc(sizeof(PNode));//�����һ�� Ԫ�صĿռ� 
	scanf("%lf%d",&p1->coef,&p1->expn);//���� ϵ�� ָ�� 
    printf("ϵ��/ָ��:%.2lfx^%d\n",p1->coef,p1->expn);
	
	head = p1;//���� �׽���ַ ����� ָ��ʼ�� ָ���׽�� 
	
	while(1)
	{

		//�� q��� 
		q = (PNode *)malloc(sizeof(PNode));//����Ԫ�صĿռ� 
		scanf("%lf",&q->coef);//���� ϵ�� 
		q->next = NULL;
		if(q->coef == 0)//�ж� ϵ��Ϊ ���� ��־ 
		{
			free(q);
			break;
		}
		
		scanf("%d",&q->expn);//���� ָ�� 
		
		if(q->expn == 0)//���� ��־ 
		{
			printf("ϵ��/ָ��:%.2lf\n",q->coef);
		}
		else
			printf("ϵ��/ָ��:%.2lfx^%d\n",q->coef,q->expn);
		
		//���� q��� 
		p1->next = q;
		p1 = q;
		q = q->next;
	}
	printf("end\n");
	return head;
}


//����������ʽ ����һ�� ʱ ��Ϊ x 
void add_polynomial(PNode *p1,PNode *p2)
{
    PNode *q1 = p1,*q2 = p2;//�ֲ� ָ�� ��ֹ �޸�ԭ �׽��ָ�� 
	while(q1 != NULL && q2 != NULL)
    {
    	if(q1->expn == q2->expn)
		{
			printf("%.2lfx^%d ",q1->coef + q2->coef,q1->expn);
			q1 = q1->next;
			q2 = q2->next;
		}
		else if(q1->expn > q2->expn)
		{
			printf("%.2lfx^%d ",q1->coef,q1->expn);
			q1 = q1->next;
		}
		else
		{
			printf("%.2lfx^%d ",q2->coef,q2->expn);
			q2 = q2->next;
		}
	}
	
	if(q1 == NULL)
	{
		while(q2 != NULL)
		{
			printf("%.2lfx^%d ",q2->coef,q2->expn);
		    q2 = q2->next;
		    
		}
	}
	
	else if(q2 == NULL)
	{
		while(q1 != NULL)
		{
			printf("%.2lfx^%d ",q1->coef,q1->expn);
			q1 = q1->next;
		}
	}
	
	return;
}

void release_link(PNode *head)
{
	PNode *q,*p;
	q = p = head;
	while(q->next != NULL)
	{
		p = q->next;
		q->next = q->next->next;
		free(p);
	}
	free(head);
}

int main()
{
	PNode *head1,*head2;
	
	//���� ���� ���� ����ʽ 
	head1 = generate_polynomial();
	head2 = generate_polynomial();
	
	add_polynomial(head1,head2);//����ʽ ��� 
	
	//�ͷ� �������� �ռ� 
	release_link(head1);
	release_link(head2);
	
	return 0;
}
