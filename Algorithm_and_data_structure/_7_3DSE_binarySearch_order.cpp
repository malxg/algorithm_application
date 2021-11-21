/*
利用二分查找算法查找任意一个元素所比较的次数 
*/

#include <stdio.h>
#define END 1 << 12//4096作为 整形数组的结束标识 

int get_len(int a[]);//获取数组长度 
void print_array(int a[]);//打印数组

int len = 0;//测试数组的长度 
int count = 0;//记录查找任意一个元素所比较的次数 
//二分查找
int c[20] = {0};
int BinarySearch(int a[],int low,int high,int data)
{
	if(low > high)//查找失败 
	{
		return 0;
	}
	
	int mid = (low + high)/2;//获取 中间值
	
	c[count] = a[mid];
	int flag = 0;//获取查找结果 
	count ++;//查找次数 + 1
	
	if(a[mid] < data)//mid小于data 递增有序表中说明 若存在 则是在mid的右边 
	{
		flag = BinarySearch(a,mid + 1,high,data);
	}
	else if(a[mid] > data)//mid大于data 递增有序表中说明 若存在 则在mid的左边 
	{
		flag = BinarySearch(a,low,mid - 1,data);
	}
	else//查找成功 
	{
		return 1;
	}
	
	
	return flag;
}

int main()
{
	int a[101] = {1,2,2,15,16,18,20,20,30,33,END};//test 有序表 END为结束符（默认为0，如果不用0需要自己定义结束符） 
	len = get_len(a);//获取元素个数 不包括(END) 

	//print打印 原数组 
    print_array(a);

	//输入要查找的值
	int data = 0;

	scanf("%d",&data); 
	
	//二分查找 
    int flag = BinarySearch(a,0,len - 1,data);
    
    //print打印次数 
    if(flag == 1)//查找成功
    {
    	printf("查找成功，查找次数:%d \n依次是\n",count);
    	for(int i = 0;c[i] != 0;i ++)
    	{
    		printf("%d ",c[i]);
		}
	}
	else
	{
		printf("查找失败！没有该元素");
	}
	
	return 0;
} 

//打印数组 
void print_array(int a[])
{
	int size = get_len(a);//获取 传入数组的元素长度 
	for(int i = 0;i < size;i ++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
	return;
}
//获取数组长度 
int get_len(int a[])
{
	int i = 0;
	while(a[i] != END)
	{
		i ++;
	}

	return i;
}

