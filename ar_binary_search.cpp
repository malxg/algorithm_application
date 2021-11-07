/*
假定a[n]为升序有序整型数组，
编写函数实现 折半（二分）查找 某指定关键字为e的操作。
*/

#include <stdio.h>
#include <algorithm>//include sort()
#include <iostream>
#define n 10
using namespace std;
bool cmp(int a,int b)
{
	return a < b;//前者 小于 后者，升序 -> 非递减 
}


void binary_search(int a[],int e,int low,int high)
{
	//binary search 除不尽时，向下取整 
	int mid = (low + high) / 2;
	
	//找到 返回 
	if(a[mid] == e)//如果 序列中 有 重复的e 则为 靠前的那个e（mid是 向下取整） 
	{
		printf("search success,position is %d",mid + 1);//第mid + 1个,(mid 是下标) 
		return;
	}
	//中间值 大于 目标值，说明 目标值 在左边(序列是升序) 
	else if(a[mid] > e)
	{
		high = mid - 1;//向较小的左边找，上界 变为 mid - 1,左部分
		binary_search(a,e,low,high);//以新的high 作为上界 进入 左部分 
	}
	//中间值 小于 目标值，说明 目标值 在右边(序列是升序) 
	else if(a[mid] < e)
	{
		low = mid + 1;//向较大的右边找，下界 变为 mid + 1,右部分
		binary_search(a,e,low,high);//以新的low 作为下界 进入 右部分 
	}
	else;
	 
	return;
}

//print function
void print_arrange(int a[])
{
	for(int i = 0;i < 10;i ++)
	{
		printf("%d ",a[i]);
	}
	cout << endl;
}

int main()
{
	int a[n] = {9,2,3,10,1,11,5,2,1,4};// n == 10
	//升序 序列 
	sort(a,a + 10,cmp);//sort 排序 函数 
	print_arrange(a);
	
	int e;//查找 值 
	cout << "please,enter the find value: ";
	scanf("%d",&e);
	
	binary_search(a,e,0,n);
	
	return 0;
}
