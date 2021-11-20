/*
创建一个带权路径的 有向图,无向图,
输出从v0到其他各个顶点的最短路径
采用Dijstra算法求一个顶点到其他所有顶点的最短路径 

*/
#define N 1 << 12 //4096,这里代替无穷大（默认 邻接矩阵） 
#define size 6
#include <stdio.h>

//cost为带权有向图的邻接矩阵，v为指定的 源点（从那个点开始） 
void dijstra(int cost[size][size],int v);

int main()
{
	//测试 邻接矩阵（用邻接矩阵 表示图）
	//这里用 有向图测试，无向图 类似 不过邻接矩阵必须关于对角线对称
	int a[size][size] = 
	{
		N ,N ,10,N ,30,100,
		N ,N ,5 ,N ,N ,N  ,
		N ,N ,N ,50,N ,N  ,
		N ,N ,N ,N ,N ,10 ,
		N ,N ,N ,20,N ,60 ,
		N ,N ,N ,N ,N ,N  ,
	};
	//参数 带权有向图的邻接矩阵，v为指定的 源点（从那个点开始）
	dijstra(a,0);//V0 ~ V(size - 1),一共 size个顶点 
	
	return 0;
}
//cost为带权有向图的邻接矩阵，v为指定的 源点（从那个点开始） 
void dijstra(int cost[size][size],int v)
{
	printf("源点是%d\n",v);
	int dist[size],s[size],rear[size];//dist[i]当前源点到顶点i的最小距离,s表示并入集合标识 
	int q[size][size]; 
	
	int i,j,k,mmin,m;
	//初始化s和rear 
	for(i = 0;i < size;i ++)
	{
		s[i] = 0;
		rear[i] = -1;
	}
	//初始化 dist和q
	for(i = 0;i < size;i ++)
	{
		dist[i] = cost[v][i];
		
		if(dist[i] < N)
		{
			q[i][++ rear[i]] = v;
			q[i][++ rear[i]] = i;
		}
	}
	
	s[v] = 1;//v并入 集合 
	
	//源点以及并入，再并入 size - 1个结点 
	for(k = 0;k < size - 1;k ++)
	{
		mmin = N;j = v;
		for(i = 0;i < size;i ++)//选出最小的dist[j] 
		{
			if(s[i] == 0 && dist[i] < mmin)//如果标识为0（没有被处理），且有到 i 的 路径 
			{
				j = i; //待处理index 赋值为i 
				mmin = dist[i];//更新 dist   
			}
		}
		if(j != i)
		{
			s[j] = 1;//处理后标识 为 1，避免重复处理 

						
			if(dist[j] == N)//dist[j] 等于无穷大，说明 没有到达该 点的路径,剔除源点到其 没有路径的index 
			{
				break;
			}
			
			printf("\nthe %d shortestdistance is %d\n",j,dist[j]);

			for(i = 0;i <= rear[j];i ++)//查看 path 
			{
				printf("-->%d",q[j][i]);//打印从源点到j的最短路径 
			}
			
			for(i = 0;i < size;i ++)//修改从源点到其余各店的最短距离 
			{
				if( s[i] == 0 && ( (dist[j] + cost[j][i]) < dist[i] ) )
				{
					dist[i] = dist[j] + cost[j][i];    //更新源点 到每个点的 最短路径 
					for(m = 0;m <= rear[j];m ++)
					{
						q[i][m] = q[j][m]; //修改相应的路径 
					}
				
					rear[i] = rear[j];
					q[i][++ rear[i]] = i;
				}
				
				
			}
		}
		
	}
	
	return;
}
