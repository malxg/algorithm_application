/*
假设有A,B,C,D,E五个高等院校进行田径对抗赛，各院校的单项成绩均已存入计算机，
并构成一张表，表中每一行形式为（项目名称，性别，校名，成绩，得分）
处理上述表格，以统计各院校男，女总分和团体总分，并输出。 
*/

#include <stdio.h>
#define N 4
#define male 1
#define female 0

typedef struct student
{
	char entry[20];//项目名称
	int sex;//性别
	int number;//校名 编号 
	double result;//成绩
	double score;//得分 
}stu;

void count_score(stu a[])
{
	double sum1 = 0.0,sum1_male = 0.0,sum2 = 0.0,sum2_male = 0.0;
	
	
	for(int i = 0;i < N;i ++)
	{
		
		if(a[i].number == 111)
		{
			sum1 += a[i].score;
			if(a[i].sex == male)
			{
				sum1_male += a[i].score;
			}
		}
		else
		{
			sum2 += a[i].score;
			if(a[i].sex == male) 
			{
				sum2_male += a[i].score;
			}
		}
	}
	
	//统计结束输出 
	printf("111大学团体分:%.2lf 男:%.2lf 女:%.2lf\n",sum1,sum1_male,sum1 - sum1_male);
	printf("110大学团体分:%.2lf 男:%.2lf 女:%.2lf\n",sum2,sum2_male,sum2 - sum2_male);
	
	return;
}

int main()
{
	stu a[N] = 
	{
		
		{"100m短跑",male,111,96,9},
		{"800m长跑",female,110,93,7},
		{"800m长跑",female,111,96,10},
		{"100m短跑",male,110,100,10},
		
	};//模拟 学生数据 

	//统计 
	count_score(a);
	
	
	return 0;
} 
