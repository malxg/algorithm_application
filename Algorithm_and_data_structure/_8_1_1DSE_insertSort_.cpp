/*
简单插入排序，用以下无序序列加以验证:
49,38,65,97,76,13,27,49 
*/
#include <stdio.h>

//插入排序(稳定算法)
void insertSort(int a[])
{
    int i;
    int j;
    int temp;  //定义一个临时变量，用于交换数据时存储 
    for(i=1;i<8;i++)
	{  //对序列进行遍历 
        for(j=0;j<i;j++)
		{  //进行扫描
            if(a[i] < a[j])//从小到大排序 
			{//交换位置 
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
   }
 }

//打印数组 
void prin_a(int a[]);
int main()
{
	int a[8] = {49,38,65,97,76,13,27,49};
	//插入排序 
	insertSort(a);
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
