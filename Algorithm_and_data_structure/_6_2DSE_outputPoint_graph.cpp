/*
用邻接表作为存储结构的图G，
1 求图中每个顶点的出度
2 计算图中出度为0的顶点数 
*/

#include <stdio.h>
#include <malloc.h>
#define N 6
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

//判断结点的 出度数，如果为 1则输出 
void judge(listnode a[])
{
	int count = 0;
	for(int i = 0;i < N;i ++)//遍历 表结点的出度值 
	{
		if(a[i].outdegree == 0)
		{
			printf("出度为0结点：v%d ",a[i].index); 
			count ++;
		}
		else;
	}
	
	printf("\n出度为0的节点数 %d",count);
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
	listnode a[N];
	
	//构建 邻接表,同时统计 每个结点的 出度 
	create_list(a);
	
	//判断结点的 出度数，如果为 1则输出 
	judge(a);
	
	return 0;
}
