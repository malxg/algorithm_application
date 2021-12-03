/*
以结点大小为1，且带有头结点的链表结构表示串，
实现串的六种串的基本操作StrAssign,StrCopy,StrCompare,
StrLength,Concat和SubString的函数 
*/

//结点 
typedef struct node{
	char data;
	struct node *next;
}node,*pnode;
#include <stdio.h>
#include <malloc.h>
#define N 51
//依据字符数组 构建 链队列
pnode create_link(char c[]);
//释放链队列
void free_link(pnode a);
//打印 串 
void print_linkstring(pnode a);
//成员函数assign()用于分配，把一个 string b对象的从index下标开始的部分内容拷贝到另一个 string a对象上并覆盖原数据。
pnode StrAssign(pnode a,pnode b,int index);//--1
//串的复制 操作 b复制给a 
pnode StrCopy(pnode a,pnode b);//--2
//串的比较操作 
void StrCompare(pnode a,pnode b);//--3
//获取串的长度 
int StrLength(pnode a);//--4
//串的连接 b连接到a的末尾 
pnode Concat(pnode a,pnode b);//--5
//用于截取字符串的某部分，其基本语法为substring(字符串,起始位置(下标),截取长度)
pnode SubString(pnode a,int begin,int length);//--6

//主函数 
int main()
{
	//test_one
	pnode a,b,sub;
	char c1[N] = {'a','b','c','d','e','f','g','h','f','a','b','c','d','e','f','g','h','f'};
	char c2[N] = {'a','b','g','f','e','d','c','b','a'};
	a = create_link(c1);b = create_link(c2);//依据字符数组 构建链队列 
	//打印各串
	print_linkstring(a);
	print_linkstring(b);
//	print_string(sub);

	//test each function
	
	//a = StrAssign(a,b,2);//分配 --1
	//print_linkstring(a);
	
	
	
	//a = StrCopy(a,b);//--2
	//print_linkstring(a);
	
	
	
	//StrCompare(a,b);//--3
	
	
	
	//printf("a: %d b: %d",StrLength(a),StrLength(b));//--4
	
	
	
	//Concat(a,b);//--5
	//print_linkstring(a);
	
	
	
	sub = SubString(a,10,3);
	print_linkstring(sub);
	
	
	//释放a,b 
	free_link(a);
	free_link(b);
	
	return 0;
}

//成员函数assign()用于分配，把一个 string b对象的从 index下标 开始的部分内容拷贝到另一个 string a对象上。
pnode StrAssign(pnode a,pnode b,int index)//--1
{
	//a，b不为空 
	if(a == NULL || b == NULL)
	{
		return NULL;
	}
	//由于是覆盖式拷贝 直接释放a就行
	free_link(a);
	
	//a为空后，开始寻找拷贝点,寻找到后，把后面值 赋值到数组，然后根据这个数组重新构造a链表 
	int count = 0;
	pnode p = b->next;
	while(p != NULL)
	{
		count ++;
		if(count == index + 1)//找到元素位置 
		{
			break;
		}
		p = p->next;
	}
	
	//字符数组
	char c[N] = {'\0'};
	int k = 0; 
	while(p != NULL)
	{
		c[k ++] = p->data;
		p = p->next;
	}
	
	//然后依据这个矩阵 创建一个以a为头结点 的链表 
	a = create_link(c);

	return a;
}
//串的复制 操作 b复制给a 
pnode StrCopy(pnode a,pnode b)//--2
{
	//b不为空 
	if(b == NULL)
	{
		return NULL;
	}
	
	//由于是覆盖式拷贝 直接释放a就行
	free_link(a);
	
	//字符数组
	char c[N] = {'\0'};
	int k = 0;pnode p = b->next;
	while(p != NULL)
	{
		c[k ++] = p->data;
		p = p->next;
	}
	//然后依据这个矩阵 创建一个以a为头结点 的链表 
	a = create_link(c);
	
	return a;
}
//串的比较操作 
void StrCompare(pnode a,pnode b)//--3
{
	pnode p1 = a->next,p2 = b->next;
	//比较 
	while(  p1 != '\0' || p2 != '\0')
	{
		//值相等 
		if(p1->data == p2->data)
		{
			//后移 
			p1 = p1->next;
			p2 = p2->next;
			continue;
		}
		else;
		
		if(p1->data > p2->data)//前者值大 
		{
			printf("前者首次不相同字符大，前者大");
		}
		else if(p1->data < p2->data)//后者值大 
		{
			printf("后者首次不相同字符大，后者大");
		}
		else;

		break;
	}
	
	if(p1 == '\0' && p2 == '\0')//同时结束 
	{
		printf("一样大");
	}
	else if(p1 != '\0' && p2 == '\0')//后者先结束 
	{
		printf("后者字符少,前者大");
	}
	else if(p1 == '\0' && p2 != '\0')//前者先结束 
	{
		printf("前者字符少，后者大");
	}
	else;
	
	return;
}

