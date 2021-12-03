/*
编写对串求逆的递推算法。 
*/
#include <stdio.h>
#define N 30
//获取数组长度 
int get_arrSize(char a[]);
//打印数组
void print_arr(char a[]);
//转置 
char * string_reverse(char *s)
{
	int size = get_arrSize(s);//获取串的长度 
	size = size - 1;//由于 串后面会自动加一个结束符'\0',故空串的长度为1,真正串长得减去1 
	if(size <= 0)//串不正确 
	{
		printf("串不合法");
		return NULL;
	} 
	else;
	
	//中间数组，开始转置 
	char a[N] = {'\0'};
	for(int i = 0;i < size;i ++)
	{
		a[i] = *(s + size - 1 - i);
		printf("%c ",a[i]);
	}
	return a;
}

int main()
{
	//初始化串 
	char *s = "abcdefghijk";//注意这种赋值方法不能改变值(后面用数组获取转置)
	//开始转置
	s = string_reverse(s);
	//查看转置结果 打印 
//	print_arr(s);
	return 0;
}
//打印数组
void print_arr(char a[])
{
	for(int i = 0;a[i] != '\0';i ++)
	{
		printf("%c ",a[i]);
	}
	printf("\n");
	return;
} 
//获取数组长度 
int get_arrSize(char a[])
{
	int length = 0;
	while(a[length ++] != '\0');
	return length;
}
