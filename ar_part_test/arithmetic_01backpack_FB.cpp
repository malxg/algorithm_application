#include <iostream>
#include <stdio.h>
#define num 4
using namespace std;

//01 背包 回溯法 求出每个 体积 的最大，然后 让当前重量和背包体积一样的物体（若存在） 价值 和之前回溯价值 取较大值 
 
int value[num] = {2,4,3,7},weight[num] = {2,3,5,5};

int dynamic_programming(int Backpack_Capacity) //参数 背包体积 
{
	if(Backpack_Capacity <= 0)
	{
		printf("BC error!");
	}
	int c = Backpack_Capacity;
	int index[c + 1] = {0};
	int t_value = 0;
	
	//i为weight 和 value的下标,i + 1代表背包的体积 
	for(int i = 0;i <= c;i ++)
	{
		
		//初始价值为 之前没有统计过的 恰好体重等于 当前bp体积的 物体 
		for(int k = 0;k < num;k ++)
		{
			if(weight[k] == i + 1)
			{
				index[i + 1] = value[k];
			}
		}
		
		//回溯 如背包体积为5价值 的等于 背包体积为4的价值 + 背包体积为1的价值（2+3） 
		for(int j = 1;j <= i/2;j ++) 
		{
			t_value = index[j] + index[i + 1 - j];//重量j + i + 1 - j =i + 1 =当前背包的体积 
			if(t_value > index[i + 1])//当回溯 的价值 大于 初始化的价值 交换 
			{
				index[i + 1] = t_value;
			}
		}
	}
	
	return index[c];
}

void print()
{
	int back_v = 0;
	
	while(1)
	{
		printf("Please,enter the volume of the backpack: ");
		scanf("%d",&back_v);//cin>>back_v;
		
		if(back_v <= 0)
		{
			printf("volume <= 0,program end.");
			break;
		}
		
		cout << "end result: "<< dynamic_programming(back_v) << endl;
	}
	
	return;
}

int main()
{
	print();
	return 0;
}
