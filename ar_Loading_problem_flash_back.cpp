/*
有一批共n个集装箱要装上艘载重量为c的轮船，其中集装箱i的重量为wi。找出一种最优装载方案，将轮船尽可能装满，即在装载体积不受限制的情况下，将尽可能重的集装箱装上轮船。
*/

#include <stdio.h>
#include <iostream>
#define num 10
using namespace std;

int c1 = 0,c1x[num] = {0};          // 船舱 的 载重（后面通过 用户 录入） 和 选择 物体 序列  
int w[num] = {1,3,4,6,7,8,2,4,3,1}; //模拟 的 物体 重量 数据 
int bestw = 0;                      //在该 情况 下 的最大重量 （随 着 起始遍历点 选择 不同 而 不同） 

//函数 中间量  
int x[num] = {0};                   //c1x 的中间量 
int current_weight = 0;             //bestw 的中间量 


//采用 dfs 深度 遍历数据，之前 遍历的 数据 排除 在下一次 遍历外 
void BackTrace(int t) 
{
	if(t >= num)
	{
		
		for(int i = 0;i < num;i ++)//标记 
		{
			c1x[i] = x[i];
		}
		bestw = current_weight;     //取得本次 情况 的最大重量 
		return;
	}
	
	if(w[t] > c1)
	{
		BackTrace(t + 1);
		return;
	}
	else
	{

		c1 = c1 - w[t];
		current_weight = current_weight + w[t];
		x[t] = 1;
		BackTrace(t + 1);
		//处理完毕 弹出 栈，还原 变量 
		current_weight = 0;
		c1 = c1 + w[t];
		x[t] = 0;
	
	}
	return;
}

//主函数 
int main()
{
	
	while(1)
	{
	    int end_bestw = 0;//记录 最终 船舱 最大重量 
		printf("cabin weight: ");
		
		scanf("%d",&c1); //输入 船舱的 载重 
		
		for(int i = 0;i < num;i ++)//选择 以 不同的 顶点 为根节点 进行回溯，之间选过的 数据不在 排除考虑 剪切 
		{
			bestw = 0;c1x[num] = {0};//初始化 
			
			BackTrace(i);//////开始回溯 入口 
			
			printf("当从第%d个货物开始装时, bestw :%d\n序列:",i + 1,bestw);
			for(int j = 0;j < num;j ++)//打印 每种 情况 下 的 序列  
			{
				printf("%d ",c1x[j]);
			}
			
			if(bestw >= end_bestw)//在每个情况最大重量 中选出 所有情况中 最大的重量 
			{
				end_bestw = bestw;
			}
			cout << endl << endl;
		}
		cout << "最大重量: " << end_bestw << "\n" << endl;	
	}
	return 0;
}
