/*
������A,B,C,D,E����ߵ�ԺУ�����ﾶ�Կ�������ԺУ�ĵ���ɼ����Ѵ���������
������һ�ű�����ÿһ����ʽΪ����Ŀ���ƣ��Ա�У�����ɼ����÷֣�
�������������ͳ�Ƹ�ԺУ�У�Ů�ֺܷ������ܷ֣�������� 
*/

#include <stdio.h>
#define N 4
#define male 1
#define female 0

typedef struct student
{
	char entry[20];//��Ŀ����
	int sex;//�Ա�
	int number;//У�� ��� 
	double result;//�ɼ�
	double score;//�÷� 
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
	
	//ͳ�ƽ������ 
	printf("111��ѧ�����:%.2lf ��:%.2lf Ů:%.2lf\n",sum1,sum1_male,sum1 - sum1_male);
	printf("110��ѧ�����:%.2lf ��:%.2lf Ů:%.2lf\n",sum2,sum2_male,sum2 - sum2_male);
	
	return;
}

int main()
{
	stu a[N] = 
	{
		
		{"100m����",male,111,96,9},
		{"800m����",female,110,93,7},
		{"800m����",female,111,96,10},
		{"100m����",male,110,100,10},
		
	};//ģ�� ѧ������ 

	//ͳ�� 
	count_score(a);
	
	
	return 0;
} 
