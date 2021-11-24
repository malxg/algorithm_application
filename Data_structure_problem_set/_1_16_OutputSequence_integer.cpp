/*
自大至小依次输出顺序读入的三个整数X,Y,Z的值 
*/

#include <stdio.h>


int mmax(int a,int b)//求两个数中最大值 
{
	return a > b ? a : b;
}

int main()
{
	int x = 0,y = 0,z = 0;
		
	scanf("%d%d%d",&x,&y,&z);
	int max = mmax(x,mmax(y,z));//第一大 
	printf("%d ",max);
	if(max == x)//第一大是 x时 
	{
		max = mmax(y,z);//找第二大 
		printf("%d ",max);
		if(max == y)
		{
			printf("%d ",z);//找第三大 
		}
		else
		{
			printf("%d ",y);//找第三大 
		}
	}
	
	else if(max == y)//第一大是 y时 
	{
		max = mmax(x,z);//找第二大 
		printf("%d ",max);
		if(max == x)
		{
			printf("%d ",z);//找第三大 
		}
		else
		{
			printf("%d ",x);//找第三大 
		}
	}
	
	else//第一大是 z时 
	{
		max = mmax(x,y);//找第二大 
		printf("%d ",max);
		if(max == x)
		{
			printf("%d ",y);//找第三大 
		}
		else
		{
			printf("%d ",x);//找第三大 
		}
	}
	
	return 0;
}
