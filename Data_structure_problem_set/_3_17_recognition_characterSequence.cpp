/*
识别依次读入的一个以@为结束符的字符序列是否为形如
‘序列&序列’模式的字符序列。其中两个序列都不含‘&’，且后序列为前一个序列的逆序列。
如，‘a+b&b+a’是，而‘1+3&3-1’不是。 
*/

#include <stdio.h>
//获取字符数组元素 
int get_array_size(char a[]);

//开始识别，两边往中间 判断(因为后序列是前序列的逆序列) 
void judge(char a[])
{
	
	int size = get_array_size(a);
	if(size % 2 == 0 || a[size / 2] != '&')//如果是偶数说明序列有误,或者中间不是'&'符号说明也有误
	{
		printf("错误，长度不可能是偶数!或者'&'符号位置错误");
		return;
	}//(后序列为前一个序列的逆序列(两个序列长度一样 再加上'&'符号肯定奇数))
	else;//正常继续程序
	
	//两边往中间 判断(因为后序列是前序列的逆序列) 
	int i = 0;
	for(i = 0;i < size / 2;i ++)
	{
		if(a[i] == a[size - 1 - i])
		{
			continue;
		}
		
		printf("NO!");
		break;
	}
	if(i == size / 2)//循环正常结束，说明对比完毕 
	{
		printf("YES!");
	}
	
	return;
}

int main()
{
	char a[30] = {'\0'},t;//作为全部输入
	int i = 0;
	do
	{
		scanf("%c",&t);
		if(t == '@')
		{
			break;
		}
		else
			a[i ++] = t;
	}while(1);
	//开始识别
	judge(a); 
	
	return 1;
}

//获取字符数组元素 
int get_array_size(char a[])
{
	int i = 0;
	for(i = 0;a[i] != '\0';i ++);
	return i;
}
