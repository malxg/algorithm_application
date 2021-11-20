/*
利用Kruskal算法求网的最小生成树，输出构造生成树过程的连通分量，
以文本形式输出生成树中各条边路径，以及其权值。 
*/

#include<algorithm>
#include<stdio.h>
#include <string.h>
using namespace std;

int dep[1001];//用于回溯的数组 
struct node{
	int x,y,v;
}a[1001];

int c[20] = {0},flag = 0;//保存 中间过程变量，为了 输出路径 
int depth(int x)
{
	if(dep[x] == x)
	{
		return x;
	}
	else
	{
		c[flag ++] = x;//如果 发生了回溯，就保存 中间所有过程量 和结果，后面再判断用不用 
		return dep[x] = depth(dep[x]);
	}
}

//cmp 编写sort（）里面参数 
int cmp(const node &a,const node &b)
{
	return a.v<b.v;       //从小到大 排序  
}
/*TEST_ONE
put: 
5 6 
1 2 4 
1 5 2
2 3 3
2 5 3
2 4 6
3 4 4
			v1 --4-- v2--3--v3
			|        | |     |
			2        | |     4
			|        | |     |
			v5----3--| |--6-v4
*/
int main()
{
	int n = 0,m = 0,lowcost = 0,d1 = 0,d2 = 0,k = 0;//f1 f2为回溯数组坐标 
	scanf("%d%d",&n,&m);//结点个数,边的条数 
	
	for(int i = 1;i <= n;i ++)//初始化 结点的编号1~n 
	{
		dep[i] = i;
	}
	
	for(int i = 1;i <= m;i ++)//录入边 （边的两个结点，以及边权值）,将所有边属性 放入全局数组 
	{
		scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].v);//（边的两个结点，以及边权值） 
	}
	
	sort(a + 1,a + 1 + m,cmp); //对a结构体 数组[a + 1,a + 1 + m] 从小到大 排序
	
	for(int i = 1;i <= m;i ++)
	{	
	
		d1 = depth(a[i].x);
		d2 = depth(a[i].y);
		
		if(d1 == d2)        //如果 满足，说明c数组 和flag变量 失效不能使用，因为这次 回溯结果是失败 
		{
			flag = 0;
			memset(c,0,sizeof(c));
			continue;
		}
		
		printf("path:");
		dep[d1] = d2;      //记录为 建立索引 路径f1->f2 等于以f1 f2都归在进生成树
		printf("%d \t",d2);//终点 无论flag 那种情况都得输出 
		if(flag == 1)//说明c数组 和flag变量能使用，因为这次 回溯结果是成功 
		{
			for(int j = 0;c[j] != 0;j ++)
				printf("%d->",c[j]);
		}
		else
			printf("%d->",d1);
		
		
		flag = 0;    //初始 flag 路径标识  
		memset(c,0,sizeof(c));//数组使用完成，初始 c数组 准备下一次保存回溯量 
		
		lowcost += a[i].v;//存储 最小生成树的权值 
		
		k ++; //构建边 成功，边数 + 1 
		if(k == n-1)//最小生成二叉树 边个数 等于 结点数-1 
		{
			break;
		}
	}
	
	printf("最小生成树权值: %d\n",lowcost);
}
