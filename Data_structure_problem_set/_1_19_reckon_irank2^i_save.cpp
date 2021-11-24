/*
计算i!*2^i(i=0,1,...,n-1)的值并分别存入数组a[arrsize]的各个分量中。
假设计算机中允许的整数最大值为MAXINT,则当n>arrsize或对某个k(0<=k<=n-1)
使k!*2^k>MAXINT时，应该按出错处理。注意选择逆认为较好的出错处理方法。 
*/
#define MAXINT 1<<25//这里作为出错标识 
#define arrsize 1001
#include <stdio.h>
#include <cmath>

long long int a[arrsize] = {0};//保存运算结果 

void reckon_(long int n)
{
	if(n > arrsize)
	{
		printf("n超限");
		return;
	}
	
	for(long int i = 0;i < n;i ++)//i=0,1,...,n-1
	{
		if(i == 0)
		{
			a[i] = 1;
			continue;
		}
		
		long int rank = 1;//保存i的阶乘的值 
		long int j = i;
		while( j != 0)
		{
			rank *= j;
			j --;
		}
		
		if(abs(rank * pow(2,i)) > MAXINT)
		{
			printf("计算结果,超限!");
			break;
		}
		a[i] = rank * pow(2,i);
		
		
	}
	return;
}
void print_array();//打印数组 
int main()
{
	long int n = 0;
	scanf("%d",&n);//输入n 
	reckon_(n);//calculation
	print_array();//打印数组 
	return 0;
} 

void print_array()
{
	for(int i = 0;a[i] != 0;i ++)
	{
		printf("%lld ",a[i]);
	}
	printf("\n");
	return;
}
