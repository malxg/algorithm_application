/*
基于深度优先，判别以邻接表方式存储的有向图是否有顶点v到顶点u的路径。 
*/

 
#include <stdio.h>
#include <malloc.h>
 
using namespace std;
#define N 11
typedef struct node{
	int aimdex;//箭头指向结点的编号 
	struct node *next;//指向下一个结点 
}node;
 
typedef struct listnode{
	int index;   //结点编号 
	int outdegree;//出度
	node *first; //第一个 边结点 (用 头插法 建立)
}listnode;
 
//构建 邻接表,同时统计 每个结点的 出度 
int len = sizeof(node);//便于 申请 结点空间 

void create_list(listnode a[]);

//深度优先 目标边编号(类似栈)
int node_flag[N + 1] = {0};//结点 编号 访问标识 
int flag = 0;//找到标识 
void dfs(listnode a[],node *p,int w)
{	

	if(p == NULL)
	{
		return;
	}

	if(p->aimdex == w)
	{
		printf("存在");
		flag = 1;
		return;
	}
	//找到 对应边结点的 表头，往深度 
	int i = 0;
	for(i = 0;i < N;i ++)
	{
		if(a[i].index == p->aimdex)
		{
			break;
		}
	}

	//找到表头 按同样操作处理 边结点
	listnode * t = &a[i];
	node_flag[t->index] = 1;//标识为访问 
	node *q = t->first;
	//退出循环条件：q为NULL,或者flag = 1,已经找到 不用再找了
	while(q != NULL || flag == 1)
	{
		if(node_flag[q->aimdex] == 1)//该编号结点已经被访问 
		{
			q = q->next;//跳过 该编号结点 
			continue;
		}
		//否则递归处理 
		dfs(a,q,w);
		q = q->next;
	}
	
	return;
}
/*
test
结点编号 出度 边结点 
v1        3   -->4-->3-->2
v2        0         
v3        2   -->5-->2
v4        1   -->5
v5        0
v6        2   -->5-->4
*/
int main()
{
	listnode a[N] = {0,0,NULL};
	//构建 邻接表,同时统计 每个结点的 出度 
	create_list(a);
	//输入要判断 存在 的边
	int v,w;
	v = w = 0;
	printf("v,w: ");
	scanf("%d%d",&v,&w);
	//找到 对应边结点的 表头，往深度 
	int i = 0;
	for(i = 0;i < N;i ++)
	{
		if(a[i].index == v)
		{
			break;
		}
	}

	//递归寻找 
	//找到表头 处理 边结点
	listnode * t = &a[i];
	node_flag[t->index] = 1;//标识为访问 
	node *q = t->first;
	//退出循环条件：q为NULL,或者flag = 1,已经找到 不用再找了
	while(q != NULL || flag == 1)
	{
		if(node_flag[q->aimdex] == 1)//该编号结点已经被访问 
		{
			q = q->next;//跳过 该编号结点 
			continue;
		}
		//否则递归处理 
		dfs(a,q,w);
		q = q->next;
	}
	
	if(flag == 0)
	{
		printf("不存在!");
	}
	
	return 0;
}
//输入 创建邻接表 
void create_list(listnode a[])
{
	listnode *p = a;//表结点 
	node *q;//指向边结点 
	//初始 N个 表结点 
	for(int i = 0;i < N;i ++)
	{
		p[i].index = i + 1;//1~n编号
		p[i].outdegree = 0;
		p[i].first = NULL;
	}
	
	//建立 边结点 
	printf("\nplease input the edge node(箭头尾部&头部(编号)(0,0)为结束):\n");
	int k = 0,m = 0;
	scanf("%d%d",&k,&m);//k为 有向边，箭头尾部，m为 头部，编号 
	
	while(k != 0 && m != 0)//输入(0,0)结束
	{
		
		q = (node*)malloc(len);
		
		q->aimdex = m;//标识所指 结点编号
		//头插法 思想
		q->next = p[k - 1].first;//本次结点next 指向上次插入的那个结点（没有就指向 NULL） 
		p[k - 1].first = q;//头插法 新的 边结点 插入单链表的表头 
		
		p[k - 1].outdegree ++;//出度 增加
		
		scanf("%d%d",&k,&m);
	}
	return;
}
