/*
编写算法，
用归并排序方法实现对整型数组a[n]的 升序排序。
*/


#include <stdio.h>
#include <iostream>
#define n 10
using namespace std;

int a[n] = {9,2,3,3,2,1,6,5,4,10};// n == 10 保存 最后 结果 
//分治 思想 考虑 递归算法 
void merge_manage(int a[],int begin,int mid,int end)
{

    int arr[n]; 
	//开始 治，还原的过程 有局部有序 还原到 整体 有序 
	int i = 0;            //arr 数组 的下标 
	int b = begin;        //用 b 来 保存 mid 左边的 开始 
	int other_b = mid + 1;//用  other_b 保存 mid 右边的 开始
	
	//从 左边 第一个 开始，和右边第一个 进行比较，以此类推 
	while(b <= mid && other_b <= end)
	{
		if(a[b] < a[other_b])  //这里进行 升序排序，左边小于右边。 
		{
			arr[i ++] = a[b ++];
		}
		else
		{
			arr[i ++] = a[other_b ++];
		}
	}
	
	//如果 mid左边 全部 录完，剩下的 直接赋值就行 
	if(begin == mid + 1)
	{
		arr[i ++] = a[ other_b ++];
	}
	//如果 mid右边 全部 录完，剩下的 左边 直接赋值就行 
	else if(other_b == end + 1)
	{
		arr[i ++] = a[ b ++];
	}
	
	//局部 数组 录入完毕，赋值给 最后的结果数组，赋值 过程 采取 覆盖 原来位置（l 与 k要对应） 
	for(int k = 0,l = begin;k < i;k ++,l ++)
	{
		a[l] = arr[k];
	}
	
	return;
}

void merge_sort(int a[],int begin,int end)
{
	if(begin == end)//最多 两两一队,不能再小了 
		return;
		
	int mid = (begin + end) / 2;
	//开始 分，分到 最多 两两一队 
	merge_sort(a,begin,mid);//mid 左边 部分 
	merge_sort(a,mid + 1,end);//mid 右边 部分 
	
	//治 
	merge_manage(a,begin,mid,end);
}

//print function
void print_arrange(int a[])
{
	for(int i = 0;i < n;i ++)
	{
		printf("%d ",a[i]);
	}
	cout << endl;
}
//main function
int main()
{
	print_arrange(a);
	
	merge_sort(a,0,n-1);
	print_arrange(a);
	return 0;
}
