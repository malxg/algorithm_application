/*
13人围成一圈，从第一个人开始顺序报号1，2，3。报到3退出。找出最后留在圈子中的人原来的序号。用链表实现。 
*/
#include <stdio.h>
#include <malloc.h>//申请空间 
//人 结点 
typedef struct node{
	int order;
	struct node *next;
}node,*people;

//创建n个人为一圈，并依次编号 
people create_link(people one,int n)
{
	int size = sizeof(node);//要申请的结点空间大小
	//初始第一个人空间 
	one = (people)malloc(size);
	one->order = 1;
	one->next = NULL;
	people p = one,q = NULL;//开始创建剩下的人 
	
	for(int i = 2;i <= n;i ++)//从1开始编号
	{
		//创建一个'人' 
		q = (people)malloc(size);
		q->order = i;
		q->next = NULL;
		//将人加入圈中 
		p->next = q;
		p = q;
		//初始q指针 
		q = NULL;
	}
	//注意是一个圈 要形成循环 链表
	p->next = one;//最后一个‘人’指向第一个
	
	return one;//返回第一个人 
}

//开始寻找 
void find_LastOrder(int n)
{
	people one;//指向起始第一个人
	//创建队伍 
	one = create_link(one,n);
	if(one == NULL)
	{
		printf("创建队伍失败！");
		return;
	}
	
	//创建成功 
	//开始寻找
	people p = one,q;
	int i = 0;
	while(1)//找到为止，找到后直接break释放调 
	{
		i = 1;
		//删除报3口号的人，说明是删除报2口号人的 下一位 
		while(i != 2)//找到报口号为2的人 
		{
			i ++;
			p = p->next;
		}
		 
		if(p->next == p)//说明只有一个人了，自己又报口号2，又得报口号3，这就是最后一个，找到成功
		{
			//打印
			printf("最后一个人序号为%d\n",p->order);
			break; 
		}
		else//否则，是该退出的人 
		{
			//删除 该退出的人
			q = p->next;//q指向要删除的，方便后面释放 
			p->next = p->next->next;//剔除要删除的人，p指向报4的人
			free(q);//释放剔除的人 
		}
	}
	
	free(p);//释放最后一个人的结点
	one = q = p = NULL;//初始化指针
	 
	return;	
}

int main()
{
	int n = 13;//有多少人在队伍 
	find_LastOrder(n);//找到 并打印结果 
	return 0;
}
