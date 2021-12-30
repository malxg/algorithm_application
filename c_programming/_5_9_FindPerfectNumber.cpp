/*
找1000之内的完数和其因子。 一个数恰好等于它因子之和，这个数就称为完数。
*/
//如6因子为1，2，3，又6 = 1 + 2 + 3，故6为完数
#include <stdio.h>
#define Size 1000
//找完数 并打印 蛮力遍历 
void Find_PerfectNumber()
{
	int sum = 0;
	for(int i = 6;i < Size;i ++)//找完数 (显然从6开始)
	{
		sum = 0;//初始化sum因子总值 
		int a[Size/10] = {0},k = 0;//a数组用来保存 因子,k作为数组的遍历指针 
		for(int j = 1;j <= i/2;j ++)//找数的因子,并保存在数组中,(由数学知识，n的因子不可能 > n/2 (数的因子不包含本身，但包含1))
		{
			//能被数整除，即为该数因子 
			if(i % j == 0)
			{
				a[k ++] = j;//因子存入数组
				sum += j;//并把因子相加 用来判断是否为完数 
			}
		}
		if(sum == i)
		{
			//打印结果 
			printf("%d its factors are ",i);
			for(int j = 0;j < k - 1;j ++)
			{
				printf("%d,",a[j]);
			}
			printf("%d\n",a[k - 1]);
		}
	}
	
	return;
}
int main()
{
	Find_PerfectNumber();//寻找Size以内的全部完数以及其因子 
	return 0;
}
