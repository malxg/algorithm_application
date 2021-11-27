/*
模拟 sort() 函数 按负数（-1） 零 正数（1） 的次序 排好
时间复杂度 o(n)
空间复杂度 o(1) 
*/
#include <stdio.h>
#define Maxsize 10

// 模拟 排序 
void sort(int a[])
{
	int count_plus = 0,count_minus = 0,count_zero = 0;//记录 三个数 的次数，统计后 直接 覆盖 式赋值 
	printf("star \n");
	//Start statistics
	for(int i = 0;i < Maxsize;i ++)
	{
		
		if(a[i] == -1)//-1
		{
			
			count_minus ++;
			
		}
		
		else if(a[i] == 0)//zero
		{
			
			count_zero ++;
			
		}
		
		else if(a[i] == 1)//1
		{
			
			count_plus ++;
			
		}
		
		else
		{
			
			printf("being error value!");
			
		}
	}
	
	//覆盖式 回退 
	int i = 0;
	while(count_minus != 0)//fill value minus
	{
	
		a[i ++] = -1;
		count_minus --;
	
	}
	
	while(count_zero != 0)//fill value zero
	{
	
		a[i ++] = 0;
	    count_zero --;
	    
	}
	
	while(count_plus != 0)//fill value plus
	{
	
		a[i ++] = 1;
	    count_plus --;
	    
	}
	
	return;
} 

//test_one
int main()
{
	int a[Maxsize] = {1,1,1,1,1,0,0,-1,0,-1};//example
	sort(a);                //调用 
	
	int i = 0;
	while(i != Maxsize)  //printf 打印 原数组 
	{
		
		printf("%d  ",a[i ++]);
		
	}
	
	return 0;
}
