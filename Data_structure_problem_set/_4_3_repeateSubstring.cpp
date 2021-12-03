/*
在定长顺序存储结构表示串，求串中出现的第一个最长重复子串及其位置。 
*/

#include <stdio.h>
#define N 31

//直接子串和子串比较，查看所有字符串
//比如 字符串 aabcbc, 先遍历第一个元素a,从第二个开始找，找到某个跟他一样的，
//开始游标k++,j++...然后记录相等子串长度;以此找到最长重复子串

//在a[]数组中 以当前i下标开始 和 以k下标开始 开始游标比对（找到相同元素的时候调用，看它们之后的元素是否仍匹配） 
int find_SonSize(int i,int k,char a[])//返回 匹配长度值(>= 1) 
{
	int length = 1;//因为是找到第一个相同元素时调用，故初始化为1 
	//能到这,i + k的值就是 下一个匹配点的下标 
	int cursor = i + 1;//定义游标1 
	int j = k + 1;//游标2 
	
	while(cursor < k)//需要不超过 i开始 下一个匹配点 k的地址即小于k
	{
		
		if(a[cursor ++] == a[j ++])
		{
			length ++;//长度+1	
		}
		else//不匹配 
		{
			break;//退出 
		}
	}
	return length;
}

int find_MaxSubstring(char a[])
{
	int position = -1;
	
	int k = 0;//游标1
	int length = 0,local_l = 0;
	for(int i = 0;a[i] != '\0';i ++)
	{
		
		
		k = i;//寻找 第二次出现的地点 
		while(a[k] != '\0')
		{
			k ++;
			//说明找到一个与当前元素匹配 有重复 
			if(a[k] == a[i])
			{
				
				length = find_SonSize(i,k,a);//返回以i下标开始 和 以k下标开始 的串匹配长度
				//printf("i:%d,k:%d,length:%d\n",i,k,length);//测试 
				if(length > local_l)
				{
					local_l = length;//更新最长长度 
					position = i;    //更新其首地址 
				}
			}
		}
	}
	
	printf("最长重复 子串 长度%d \n",local_l);
	return position;
}

//测试 
int main()
{
	//定长 串 
	char a[N] = {'a','a','a','b','c','a','b','c','a','b','c','b','c'};
	
	//打印
	for(int i = 0;a[i] != '\0';i ++)
	{
		printf("%c ",a[i]);
	}
	printf("\n"); 
	//寻找位置 
	int position = find_MaxSubstring(a);//返回第一个最长重复子串的位置 
	
	//打印 
	printf("The position of the substring is %d",position);
	printf("\n");
	
	return 0;
}

