/*
在有n个学生的成绩表里，每条信息由姓名与分数组成，要求：
1按分数高低次序，输出每个学生的名字，分数相同的为同一名次，
2按名次输出每个学生的姓名与分数。 
*/

#include <stdio.h>
#include <algorithm>//sort函数
using namespace std;//含 algorithm库 
#define n 15//学生个数 

typedef struct node{
	char name[31];//姓名 
	int grade;//成绩
}node,*pnode;

int cmp(node a,node b)
{
	return a.grade >= b.grade;
}

//打印结点数值 
void print_node(node stu[]);
int main()
{
	node student[n] = 
	{
		{"张三",99},
		{"李四",95},
		{"王麻子",99},
		{"张三",99},
		
		{"张五",35},
		{"王六",69},
	    {"张七",79},
		{"李八",25},
		
		{"王十",19},
		{"张十",79},
		{"李西奥",85},
		{"王德胜",79},
		
		{"张十一",59},
		{"李一筹",45},
		{"王澄澄",91}
	};
	
	sort(student,student + n,cmp); 
	
	print_node(student);
	
	return 0;
}

void print_node(node stu[])
{
	int max = stu[0].grade;//保存 当前最高分数 
	int rank = 1;//名次 
	for(int i = 0;i < n;i ++)
	{
		printf("第%d名 %s:%d\n",rank,stu[i].name,stu[i].grade);
		if(i + 1 < n && stu[i + 1].grade != stu[i].grade)//如果有后一位且与前一位分数不相同，则名次往后挪，否则名次不变 
		{
			rank ++;
		}
		else; 
	}
	return;
}
