/*
有A,B两个顺序表，a,b分别为A,B中除去最大共同前缀后的子表，
若a==b==NULL,则A==B;若a为空，而b不为空，或者两者都不为空，
且a的首元小于b的首元，则A<B；否则A>B。写一个比较A,B大小的算法。 
*/
#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10
#include <stdio.h>

typedef struct{
	char *elem;//存储空间的基址 
	int length;//当前长度 
	int listsize;//当前分配的存储容量 
}SqList;//顺序表类型 
 
//打印线性表 
void print_sq(SqList a);
int mmax(int a,int b)
{
	return a > b ? a : b;
}
//合理位置插入元素x 
void comparatively(SqList A,SqList B)
{
	//遍历
	int max = mmax(A.length,B.length);//用长度最长的线性表 当遍历上线 
	int i = 0;
	for(i = 0;i < max;i ++)
	{
		
		if(*(A.elem + i) == *(B.elem + i))//1 
		{
			continue;
		}
		//不用求得 子表，直接边对比边比较 
		if(*(A.elem + i) > *(B.elem + i))//如果 前者 大于 后者 
		{
			printf("A > B");
			break;
		}
		else
		{
			printf("A < B");
			break;
		}
		
	}
	if(i == max)//说明对比完了，没有差异 
	{
		printf("A = B"); 
	}
	
	return;
}


int main()
{
	SqList A,B;//A,B 
	//初始化 
	A.length = 6;
	A.listsize = LIST_INIT_SIZE;
	B.length = 8;
	B.listsize = LIST_INIT_SIZE;
	
	//初始A数组 
	printf("A元素\n");
	char *a = "xyyzxz";
	A.elem = a;//赋值 A.length 个元素 
	//打印 A
	print_sq(A);
	
	//初始B数组 
	printf("B元素:\n");
	char *b = "xyyzyxxz";
	
	B.elem = b;//赋值 B.length 个元素
	//打印 B
	print_sq(B);
	
	//比较 
	comparatively(A,B);

	return 0;
}

//打印线性表 
void print_sq(SqList a)
{

	for(int i = 0;i < a.length;i ++)
	{
		printf("%c ",*(a.elem + i));
	}
	printf("\n");
	return;
}
