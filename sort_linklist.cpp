//count score
#include <iostream>
#include <stdio.h>
#include <algorithm>
#define maxlen 4
#define Nmax maxlen//��ʾ�ɼ� ������ 
using namespace std;

typedef struct student
{
	int score;//��ʾ�ɼ� 
}NODE;

typedef struct
{
	NODE student[Nmax];//��ʾ һ�� ÿ�ųɼ�����
	int length;//��ʾ ѧ����� 
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
		for(int j = 0;j < Nmax;j ++)//�ѿ��Գɼ� �ܷ� ��Ϊ �Ƚϳ߶ȡ� 
		{
			ex[i].all_score += S[i].student[j].score;//����ex���� ���� ���� 
		}
		ex[i].index = S[i].length;//��� 
	}
	
	sort(ex,ex + 4,cmp);//���� 
	
	printf("�����\n");
	
	for(int i = 0;i < 4;i ++)
	{
		cout << "score:" <<ex[i].all_score << " index:" << ex[i].index << endl;
	}

	return;
}

int main()//һ�� �ĸ�ѧ������ÿ�� ѧ�� ������ ���Գɼ������Ƚϣ��ѿ��Գɼ� �ܷ� ��Ϊ �Ƚϳ߶ȡ� 
{
	sqlist list[4] = {{99,120,70,63,1} , {99,100,70,62,2} , {109,100,71,60,3} , {99,123,60,64,4}};//��ʼ�� 
	
	fun2(list);//���� sqlist * 
	
	return 0;
}
