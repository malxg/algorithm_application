/*
生成两个多项式PA PB，求PA和PB之和，输出 “和多项式” 
*/
//#include <iostream>
//using namespace std;

#include <stdio.h>
#include <malloc.h>//包含 malloc 申请动态空间 函数 
//结构体 
typedef struct PNode
{
    double coef;            //系数
    int expn;              //指数
    struct PNode *next;    //指针域
}PNode,*Plink;
 
//构建 单链表 
Plink generate_polynomial()
{
	printf("build star: \n");
	PNode *q,*p1,*head;
	
	// 注意 按降幂 次序 输入！！！ 方便 后面 比对 指数，省去 归并 链表的 按指数 排序 这一步骤 
	
	p1 = (PNode *)malloc(sizeof(PNode));//申请第一个 元素的空间 
	scanf("%lf%d",&p1->coef,&p1->expn);//输入 系数 指数 
    printf("系数/指数:%.2lfx^%d\n",p1->coef,p1->expn);
	
	head = p1;//保存 首结点地址 ，这个 指针始终 指向首结点 
	
	while(1)
	{

		//造 q结点 
		q = (PNode *)malloc(sizeof(PNode));//申请元素的空间 
		scanf("%lf",&q->coef);//输入 系数 
		q->next = NULL;
		if(q->coef == 0)//判断 系数为 结束 标志 
		{
			free(q);
			break;
		}
		
		scanf("%d",&q->expn);//输入 指数 
		
		if(q->expn == 0)//结束 标志 
		{
			printf("系数/指数:%.2lf\n",q->coef);
		}
		else
			printf("系数/指数:%.2lfx^%d\n",q->coef,q->expn);
		
		//连接 q结点 
		p1->next = q;
		p1 = q;
		q = q->next;
	}
	printf("end\n");
	return head;
}


//当两个多项式 底数一样 时 都为 x 
void add_polynomial(PNode *p1,PNode *p2)
{
    PNode *q1 = p1,*q2 = p2;//局部 指针 防止 修改原 首结点指针 
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
	
	//输入 生成 两个 多项式 
	head1 = generate_polynomial();
	head2 = generate_polynomial();
	
	add_polynomial(head1,head2);//多项式 相加 
	
	//释放 两个链表 空间 
	release_link(head1);
	release_link(head2);
	
	return 0;
}
