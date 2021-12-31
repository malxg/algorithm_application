/*
已有两个链表a、b，结点包含学号、姓名。从a表中删除与b表相同相同学号的结点。 
*/

#include <stdio.h>
#include <malloc.h>//申请动态空间 
typedef struct node{
	int num;//学号
	float grade;//成绩
	struct node *next;
}node,*stu;

//从a表中删除与b链中学号相同结点 
void DeleteSame(stu a,stu b)
{
	stu p = a,q = b->next,t = NULL;//指向元素结点
	//判断链表是否合法 
	if(p->next == NULL || q == NULL)
	{
		printf("p or q没有元素！");
		return;
	}
	//链表合法 
	while(p->next != NULL)
	{
		//找相同结点
		q = b->next;//初始化b链表遍历指针，a中元素判断每次从b链首元结点开始（第一个元素结点，不包括头结点）  
		while(q != NULL)
		{

			//找 到后，初始化b遍历指针，然后结束本次循环 
			if(p->next->num == q->num)//-------------------------------------32行****
			{
				
				//找到后删除a链结点，并释放
				t = p->next;//t指向要删除结点，便于释放
				p->next = p->next->next;//从a链表中剔除该结点
				free(t);//释放被剔除结点
				break;
			}
			//如果没有找到，继续遍历b链表
			q = q->next;
		}
		//判断a链的一个元素完毕，继续判断下一个元素结点
		if(q == NULL)//如果是由于没有找到该元素，而退出
		{
			p = p->next;//则下一个判断的 元素，为p->next->next(因为每一次判断 都是判断p指向结点的下一个结点第32行****)
		}
		else;//是由于break,删除一个元素而退出，则 不变，下一个元素仍是p->next(因为每一次判断 都是判断p指向结点的下一个结点第32行****)
		 
	}
	
	return;
}
//初始化链表,长度有n结点
stu InitLink(stu a,int n,int flag);//flag 为1时说明需要手动赋值，为0说明不需要赋值 
//打印链表结点元素 
void prinLink(stu a);
//释放链表(传入头指针) 
void freeLink(stu head);
int main()
{
	stu a,b;//a,b两个链表 
	int n,m,i = 0;//a，b两个链表的大小
	
	//控制台录入a链表，初始化 a链表
	scanf("%d",&n);
	a = InitLink(a,n,1);//手动赋值 
	//初始b 
	scanf("%d",&m);
	b = InitLink(b,m,1);//手动赋值 
	
	
	//查看初始化结果
	printf("a:\n");
	prinLink(a);
	printf("b:\n");
	prinLink(b);
	//查看删除结果
	DeleteSame(a,b);//删除 
	printf("删除后a为:\n");
	prinLink(a);//再次看删除后的a 
	
	//释放a,b,c链表
	freeLink(a);
	freeLink(b); 
	
	return 0;
}
//初始化链表,长度有n结点
stu InitLink(stu a,int n,int flag)//flag 为1时说明需要手动赋值，为0说明不需要赋值 
{
	int size = sizeof(node);
	//构建头结点 不包含元素 
	stu head;
	head = (stu)malloc(size);
	head->grade = 0;
	head->num = 0;
	
	//构建保存数据的n个结点 
	stu p = head,q = NULL;
	for(int i = 0;i < n;i ++)
	{
		//创建一个结点 
		q = (stu)malloc(size);
		q->grade = 0;
		q->num = 0;
		q->next = NULL;
		//把结点加入链表（头插法）
		p->next = q;
		p = q;
		q = NULL; 
	}
	p->next = NULL;
	
	//flag为1说明手动赋值 
	if(flag == 1)
	{
		//控制台录入 数值,手动赋值(尾插法 构建元素)
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
//释放链表(传入头指针) 
void freeLink(stu head)
{
	stu q = NULL;
	//头插法 释放元素 
	while(head->next != NULL)
	{
		q = head->next;//要释放结点 
		head->next = head->next->next;//剔除该结点 
		free(q);//释放这个被剔除的 结点 
	}
	free(head);//释放头指针 
	q = head = NULL;//初始化 指针 
	return;
}
//打印链表结点元素 
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
