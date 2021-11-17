/*
顺序结构存储串
编写一个函数 index(s1,s2) 用于判断s2是否 是s1的字串，
若是，返回 其在主串的 位置，否则返回 -1 
*/

#include <stdio.h>

//传入 两个 数组 变量， 进行 遍历比对 
int index(char a[],char b[])
{
	//如果 传入的 数组 不符合 要求，直接 返回 
	if( *a == '\0' && b[0] == '\0' )
	{
		return -1;
	}
	
	
	//j 用来 保存 字串 
	int j = 0;
	for(int i = 0;a[i] != '\0';i ++)
	{
		if(a[i] == b[0])
		{
			for(j = 0;b[j] != '\0' && a[i + j] != '\0';j ++)
			{
				if(b[j] != a[i + j])//字串 和 主串 对比 
				{
					break;
				}
			}
			//说明 字串 已经遍历 到尾了，配对成功 
			if(b[j] == '\0')
			{
				return i;
			}
		}
	}
	
	return -1;
}

int main()
{
	char *a = "abcdefghigk";//这种 赋值 只能 做 查找，整串赋值操作，不能赋值其中一个字符 或者删除 
	char b[3] = {'b','c'};//等价于 *b = "bc",这两种 赋值 都会自动加结束符号'\0'
	
	
	int flag = -1;//获取 函数返回的 参数
	
	//开始 匹配 
	flag = index(a,b);
	
	//匹配 失败返回 整型 -1 
	if( flag == -1)
	{
		printf("匹配失败!");
	}
	else 
		printf("在主串位置（下标）: %d",flag);
	
	return 0;
}
