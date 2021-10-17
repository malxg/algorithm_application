//count score
#include <iostream>
#include <stdio.h>
#include <string.h>
#define num 4
using namespace std;

typedef struct student
{
	char *number;//Sno
	char *name;//student name
	int score;//score
	struct studnet *next;//index next node
}linklist;

int fun1(linklist *L)
{
	int count = 0;//统计 成绩 大于等于 90（优秀）的人数 
	for(int i = 0;L[i].score != NULL;i ++)
	{
		if(L[i].score > 90)
		{
			count ++;
		}
		else;
	}
	return count;
}

int main()
{
	linklist list[num] = {{"1231","刘备",88},{"1232","关羽",101},{"1233","张飞",90},{"1234","赵云",200}};//初始表 
	printf("number\tname\tscore\n");
	for(int i = 0;i < num;i ++)
	{
		printf("%s\t%s\t%d\n",list[i].number,list[i].name,list[i].score);
	}
	printf(">=90成绩的 人数：%d \n",fun1(list));
	return 0;
}
