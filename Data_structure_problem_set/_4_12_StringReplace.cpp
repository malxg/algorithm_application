/*
编写一个实现串的置换操作Replace(&S,T,V).
*/

#include <stdio.h>
//获取串长度 
int get_stringSize(char *p);
//打印 
void print_string(char *p);
// 串的置换操作 用串v置换出 串s中与t相同的所有非空串 
void replace(char s[],char t[],char v[])
{
	int len_v = get_stringSize(v);
	int len_t = get_stringSize(t);
	int len_s = get_stringSize(s);
	
	if(len_s < len_t || len_v == 0 || len_t == 0 || len_s == 0)//串不能为空,且子串 不能比主串长 
	{
		printf("替换失败,串不符合规定!!!\n");
		return;
	}
	
	int i = 0,j = 0;
	for(i = 0;s[i] != '\0';i ++)
	{
		for(j = 0;t[j] != '\0';j ++)
		{
			if(s[i + j] == t[j])
			{
				continue;
			}
			break;
		}
		
		//比对找到了一个 
		if(t[j] == '\0')
		{
			//如果要替换的串t 长度大于 替换串v 
			if(len_t >= len_v)
			{
				//先替换 再腾位置 
				//替换 
				for(int k = 0;k < len_v;k ++)
				{
					s[i + k] = v[k];
				}
				//因为 替换后仍有 无效数据，后面数据向前靠拢
				int sub = len_t - len_v;//向前靠拢空间为 sub
				for(int k = i + len_v;k < len_s;k ++)
				{
					s[k] = s[k + sub];
				}//最后sub位 元素 会被自己赋值为空，省了赋空操作 
			}
			else//len_t < len_v要替换的串t 长度小于 替换串v
			{
				//先腾位置 再替换
				//向后 腾位置 
				int sub = len_v - len_t;
				for(int k = len_s - 1;k >= i + len_t;k --)
				{
					s[k + sub] = s[k];
				}
				//位置腾出，开始替换
				for(int k = 0;k < len_v;k ++)
				{
					s[i + k] = v[k];
				}
			}
			
			//原s 串 的长度 发生了 变化，更新s串长度 
			len_s = get_stringSize(s);
		}
		else;//没有找到 break结束 
	}
	return;
}

int main()
{
	char s[50] = {'a','b','c','d','a','b','c','a','b'};//初始化一个串,需要修改定义成字符数组 
	char *t = "bcd";//只需要查找，不修改定义成字符串指针 
	char *v = "BCD";//只需要查找，不修改定义成字符串指针 
	//串的转置 
	replace(s,t,v);
	print_string(s);
	return 0;
}

//获取串长度 
int get_stringSize(char *p)
{
	int i = 0;
	while(*(p + i) != '\0'){i ++;}
	return i;
}

void print_string(char *p)
{
	for(int i = 0;*(p + i) != '\0';i ++)
	{
		printf("%c ",*(p + i));
	}
	printf("\n");
	return;
}