//获取串的长度 
int StrLength(pnode a)//--4
{
	int length = 0;
	pnode p = a->next;
	while(p != NULL ){p = p->next;length ++;}
	return length;
}

//串的连接 b连接到a的末尾 
pnode Concat(pnode a,pnode b)//--5
{
	
	pnode tail = a;
	//找到a链表的末尾 
	while(tail->next != NULL)
	{
		tail = tail->next;
	}
	
	//链接b的第一个元素结点 
	tail->next = b->next;
	//连接完毕释放b的头结点 
	free_link(b);
	b = NULL;
	
	return a;
}

//用于截取字符串的某部分，其基本语法为substring(字符串,起始位置(下标),截取长度)
pnode SubString(pnode a,int begin,int length)//--6
{
	if(begin < 0 || length <= 0)
	{
		printf("begin,或length 不符合规制！");
		return NULL;
	}
	
	pnode p = a->next;
	//类似于strcopy操作，先把a中要截取的数据 放入一个字符数组
	char c[N] = {'\0'}; 
	//先找到起始位置 
	int k = 0;
	while(p != NULL)
	{
		k ++;
		//找到起始位置 
		if(k == begin + 1)
		{
			break;
		}
		p = p->next;
	}
	//开始赋值 到数组 
	k = 0;
	while(p != NULL)
	{
		k ++;
		c[k - 1] = p->data;
		//限制长度 
		if(k == length)
		{
			break;
		}
		p = p->next;
	}
	
	//依据数组构造一个新的sub链表 
	pnode sub = NULL;
	sub = create_link(c);
	
	return sub;
}
//打印 串 
void print_linkstring(pnode a)
{

	if(a == NULL)
	{
		printf("a is null,error!");
		return;
	}
	else;
	

	pnode q = a->next;
	while(q != NULL)
	{
		printf("%c ",q->data);
		q = q->next;
	}
	
	printf("\n");
	return;
}

//释放链队列
void free_link(pnode a)
{
	//已经释放过 
	if(a == NULL)
	{
		return;
	}
	else;
	
	pnode p = a->next;
	while(p != NULL)
	{
		//剔除p结点 
		a->next = p->next;
		//释放 
		free(p);
		//继续初始化 p 
		p = a->next;
	}
	//结点完毕 释放头结点 
	free(a); 
	
	a = NULL;//置头结点指针,p指针为空
	p = NULL;
	return;
} 
//依据字符数组 构建 链队列
pnode create_link(char c[])
{
	//依据字符数组 构建 链队列
	int size = sizeof(node);
	pnode a = (pnode)malloc(size);
	a->next = NULL;
	a->data = '\0';
	pnode head = a;//头结点
	//构建数据结点 
	int i = 0;
	pnode p = NULL;
	while(c[i] != '\0')
	{
		//初始p 
		p = (pnode)malloc(size);
		p->next = NULL;
		p->data = c[i];
		//链接p 
		head->next = p;
		head = p;//后移
		
		//遍历字符数组
		i ++; 
	}
	return a;
}
