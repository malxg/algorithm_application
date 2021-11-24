/*
求一元多项式pn(x)=a(i)x^i(i~n的和)的值pn(x0),
并确定算法中每一语句的执行次数和整个算法的时间复杂度。注意选择你认为较好的输入和输出方法。
本题的输入为a(i)(i=0,1,...,n),x0和n，输出为pn(x0); 
*/

#include <stdio.h>
#include <cmath>
//计算 求和 
int result = 0;//保存结果 
void reckon(int a[],int x0,int n)
{
	
	for(int i = 0;i < n;i ++)
	{
		result += a[i]*pow(x0,i);
	}
	return;
}

int main()
{
	int a[101] = {0},x0 = 0,n = 0;
	printf("输入x0,n:\n");
	scanf("%d%d",&x0,&n);
	printf("输入n个a:\n");
	for(int i = 0;i < n;i ++)
	{
		scanf("%d",&a[i]);
	}
	
	reckon(a,x0,n);//计算a(i)x^i 
	
	printf("\nresult is %d",result);
	return 0;
}
