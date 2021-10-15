//arithmetic_01backpack_DP
#include <iostream>
#include <stdio.h>

#include <string.h>//包含memset 初始化函数 
#define num 4
using namespace std;

//01 背包 动态规划 0222  0235 02357
 
int value[num] = {2,4,3,7},weight[num] = {2,3,5,5};

void dynamic_programming(int Backpack_Capacity) //参数 背包体积 
{
	if(Backpack_Capacity <= 0)
	{
		printf("dp error!");
	}
	int c = Backpack_Capacity;
	
	int dp[num + 1][c + 1];
	memset(dp,0, (num + 1) * (c + 1) * sizeof(int) );
	
	for(int i = 0;i < num;i ++)
	{
		for(int j = 1;j < c + 1;j ++)
		{
			if(j < weight[i])//加入的i号物体太大 等于没有加入，故此时 等于 没有i号 物体时的 最大价值。 
			{
				dp[i + 1][j] = dp[i][j];
			}
			else
			{
				dp[i + 1][j] = max(dp[i][j],dp[i][j - weight[i]] + value[i]);//与 前一行 的 该列数据比较（出去 i号物体 最大价值） 
			}
			
		}
	}
	
	for(int i = 0;i < num + 1;i ++)
	{
		//打印dp数组 
		for(int j = 0;j < c + 1;j ++)
		{
			printf("%d\t",dp[i][j]);
		}
		printf("\n");
	}
	
	return;
}
int main()
{
	int back_v = 0;
	while(1)//循环 
	{
		printf("Please,enter the volume of the backpack: ");
		scanf("%d",&back_v);//cin>>back_v;
		
		if(back_v <= 0)
		{
			printf("volume <= 0,program end.");
			break;
		}
		
		dynamic_programming(back_v);
	}
	
	return 0;
}
