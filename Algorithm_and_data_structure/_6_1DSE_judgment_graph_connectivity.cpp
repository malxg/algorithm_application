/*
判断无向图G是否连通。
若连通返回1，否则返回0 
*/

#define N 1 >> 8 //代替无穷大（默认 邻接矩阵） 
#define size 6
#include <stdio.h>

int flag[size] = {0};//无向图 只要每个顶点至少有一条边 就连通 
int judgment(int a[][size])
{
	for(int i = 0;i < size;i ++)
	{
		for(int j = 0;j <= i;j ++)
		{
			if(a[i][j] != N && flag[j] != 1)
			{
				flag[j] = 1;
			}
		}
	}
	
	int k = 0;
	while(flag[k]){k ++;}

	if(k == size)
	{
		return 1;
	}

	return 0;
}

int main()
{
	//测试 邻接矩阵（用邻接矩阵 表示图） 
	int a[size][size] = 
	{
		1,N,N,N,N,N,
		N,2,N,N,N,N,
		N,N,3,N,N,N,
		N,N,N,4,N,N,
		N,N,N,N,5,N,
		N,N,N,N,N,6,
	};
	
	printf("%d",judgment(a));
	
	return 0;
}
