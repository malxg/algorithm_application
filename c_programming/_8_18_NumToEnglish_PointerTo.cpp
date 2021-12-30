/*
输入月份号，输出该月的英文月名。用指针数组处理 
*/

#include <stdio.h>
//用二维数组实现 
int main()
{
	char a[][12] = 
	{
		" ",
		
		"January",
		"Febuary",
		"March",
		"April",
		
		"May",
		"June",
		"July",
		"August",
		
		"September",
		"October",
		"November",
		"December",
		
	};
	
	int x = 0;
	scanf("%d",&x);
	if(x > 0 && x <= 12)
		printf("%s",a[x]);
	else
	{
		printf("error!");
	}
}
