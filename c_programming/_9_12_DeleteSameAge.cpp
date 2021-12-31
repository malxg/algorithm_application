/*
一个链表包括学号、姓名、性别、年龄。输入一个年龄，如果链表中的结点所包含年龄等于此年龄则删除该结点。 
*/
/*
已有两个链表a、b，结点包含学号、姓名。从a表中删除与b表相同相同学号的结点。 
*/

#include <stdio.h>
#include <malloc.h>//申请动态空间 
typedef struct node{ 
	int num;//学号
	char name[30];//姓名
	char sex[20];//性别
	int age;//年龄 
	struct node *next;
}node,*stu;

//删除相同学号的结点 
void deleteAge(stu a,int ages)//传入 头结点 
{
	stu p = a,q = NULL;//p指向 头结点(不保存元素)
	while(p->next != NULL)
	{
		//寻找 
		if(p->next->age == ages)
		{
			//找到后删除
			q = p->next;//指向要删除结点 
			p->next = p->next->next;//剔除要被删除的结点 
			free(q);//释放该结点 
		}//找到的同时，会使 p->next = p->next->next,故相当于向下 遍历了，不用重复执行p = p->next 
		else
		{
			p = p->next;//没有找到 就需要p = p->next继续向下遍历 
		}
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
	stu a;//a,b两个链表 
	int n = 0,ages = 0;//要删除的等于ages的结点 
	printf("链表多长:\n");
	scanf("%d",&n);
	//初始化
	a = InitLink(a,n,1);//flag == 1手动录入 
	//查看初始化结果
	printf("a:\n");
	prinLink(a);
	//查看删除结果
	printf("To delete ages:\n");
	scanf("%d",&ages);
	deleteAge(a,ages);
	prinLink(a);//打印删除后的a 
	//释放a,b,c链表
	freeLink(a);
	
	return 0;
}
//初始化链表,长度有n结点
stu InitLink(stu a,int n,int flag)//flag 为1时说明需要手动赋值，为0说明不需要赋值 
{
	int size = sizeof(node);
	//构建头结点 不包含元素 
	stu head;
	head = (stu)malloc(size);
	head->next = NULL;
	//构建保存数据的n个结点 
	stu p = head,q = NULL;
	for(int i = 0;i < n;i ++)
	{
		//创建一个结点 
		q = (stu)malloc(size);
		q->num = 0;
		q->age = 0;
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
		printf("学号、姓名、性别、年龄\n"); 
		while(p != NULL)
		{
			scanf("%d%s%s%d",&p->num,&p->name,&p->sex,&p->age); 
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
		printf("%d %s %s %d\n",p->num,p->name,p->sex,p->age);
		p = p->next;
	}
	printf("----\n");
	return;
}
