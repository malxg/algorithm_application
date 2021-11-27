/*
实现顺序表的就地逆置,即利用原表的存储空间将线性表逆置。 
*/
#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10
#include <stdio.h>

typedef struct{
	int elem[LIST_INIT_SIZE];//存储空间的基址 
	int length;//当前长度 
	int listsize;//当前分配的存储容量 
}SqList;//顺序表类型 
 
//逆置 
void inverse(SqList &a)
{
	int e = 0;//作为中介
	for(int i = 0;i < a.length/2;i ++)
	{
		//逆置 
		e = a.elem[a.length - 1 - i];
		a.elem[a.length - 1 - i] = a.elem[i];
		a.elem[i] = e;
	} 
	return;
}
//打印线性表 
void print_sq(SqList a);


int main()
{
	SqList a;
	//初始化 
	a.length = 5;
	a.listsize = LIST_INIT_SIZE;
	for(int i = 0;i < a.length;i ++)
	{
		a.elem[i]= i;//赋值 
	}
	//打印 
	print_sq(a);
	
	//逆置 
	inverse(a);
	//打印 
	print_sq(a);
	
	return 0;
}

//打印线性表 
void print_sq(SqList a)
{
	for(int i = 0;i < a.length;i ++)
	{
		printf("%d ",*(a.elem + i));
	}
	printf("\n");
	return;
}
