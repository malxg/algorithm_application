/*
正读和反读都相同的字符序列为“回文”，
现判别读入一个以'@'为结束符的字符序列是否为“回文”。 
*/
#include <stdio.h>
#define N 30

//获取字符数组长度 
int get_arrsize(char a[])
{
	int length = 0;
	while(a[length ++] != '\0');
	return length - 1;
}
//判断是否是回文 
void judege_Palindrome(char a[])
{
	int length = get_arrsize(a),i;//获取字符数组长度
	if(length == 0)
	{
		printf("数组为空!\n");
		return;
	}
	//两端向中间 靠拢 
	for(i = 0;i < length/2;i ++)
	{
		//存在不相等元素 则不是回文 
		if(a[i] != a[length - i - 1])
		{
			printf("no palindrome!!!");
			break;
		}
	} 
	
	//如果遍历正常结束 则是 
	if(i == length / 2)
	{
		printf("is palindrome");
	}
	
	return;
}

int main()
{
	char a[N] = {'\0'},c = {'\0'};
	
	int i = 0;
	//以@判断 是否结束输入 
	while(1)
	{
		scanf("%c",&c);
		if(c == '@')
		{
			break;
		}
		a[i ++] = c;
		
	}

	//开始判断是否是回文，无返回值 
	judege_Palindrome(a);
	
	return 0;
}
