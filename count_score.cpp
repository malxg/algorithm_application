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
	int count = 0;//ͳ�� �ɼ� ���ڵ��� 90�����㣩������ 
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
	linklist list[num] = {{"1231","����",88},{"1232","����",101},{"1233","�ŷ�",90},{"1234","����",200}};//��ʼ�� 
	printf("number\tname\tscore\n");
	for(int i = 0;i < num;i ++)
	{
		printf("%s\t%s\t%d\n",list[i].number,list[i].name,list[i].score);
	}
	printf(">=90�ɼ��� ������%d \n",fun1(list));
	return 0;
}
