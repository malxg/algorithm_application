/*
使用STL的map容器实现统计功能。
如：读入一组数据（文具，数量）（ stationery,amount）,统计各种文具的总数 
*/
#include <map>//处理不包含重复项的元素 
#include <stdio.h>
#include <string>
#include <iostream>
#define N 3
using namespace std;//map在std空间里面 

typedef struct node{
	char stationery[20];
	int amount;
}node,*pnode;

//统计 
void count_m(node data[])
{
	
	map<string,int>m;
	
	//读入结构体 数组里面数据(插入)
	int j = 0;
	while(j < N)
	{
		m[data[j].stationery] = data[j].amount;//插入元素。返回其地址和true。Pair也可以定义成一个变量形式的。 
		j ++;//处理下一个 元素 
	};
//	int count = m.count("文具盒");//若键值k对应的元素存在，则返回1，否则0。
	//统计
	char a[3][10] = {{"文具盒"},{"铅笔"},{"橡皮"}};//要查找的文具名字
	for(int i = 0;i < 3;i ++)
	{
		int sum = 0;//该文具的 总数
		//map容器的遍历 
		map<string,int>::reverse_iterator iter;//指针;
		for(iter = m.rbegin();iter != m.rend();iter ++)
		{
			if(iter->first == a[i])
			{
				cout<<iter->first<<"总数 "<<iter->second<<endl;
			}
			
		}
	}
	
	return;
}

int main()
{
	//map是不包含重复键值的容器，如果有多个同键值的，只会存入首个键值的元素。 
	node data[N] =
	{
		{"铅笔",9},
		{"橡皮",4},
		{"文具盒",4},
	};
	
	count_m(data);
	
	return 0;
}
