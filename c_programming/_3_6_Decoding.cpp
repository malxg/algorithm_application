/*
将“China”译成密码，用原来的字母后面第4个字母代替原来字母。用putchar和printf输出字符数组。 
*/
#include <stdio.h>//含printf,scanf等 

void Decoding(char a[])
{
	int i;
	for(i = 0;a[i] != '\0';i ++)
	{
		if(i == 0)//第一个字符 是大写， 
		{
			a[i] = char((int(a[i]) + 4 - 'A')%26 + 'A');//循环 如X ASCALL码 88,A为65,按式子(88 + 4 - 65)%26 + 65 = 66 
			continue;
		}
		//其余字符是小写 
		a[i] = char((int(a[i]) + 4 - 'a')%26 + 'a');//循环 在字母表类 如x ASCALL码 120,a为97,按式子(120 + 4 - 97)%26 + 97 = 98 
	}
	return;
}
//putchar打印字符数组 
void ch_putchar(char a[]);
//打印字符数组 
void ch_printf(char a[]);
int main()
{
	char a[6] = {'C','h','i','n','a'};//要开6个空间，编译器自动填充'\0'结束符 
	ch_printf(a);
	Decoding(a);//译码 改变原字符数组
	ch_printf(a);//pritnf()
	ch_putchar(a);//putchar()
	return 0;
}
//putchar打印字符数组 
void ch_putchar(char a[])
{
	for(int i = 0;a[i] != '\0';i ++)
	{
		putchar(a[i]);
	}
	printf("\n");
	return;
}
//printf打印字符数组 
void ch_printf(char a[])
{
	for(int i = 0;a[i] != '\0';i ++)
	{
		printf("%c",a[i]);
	}
	printf("\n");
	return;
}
