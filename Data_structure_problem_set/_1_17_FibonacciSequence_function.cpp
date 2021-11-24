/*
编写求k阶斐波那契序列的第m项值的函数算法，
k和m均以值调用的形式在函数参数表中出现。 
*/

#include <stdio.h>

//斐波那契数列的阶数 表示它从多少阶再-1开始 递增如k为3就是没有常说的从第二项开始增加即0 1 1 2 3... 
int f = 0;//全局变量保存 要获取的k阶 第m项的值 
void get_Fibonacci_Value(int k,int m)//k阶斐波那契,第m项值 
{
	if(k < 2 || m < 0)//不符合条件 m < 0 
	{
		printf("k or m不符合规定");
		return;//以及k小于2也不行，因为这说明k小于等于1，则从第零项开始增加？(不是下标0，下标0是第一项，这第零项的话都变成-1的下标)显然不符合 斐波那契数列的定义
	}
	//F(0)=0，F(1)=1, F(n)=F(n - 1)+F(n - 2)（n ≥ 2，n ∈ N*）
	int a[1001] = {0};//保存斐波那契数列 的结果 默认全为0) 
	
	if(m >= 0 && m < k - 1)
	{
		f = 0;
	}
	else if(m == k - 1 && m == k)//从k-1开始递增 第k项等于0 + 1 = 1实际和k-1项相等 
	{
		f = 1;
	}
	else//说明 m > k(m >= k + 1) 
	{//开始 斐波那契的运算 
		
		a[k - 1] = 1;
		a[k] = 1;
		printf("%d %d ",a[k - 1],a[k]);
		for(int j = k + 1;j <= m;j ++)
		{
			a[j] = a[j - 1] + a[j - 2];
			printf("%d ",a[j]);
		}
		printf("\n");
		f = a[m];
		 
	} 
	return;
	
}

int main()
{
	int k = 0,m = 0;
	
	printf("(阶数/第几项)\n");
	scanf("%d%d",&k,&m);
	get_Fibonacci_Value(k,m);//k阶斐波那契,第m项值
	printf("%d阶第%d项为：%d",k,m,f);
	return 0;
}
