/*
����n��ѧ���ĳɼ����ÿ����Ϣ�������������ɣ�Ҫ��
1�������ߵʹ������ÿ��ѧ�������֣�������ͬ��Ϊͬһ���Σ�
2���������ÿ��ѧ��������������� 
*/

#include <stdio.h>
#include <algorithm>//sort����
using namespace std;//�� algorithm�� 
#define n 15//ѧ������ 

typedef struct node{
	char name[31];//���� 
	int grade;//�ɼ�
}node,*pnode;

int cmp(node a,node b)
{
	return a.grade >= b.grade;
}

//��ӡ�����ֵ 
void print_node(node stu[]);
int main()
{
	node student[n] = 
	{
		{"����",99},
		{"����",95},
		{"������",99},
		{"����",99},
		
		{"����",35},
		{"����",69},
	    {"����",79},
		{"���",25},
		
		{"��ʮ",19},
		{"��ʮ",79},
		{"������",85},
		{"����ʤ",79},
		
		{"��ʮһ",59},
		{"��һ��",45},
		{"���γ�",91}
	};
	
	sort(student,student + n,cmp); 
	
	print_node(student);
	
	return 0;
}

void print_node(node stu[])
{
	int max = stu[0].grade;//���� ��ǰ��߷��� 
	int rank = 1;//���� 
	for(int i = 0;i < n;i ++)
	{
		printf("��%d�� %s:%d\n",rank,stu[i].name,stu[i].grade);
		if(i + 1 < n && stu[i + 1].grade != stu[i].grade)//����к�һλ����ǰһλ��������ͬ������������Ų���������β��� 
		{
			rank ++;
		}
		else; 
	}
	return;
}
