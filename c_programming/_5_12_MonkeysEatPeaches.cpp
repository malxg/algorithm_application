/*
猴子吃桃问题。求第一天共摘了多少个桃子。 
*/
#include <stdio.h>
//递归 
int days = 0;//天数 
int MonkeyEat(int n)
{
	days ++;
	if(n <= 1)
	{
		return n;
	}
	return MonkeyEat(n / 2 - 1);
}

int main()
{
	//蛮力 遍历 
	for(int i = 10;i < 2000;i ++)
	{
		days = 0;//初始化天数 
		//当 数量最先为1534时，第十天只有一个桃子 
		if(MonkeyEat(i) == 1 && days == 10)
		{
			printf("peaches:%d",i);
			break;
		}
	}
	return 0;
}
