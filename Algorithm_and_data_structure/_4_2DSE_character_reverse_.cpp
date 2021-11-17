/*
设计 一个 算法将 串中所有字符倒过来重新 排列，

类似于 algorithm 库中的reverse函数
或者 使用string.h库中的strrev函数
*/

#include <stdio.h>

char c[101] = {'\0'};
/*s字符串 不能被直接 在原串 赋值(只能串与串赋值)，
或者 加个媒介c[]数组,让 字符串的值 付给它,然后转置c */

//反转 串 中所有字符 
void weak_reverse(char *s)
{
	int len = 0;//s字符串 长度 
	for(len = 0;*(s + len) != '\0';len ++);//获取s 字符串 长度 
	
	for(int i = 0;i < len;i ++)
	{
		c[i] = *(s - i + (len - 1));
	}
	
	return;
}

//打印 
void prin_char(char *c)
{
	for(int i = 0;*(c + i) != '\0';i ++)
	{
		printf("%c",*(c + i));
	}
	printf("\n");
	
	return;
}

int main()
{
	char *s = "abcdefgh";
	prin_char(s);
	//反转 s 字符串 
	weak_reverse(s);
	//输出 c 字符串
	prin_char(c);
	 
	return 0;
}
