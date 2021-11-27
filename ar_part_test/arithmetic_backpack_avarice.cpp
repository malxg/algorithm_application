//arithmetic_backpack_avarice
#include <iostream>
#include <stdio.h>
#include <algorithm>//含sort 
#include <string.h>//包含memset 初始化函数 
#define num 4
using namespace std;

//背包 贪心算法
 
typedef struct{//保证 权重sort排序后 仍能 和其价值 重量 一一对应 
	double value;
	double weight;
	double proportion;
}article;
article ar[num] = {{2,2},{4,3},{5,5},{7,5}};//先初始化 个物体 的 价值 和重量，比重（value/weight） 用后面程序 运算 

double cmp(article &a,article &b)//编写sort函数的比较函数
{
	return  a.proportion > b.proportion;//采用降序排序
}



void greedy_method(double Backpack_Capacity) //参数 背包体积 
{
	if(Backpack_Capacity <= 0)
	{
		printf("Backpack volume error!");
	}
	double c = Backpack_Capacity;//局部变量 
	
	double all_value = 0,all_weight = 0;
	double ar_content[num];//记录 num个物体 存储到 背包中那部分 的比重
	memset(ar_content,0, num * sizeof(int) );//初始化 等于 int ar_content[num] = {0}; 
	
	//greedy_method run
	printf("value\tweight\tproportion\tar_content\n");
	for(int i = 0;i < num;i ++)//比重（value/weight）
	{
		if(ar[i].weight <= c)//在背包 容量内 
		{
			ar_content[i] = 1.0;//全部 可以 装入
			c = c - (ar[i].weight * ar_content[i]);
		}
		else if(ar[i].weight > c)//超过背包容量 
		{
			ar_content[i] = (c/ar[i].weight);
			c = c - (ar[i].weight * ar_content[i]);
		}
		else;

		//count value_weight
		all_value = all_value + (ar[i].value * ar_content[i]);
		all_weight = all_weight + (ar[i].weight * ar_content[i]);
		//print result
		printf("%.2lf\t%.2lf\t%.2lf\t\t%.2lf\n",ar[i].value,ar[i].weight,ar[i].proportion,ar_content[i]);
	}
	cout << "all value:" << all_value << "\tall weight:" << all_weight << endl;//\t 为tap指令 
	
	return;
}
int main()
{
	printf("value\tweight\tproportion\n");
	for(int i = 0;i < num;i ++)//比重（value/weight）
	{
		ar[i].proportion = ar[i].value / ar[i].weight;
	}
	
	sort(ar,ar + num,cmp);//按照 权重 给物体 排序 
	
	for(int i = 0;i < num;i ++)//输出 按权重 排序 后序列 
	{
		printf("%.2lf\t%.2lf\t%.2lf\n",ar[i].value,ar[i].weight,ar[i].proportion);
	}
	
	double back_v = 0;
	while(1)//循环 
	{
		printf("\nPlease,enter the volume of the backpack: ");
		scanf("%lf",&back_v);//cin>>back_v;
		
		greedy_method(back_v); 
		
	}
	
	return 0;
}
