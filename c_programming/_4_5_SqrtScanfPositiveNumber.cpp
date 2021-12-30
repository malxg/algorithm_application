/*
输入小于1000的正数，输出它的平方根。（如果平方根不是整数，则输出其整数部分） 
*/
#include <stdio.h>

void solve_sqrt(int n)
{
	for(int i = 1;i <= n/2;i ++)
	{
		if(i * i <= n && (i + 1)*(i + 1) > n )
		{
			printf("sqrt is %d\n",i);//如果平方根不是整数，则输出其整数部分
			break;
		}
	}
	
	return;
}

int main()
{
	double n = 0;//double float
	while(1)
	{
		printf("Please enter a positive number less than 1000:\n");
		scanf("%lf",&n);
		if(n > 0 && n < 1000)
		{
			break;
		}
	}
	solve_sqrt(n);
	return 0;
}
