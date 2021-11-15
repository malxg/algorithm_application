/*
--生成 非递减 有序 线性表 LA,LB。
--将LA,LB归并为 新表LC，
--且LC中同样 非值递减 排序，
--输出LA,LB,LC 
*/
//#include <iostream>
//using namespace std;

#include <stdio.h>
#include <algorithm>//include sort() 排序函数 包含在c ++中 
using namespace std;//c ++中 告诉编译程序使用std命名空间 (使用c ++ 函数时候必须有)

#define size 10
//这里 线性表 可以 是 数组 或者 链表，由于按 非递减排序 显然数组更方便 

bool cmp(int a,int b)
{
	return a <= b;// 前者 <= 后者  非递减 排序
}

void print_array(int a[],int range)
{
	int i = 0;
	while(i < range)
	{
		printf("%d ",a[i ++]);
	}
	printf("\n");
} 

//test procedure
int main()
{
	int LA[size] = {4,6,12,4,
					6,7,9,11,
					13,2};
	int LB[size] = {2,4,0,3,
					6,7,5,11,
					15,2};
	int LC[size + size] = {0};//init LC
	
	
	sort(LA,LA + size,cmp);//非递减 排序LA 
	printf("LA: ");
	print_array(LA,size);  //输出 LA 
	
	sort(LB,LB + size,cmp);//非递减 排序LB
	printf("LB: ");
	print_array(LB,size);  //输出 LB 
	
	//先合并 LA,LB -> LC
	int i = 0; 
    while(i < size)
    {
    	LC[i] = LA[i];
    	LC[i + size] = LB[i ++];
	}
	
	//排序 lC 
    sort(LC,LC + 2*size,cmp);//非递减 排序LC 
	printf("LC: ");
	print_array(LC,2*size); //输出 LC 
	
	return 0;
}
