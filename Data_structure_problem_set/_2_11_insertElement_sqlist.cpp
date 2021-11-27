/*
设顺序表va中的数据元素递增有序。先实现将x插入
到顺序表的适当位置上，保存该表的有序性。 
*/
#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10
#include <stdio.h>

typedef struct{
	int *elem;//存储空间的基址 
	int length;//当前长度 
	int listsize;//当前分配的存储容量 
}SqList;//顺序表类型 
 
//打印线性表 
void print_sq(SqList a);

//合理位置插入元素x 
void insert(SqList &a,int x)
{
	//遍历
	for(int i = 0;i < a.length;i ++)
	{
		//printf("1");
		if(*(a.elem + i) > x || i == a.length - 1)
		{
			if(i == a.length - 1 && *(a.elem + i) < x)//处理不需要 移位的情况 
			{
				*(a.elem + a.length) = x;//直接插入到末尾的下一个空间 
			}
			else//递增 第一个 大于x的元素，说明这里就是插入点
			{
			//	printf("2");
				//该位置的元素全部向后移动一个位置 
				for(int j = a.length;j > i;j --)
				{
					*(a.elem + j) = *(a.elem + j - 1);
				}
			//	printf("3");
				//移位完毕 插入 
				*(a.elem + i) = x;
			//	printf("4");
			}
			
			a.length = a.length + 1;//插入一个元素 长度+1 
			break; //插入x完毕 退出 
		}
		//继续找  
	} 
	
	return;
}


int main()
{
	SqList a;
	//初始化 
	a.length = 5;
	a.listsize = LIST_INIT_SIZE;
	for(int i = 0;i < a.length;i ++)
	{
		*(a.elem + i) = i;//赋值 
	}
	//打印 
	print_sq(a);
	
	//插入
	int x = 0;
	while(1)
	{
		printf("插入 以0 为结束符\n");
		scanf("%d",&x);
		if(x == 0)
		{
			break;
		}
		insert(a,x);
		//再次打印
		print_sq(a);
	}

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
