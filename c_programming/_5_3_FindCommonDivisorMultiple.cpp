/*
输入两个正整数m和n，求其最大公约数和最小公倍数。 
*/
#include <stdio.h>
//找最大公约数 并打印 
void Find_MaxCommonDivisor(int m,int n)
{
	if(m == 0 && n == 0)
	{
		printf("Maximum common divisor is zero\n");
		return;
	}
	int mmin = (m > n ? n : m);//取m,n中较小值,作为最后一个测试值 
	//蛮力 遍历 
	int divisor = 1;//作为第一个公约数 
	int i = 1;//遍历种子 
	while(i <= mmin)//不能超过最后 一个测试值 
	{
		i ++;
		//寻找 
		if(n % i == 0 && m % i == 0)
		{
			divisor = i; 
		}
	}
	printf("Maximum common divisor is %d\n",divisor);
	return;
}
//找最大公倍数 并打印 
void Find_MaxCommonMultiple(int m,int n)
{
	if(m == 0 && n == 0)
	{
		printf("Maximum common multiple is zero\n");
		return;
	}
	
	int i = (m > n ? m : n);//取m,n中较大值,作为第一个测试值 
	//蛮力 遍历 
	while(1)
	{
		//寻找 
		if(i % n == 0 && i % m == 0)
		{
			printf("Maximum common multiple is %d\n",i);
			break;//退出 
		}
		i ++;//递增 
	}
	return;
}
int main()
{
	int m,n;
	printf("m,n: \n");
	scanf("%d%d",&m,&n);//输入m,n 
	if(m < 0 || n < 0)//不考虑 负值 
	{
		printf("m or n is error!!!");
		return 0;
	}
	//找最大公约数 并打印 
    Find_MaxCommonDivisor(m,n);
	//找最大公倍数 并打印 
    Find_MaxCommonMultiple(m,n);
    
	return 0;
}
