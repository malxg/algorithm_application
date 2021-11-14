/*输入10个整数，最小与第一个数对换，最大与最后对换
 3个自定义函数，输入10个数，输出10个数 
 */ 
 
#include <stdio.h>
#include <limits.h>//包含INT_MAX 2147483647  和 INX_MIN -2147483648  
//#include <iostream>
//using namespace std;

//调换最小值 和 第一位 参数:整形数组 无返回值 
void mmin_swap_begin(int a[])
{
	int x = INT_MAX,flag = 0;//记录局部最小 和 其下标 
	
	for(int i = 0;i < 10;i ++)
	{
		if(a[i] < x)
		{
			x = a[i];
			flag = i;
		}
	}
	
	if(flag != 0)
	{
		int t = a[0];
	    a[0] = a[flag];
	    a[flag] = t;
	}
	else;
	
	return;
}

//调换最大值 和 最后位 参数:整形数组 无返回值 
void mmax_swap_end(int a[])
{
	int x = INT_MIN,flag = 0;//记录局部最大 和 其下标 
	
	for(int i = 0;i < 10;i ++)
	{
		if(a[i] > x)
		{
			x = a[i];
			flag = i;
		}
	}
	
	if(flag != 9)
	{
		int t = a[9];
	    a[9] = a[flag];
	    a[flag] = t;
	}
	else;
	
	return;
}

int main()
{
	int a[10] = {0};
	
	for(int i = 0;i < 10;i ++)
	{
		scanf("%d",&a[i]);//录入 10 个 整数 
	}
	
	mmin_swap_begin(a);//找最小交换 
	mmax_swap_end(a);//找最大 交换 
	
	for(int j = 0;j < 10;j ++)
	{
		printf("%d ",a[j]);
	}
	
	printf("\n");
	return 0;
}
