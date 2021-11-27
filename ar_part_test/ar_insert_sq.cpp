/*
试给出顺序表类型定义，假定顺序表元素类型为整型，
顺序表最大长度为max，
编写函数对顺序表的指定下标位置(Pos)实现插入某元素值为e的操作.
*/

#include <stdio.h>
#include <iostream>
#define MAX 20
using namespace std;

void get_length(int a[]);
void print_sq(int a[]);
void insert(int a[],int pos,int e);//arrange,postion(下标)

int length = 0;//init data length
//main
int main()
{
	int e,pos,a[MAX] = {1,2,3,4,5,6,7,8,9,10};
	get_length(a);//get really length
	print_sq(a);//printf sqlist
	
	scanf("%d%d",&pos,&e);//position,element
	
	insert(a,pos,e);//insert element
	get_length(a);//get really length
	print_sq(a);//printf sqlist

	return 0;
}

void get_length(int a[])//get sqlist length
{
	length = 0;
	for(int i = 0;a[i] != 0;i ++)
	{
		length ++;
	}
	return;
}

void insert(int a[],int pos,int e)//arrange,postion
{
	for(int i = length;i > pos;i --)
	{
		a[i] = a[i - 1];
	}
	
	a[pos] = e;
	
	return;
}

void print_sq(int a[])//print sqlist
{
	for(int i = 0;i < length;i ++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
	
	return;
}
