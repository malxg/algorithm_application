//基于广度优先搜索，判别以邻接表方式存储的有向图是否有顶点v到顶点u的路径。
 
#include <stdio.h>
#include <malloc.h>
#include <queue>//队列实现广度优先 
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

//广度优先 目标边编号(类似 层序遍历)
int node_flag[N + 1] = {0};//结点 编号 入队标识 
int flag = 0;//找到标识 
void bfs(listnode a[],int v,int w)
{	
	if(v == w)//自己判断自己 这里不再考虑范围(当然也可以改进 用于判环) 
	{
		printf("v和w一样！");
		return;
	}
	
	queue<node*> q1;//队列
	node *p = a[v - 1].first;//创建的时候 v - 1（编号-1为 结点的位置） 
	//将v结点的 所有边结点入队  
	while(p != NULL)
	{
		q1.push(p);
		node_flag[p->aimdex] = 1;//标识入队 
		p = p->next;
	}
	
	node *q;
	while(q1.empty() == 0)//不为空 
	{
		p = q1.front();//p指向队首 结点 
		q1.pop();//队首 出队
		if(p->aimdex == w)//是否是要找的 结点 
		{
			printf("存在");
			flag = 1;//找到标识 
			break;//中断 循环 
		}
		
		//否则将 以队首结点 为出发结点的边结点入队,继续寻找 
		q = a[p->aimdex - 1].first;
		
		while(q != NULL)
		{
			//如果之前该编号边结点 入过队，跳过该结点 
			if(node_flag[q->aimdex] == 1)
			{
				q = q->next;
				continue;
			}
			//否则 入队
			q1.push(q);
			q = q->next; 
		}
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
	//找到 对应边结点的 表头，往广度 
	bfs(a,v,w);
	
	if(flag == 0)
	{
		printf("不存在！");
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
