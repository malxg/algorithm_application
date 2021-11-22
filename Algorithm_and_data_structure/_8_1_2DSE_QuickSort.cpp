/*
快速排序，用以下无序序列加以验证:
49,38,65,97,76,13,27,49 
*/

#include <stdio.h>

//快速排序(不稳定算法)
void quickSort(int a[],int begin,int end)
{
	
	if(begin == end)//该趟比对完成 
	{
		return;
	}
	
	int b = begin,e = end;//begin 作为标识，故b = begin + 1 第要处理的数据的起点 
	int t = 0,temp = 0;//前者存储begin的值 为和end的值交换,后者标识与插入点值交换
	int flag = 0;//标识 这一趟中 是否发生了 交换
	while(e != b)//寻找 a[begin]标识数据的插入位置，（左边都是比a[0]小的，右边是比a[0]大的） 
	{

		//先动 end指针 找到比a[begin]标识小的（默认用a[begin]来划分） 
		while(a[e] >= a[begin] && e > b)
		{
			e --;
		}
		//动begin指针找到比a[begin]标识大的 
		while(a[b] <= a[begin] && b < e)
		{
			b ++;
		}
		
		if(b == e)//说明交换 完成，直接退出，进行下一趟 
		{
			break;
		}
		else
		{
			//说明begin指向的值大于a[begin],end指向的值小于a[begin] 
			t = a[b];//交换 
			a[b] = a[e];
			a[e] = t;
			flag = 1;
		}
			
	}
	//标识与插入点值交换(更换标识 进入下一趟)
	temp = a[begin];//交换 
	a[begin] = a[e];
	a[e] = temp;
	
	if(flag == 1)//发生了交换说明 插入值在中间，左右两边都有 数据 
	{	
		//以上快速排序 一趟至少 确定了一个a[begin]元素的最终位置。 
		//下面继续 排序左右 两边 
		quickSort(a,begin,e - 1);//向其左边递归 继续下一趟
		quickSort(a,e + 1,end);//向其右边递归 继续下一趟
	}
	else//没有发生交换说明，插入值在没处理数据中的最左边（标识固定 偏左），只有右数据 
	{
		quickSort(a,begin + 1,end);//所以简便，直接右边递归 继续下一趟如0,3,2。 3,2 都在0右边，直接让后移一位，0标识变成3。 
	}
	
	return;   
}

//打印数组 
void prin_a(int a[]);
int main()
{
	int a[8] = {49,38,65,97,76,13,27,49};

	//快速排序 
	quickSort(a,0,8 - 1);//参数:数组,begin,end(起始，终止下标) 
	//打印数组 
	prin_a(a);
	
	return 0;
}
//打印数组 
void prin_a(int a[])
{
	for(int i = 0;i < 8;i ++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
	return;
}
