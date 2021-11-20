/*
根据用户输入的偶对(以输入0表示结束)建立其有向图的邻接表，
并输出其一个拓扑排序序列和逆拓扑排序，并判断是否有回路 
*/

#include <stdio.h>
#include <malloc.h>
#include <stack>
#define size 6
using namespace std;
typedef struct node{
	int aimdex;//箭头指向结点的编号 
	struct node *next;//指向下一个结点 
}node;

typedef struct listnode{
	int index;   //结点编号 
	int indegree;//入度
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
	for(int i = 0;i < size;i ++)
	{
		p[i].index = i + 1;//1~n编号
		p[i].indegree = 0;
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
		p[m - 1].indegree ++;//入度 增加
		
		scanf("%d%d",&k,&m);
	}
	return;
}

//拓扑排序
int top[size] = {0};//保存 拓扑排序结果 方便逆拓扑 
int topsort(listnode a[])
{
	stack<int>s1;
	node *q;
	for(int i = 0;i < size;i ++)
	{
		if(a[i].indegree == 0)//遍历表结点，所有入度为0的都进栈 
		{
			s1.push(a[i].index);//表结点 下标进栈 
		}
	}
	int count = 0;//顶点的 计数器，如果count小于结点数，说明有环 
	
	int j;//保存此时 要处理的表结点下标
	while(s1.empty() != 1)//栈不为空 
	{
		j = s1.top();//取栈顶 元素的下标(本次处理结点的下标) 
		s1.pop();//出栈 
		
		//printf("%5d",a[j - 1].index);//打印 该结点下标，此为为拓扑序列一部分 
		top[count] = a[j - 1].index;//保存 该结点下标，此为为拓扑序列一部分 
		count ++;//该结点满足条件，成功顶点数 + 1 
		
		//数组的下标为 结点下标-1(数组从0开始编号，结点从1开始编号) 
		q = a[j - 1].first;//保存为 所取下标的 顶点结点（与其相连的 结点 入度-1）
		
		int k = 0;//k保存要处理结点的 下标 
		while(q != NULL)//如果该顶点有与它相连的结点 
		{
			k = q->aimdex;//k要处理结点的 下标 
			
			//数组的下标为 结点下标-1(数组从0开始编号，结点从1开始编号) 
			a[k - 1].indegree --;  //该结点入度减1(因为与之相连的j已经处理) 
			if(a[k - 1].indegree == 0)//如果 减一后度为0说明 是待处理对象 把其下标入栈 
			{
				s1.push(k);//入栈 该下标 
			}
			q = q->next;//看是否还有 与j 相连的结点，q继续遍历j的边结点 
		} 
	}
	
	if(count < size)//如果有结点没有经过 进栈出栈（没有处理到count != size） 
	{
		printf("the graph has recycle");
		return -1;//说明 拓扑排序失败 
	}
	
	return 1; //说明 拓扑排序成功 
}

/*
test_one(测试环的情况) 
结点编号  边结点         indegree(入度)    outdegree(出度)
1        -->4-->3-->2    1                 3
2        -->5            2                 1
3        -->5-->2        1                 2
4        -->5            2                 1
5        -->1            4                 1
6        -->5-->4        0                 2

test_one(测试无环的情况) 
结点编号  边结点         indegree(入度)    outdegree(出度)
1        -->2            0                 1
2        -->3            1                 1
3        -->4            1                 1
4        -->5            1                 1
5        -->6            1                 1
6                        1                 0
*/
//打印拓扑排序（或逆拓扑排序） 数组 
void print_array(int a[],int flag)
{
	if(flag == 0)//打印拓扑 排序 
		for(int i = 0;i < size;i ++)
		{
			printf("%d ",a[i]);
		}
	else//逆拓扑排序（拓扑排序反转输出） 
		for(int i = size - 1;i >= 0;i --)
		{
			printf("%d ",a[i]);
		}
	printf("\n");
}
int main()
{
	listnode a[size];
	//构建 邻接表,同时统计 每个结点的 出度 
	create_list(a);
	
	//拓扑排序
	int flag = topsort(a);
	if(flag == 1)//如果没有环，top排序成功 
	{
		printf("拓扑排序结果:");
		print_array(top,0);
		
		//逆拓扑排序
		printf("逆拓扑排序结果:");
		print_array(top,1);//逆拓扑排序（拓扑排序反转输出） 
	}
	else;
	
	
	return 0;
}
