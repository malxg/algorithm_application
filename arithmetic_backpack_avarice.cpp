//arithmetic_backpack_avarice
#include <iostream>
#include <stdio.h>
#include <algorithm>//��sort 
#include <string.h>//����memset ��ʼ������ 
#define num 4
using namespace std;

//���� ̰���㷨
 
typedef struct{//��֤ Ȩ��sort����� ���� �����ֵ ���� һһ��Ӧ 
	double value;
	double weight;
	double proportion;
}article;
article ar[num] = {{2,2},{4,3},{5,5},{7,5}};//�ȳ�ʼ�� ������ �� ��ֵ �����������أ�value/weight�� �ú������ ���� 

double cmp(article &a,article &b)//��дsort�����ıȽϺ���
{
	return  a.proportion > b.proportion;//���ý�������
}



void greedy_method(double Backpack_Capacity) //���� ������� 
{
	if(Backpack_Capacity <= 0)
	{
		printf("Backpack volume error!");
	}
	double c = Backpack_Capacity;//�ֲ����� 
	
	double all_value = 0,all_weight = 0;
	double ar_content[num];//��¼ num������ �洢�� �������ǲ��� �ı���
	memset(ar_content,0, num * sizeof(int) );//��ʼ�� ���� int ar_content[num] = {0}; 
	
	//greedy_method run
	printf("value\tweight\tproportion\tar_content\n");
	for(int i = 0;i < num;i ++)//���أ�value/weight��
	{
		if(ar[i].weight <= c)//�ڱ��� ������ 
		{
			ar_content[i] = 1.0;//ȫ�� ���� װ��
			c = c - (ar[i].weight * ar_content[i]);
		}
		else if(ar[i].weight > c)//������������ 
		{
			ar_content[i] = (c/ar[i].weight);
			c = c - (ar[i].weight * ar_content[i]);
		}
		else;

		//count value_weight
		all_value = all_value + (ar[i].value * ar_content[i]);
		all_weight = all_weight + (ar[i].weight * ar_content[i]);
		//print result
		printf("%.2lf\t%.2lf\t%.2lf\t\t%.2lf\n",ar[i].value,ar[i].weight,ar[i].proportion,ar_content[i]);
	}
	cout << "all value:" << all_value << "\tall weight:" << all_weight << endl;//\t Ϊtapָ�� 
	
	return;
}
int main()
{
	printf("value\tweight\tproportion\n");
	for(int i = 0;i < num;i ++)//���أ�value/weight��
	{
		ar[i].proportion = ar[i].value / ar[i].weight;
	}
	
	sort(ar,ar + num,cmp);//���� Ȩ�� ������ ���� 
	
	for(int i = 0;i < num;i ++)//��� ��Ȩ�� ���� ������ 
	{
		printf("%.2lf\t%.2lf\t%.2lf\n",ar[i].value,ar[i].weight,ar[i].proportion);
	}
	
	double back_v = 0;
	while(1)//ѭ�� 
	{
		printf("\nPlease,enter the volume of the backpack: ");
		scanf("%lf",&back_v);//cin>>back_v;
		
		greedy_method(back_v); 
		
	}
	
	return 0;
}
