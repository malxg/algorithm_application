/*
在一个无序表A中，采用顺序查找算法查找值为x的元素，
返回其所在位置 
*/

#include <stdio.h>

//顺序查找 
void Sequential_search(int A[],int data)
{
	int i = 0;
	while(A[i] != 0)
	{
		if(A[i ++] == data)
		{
			printf("position: %d",i);//打印 是第几个元素(返回数组下标的话 打印i - 1) 
			break;
		}
	}
	printf("查找失败！A表中没有该元素");
	return;
}

int main()
{
	int A[101] = {2,3,4,5,6,11,34,56,88,44};
	int s = 0;
	scanf("%d",&s);
	//顺序查找
	Sequential_search(A,s); 
	return 0;
}
