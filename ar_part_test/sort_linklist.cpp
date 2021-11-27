//count score
#include <iostream>
#include <stdio.h>
#include <algorithm>
#define maxlen 4
#define Nmax maxlen//表示成绩 最大个数 
using namespace std;

typedef struct student
{
	int score;//表示成绩 
}NODE;

typedef struct
{
	NODE student[Nmax];//表示 一个 每门成绩数组
	int length;//表示 学生序号 
}sqlist;

typedef struct
{
	int all_score;
	int index;
}stu;

bool cmp(stu a,stu b)
{
	return a.all_score > b.all_score;
}


void fun2(sqlist *S)
{
	stu ex[4] = {0,0};
	
	for(int i = 0;i < 4;i ++)
	{
		for(int j = 0;j < Nmax;j ++)//把考试成绩 总分 作为 比较尺度。 
		{
			ex[i].all_score += S[i].student[j].score;//放在ex数组 便于 排序 
		}
		ex[i].index = S[i].length;//标号 
	}
	
	sort(ex,ex + 4,cmp);//排序 
	
	printf("排序后\n");
	
	for(int i = 0;i < 4;i ++)
	{
		cout << "score:" <<ex[i].all_score << " index:" << ex[i].index << endl;
	}

	return;
}

int main()//一共 四个学生，且每个 学生 有四门 考试成绩用来比较，把考试成绩 总分 作为 比较尺度。 
{
	sqlist list[4] = {{99,120,70,63,1} , {99,100,70,62,2} , {109,100,71,60,3} , {99,123,60,64,4}};//初始表 
	
	fun2(list);//参数 sqlist * 
	
	return 0;
}
