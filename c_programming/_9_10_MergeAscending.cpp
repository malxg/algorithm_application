/*
已有a,b两个链表,每个链表包含学号、成绩。要求合并两个链表，按学号升序排列。 
*/
#include <stdio.h>
#include <malloc.h>//申请动态空间 
typedef struct node{
	int num;//学号
	float grade;//成绩
	struct node *next;
}node,*stu;

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

//按Ascending升序合并 两个链表,返回合并后链表头结点c 
stu mergeLink(stu a,stu b)//传入a,b链表的头结点指针 
{
	int size = sizeof(node);
	//开始合并 
	//构建一个c头结点保存合并结果 
	stu c = NULL;
	c = (stu)malloc(size);
	c->grade = 0;
	c->num = 0;
	//a,b并非一开始就升序 
	//先将a链表变成升序并插入在头指针为c中
	stu t = NULL,q = NULL;
	q = a->next;//指向第一个 放进c链的结点
	a->next = a->next->next;//剔除要放进c链的结点 
	
	c->next = q;//赋值第一个 放入c链
	q->next = NULL;//注意 新加入c链尾的的结点一定得初始化next指针
	t = c;//每次都从c链头找起 
	while(a->next != NULL)
	{
		
		//寻找插入点 
		if(a->next->num > t->next->num)
		{
			t = t->next;
			if(t->next == NULL)//说明下一次循环，会遍历到c链表末尾 
			{
				//即该结点大于c链表所有结点，应该插入 c链表末尾
				//从a链中剔除该结点
				q = a->next;
				a->next = a->next->next;
				//把该结点放在c链的末尾 
				q->next = NULL;//注意 新加入c链尾的的结点一定得初始化next指针
				t->next = q;
				//插入后说明 该结点插入完毕，下一次结点 初始化开头 
				t = c;//每次都从c链头找起 
			}
		}
		else//找到 
		{
			//从a链中剔除该结点 
			q = a->next;
			a->next = a->next->next;
			//把该结点放在c链中合适位置
			q->next = t->next; 
			t->next = q;
			
			//插入后说明 该结点插入完毕，下一次结点 初始化开头 
			t = c;//每次都从c链头找起 
		}
	}
	
	//再 将b链表中 学号升序插入到c中 
	q = NULL;//初始 
	t = c;//每次都从c链头找起 
	while(b->next != NULL)
	{
		
		//寻找插入点 
		if(b->next->num > t->next->num)
		{
			t = t->next;
			if(t->next == NULL)//说明下一次循环，会遍历到c链表末尾 
			{
				//即该结点大于c链表所有结点，应该插入 c链表末尾
				//从b链中剔除该结点
				q = b->next;
				b->next = b->next->next;
				//把该结点放在c链的末尾 
				q->next = t->next; 
				t->next = q;
				
				//插入后说明 该结点插入完毕，下一次结点 初始化开头 
				t = c;//每次都从c链头找起 
			}
		}
		else//找到 
		{
			//从b链中剔除该结点 
			q = b->next;
			b->next = b->next->next;
			//把该结点放在c链中合适位置
			q->next = t->next; 
			t->next = q;
			
			//插入后说明 该结点插入完毕，下一次结点 初始化开头 
			t = c;//每次都从c链头找起 
		}
	}
	return c;
}

//打印链表结点元素 
void prinLink(stu a);
//释放链表(传入头指针) 
void freeLink(stu head);
int main()
{
	stu a,b,c;//a,b两个链表 
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
	//查看合并结果
	c = mergeLink(a,b);
	printf("c:\n");
	prinLink(c);
	
	//释放a,b,c链表
	freeLink(a);
	freeLink(b); 
	freeLink(c); 
	
	return 0;
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
