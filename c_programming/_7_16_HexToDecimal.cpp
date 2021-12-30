/*
输入一个十六进制数，输出相应的十进制数。 
*/

#include <stdio.h>
#include <cmath>//含pow(value,number)次方函数 
#define  n 101
//十六进制转化为十进制 
int decimal_hex(char a[],int size)//传入十六进制数组,和其长度 
{	
	//去除错误情况 
	if(a == '\0' && size < 1)
	{
		return 0;
	}
	//处理 
	int result = 0;//保存十进制结果 
	int i = size - 1;//数组最后一个下标 是长度减一 
	while(i >= 0)
	{
		if(a[i] >= 'A' && a[i] <= 'F')//为字符字母时
		{
			result = result + (int(a[i] - 'A') + 10) * pow(16,size - i - 1);
		}
		else if(a[i] >= '0' && a[i] <= '9')///为字符数字时 
		{
			result = result + int(a[i] - '0') * pow(16,size - i - 1);
		}
		else//输入的十六进制有误 
		{
			printf("存在非法字符，错误,end!\n");
			break;
		}
		//遍历下一个该十六进制数的字符 
		i --;
	}
	
	
	return result;
}
int main()
{
	char a[n] = {'2','B','A'};//2BA
	printf("十进制 %d ",decimal_hex(a,3));
	return 0;
} 
