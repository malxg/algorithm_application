/*
��һ����n����װ��Ҫװ����������Ϊc���ִ������м�װ��i������Ϊwi���ҳ�һ������װ�ط��������ִ�������װ��������װ������������Ƶ�����£����������صļ�װ��װ���ִ���
*/

#include <stdio.h>
#include <iostream>
#define num 10
using namespace std;

int c1 = 0,c1x[num] = {0};          // ���� �� ���أ�����ͨ�� �û� ¼�룩 �� ѡ�� ���� ����  
int w[num] = {1,3,4,6,7,8,2,4,3,1}; //ģ�� �� ���� ���� ���� 
int bestw = 0;                      //�ڸ� ��� �� ��������� ���� �� ��ʼ������ ѡ�� ��ͬ �� ��ͬ�� 

//���� �м���  
int x[num] = {0};                   //c1x ���м��� 
int current_weight = 0;             //bestw ���м��� 


//���� dfs ��� �������ݣ�֮ǰ ������ ���� �ų� ����һ�� ������ 
void BackTrace(int t) 
{
	if(t >= num)
	{
		
		for(int i = 0;i < num;i ++)//��� 
		{
			c1x[i] = x[i];
		}
		bestw = current_weight;     //ȡ�ñ��� ��� ��������� 
		return;
	}
	
	if(w[t] > c1)
	{
		BackTrace(t + 1);
		return;
	}
	else
	{

		c1 = c1 - w[t];
		current_weight = current_weight + w[t];
		x[t] = 1;
		BackTrace(t + 1);
		//������� ���� ջ����ԭ ���� 
		current_weight = 0;
		c1 = c1 + w[t];
		x[t] = 0;
	
	}
	return;
}

//������ 
int main()
{
	
	while(1)
	{
	    int end_bestw = 0;//��¼ ���� ���� ������� 
		printf("cabin weight: ");
		
		scanf("%d",&c1); //���� ���յ� ���� 
		
		for(int i = 0;i < num;i ++)//ѡ�� �� ��ͬ�� ���� Ϊ���ڵ� ���л��ݣ�֮��ѡ���� ���ݲ��� �ų����� ���� 
		{
			bestw = 0;c1x[num] = {0};//��ʼ�� 
			
			BackTrace(i);//////��ʼ���� ��� 
			
			printf("���ӵ�%d�����￪ʼװʱ, bestw :%d\n����:",i + 1,bestw);
			for(int j = 0;j < num;j ++)//��ӡ ÿ�� ��� �� �� ����  
			{
				printf("%d ",c1x[j]);
			}
			
			if(bestw >= end_bestw)//��ÿ������������ ��ѡ�� ��������� �������� 
			{
				end_bestw = bestw;
			}
			cout << endl << endl;
		}
		cout << "�������: " << end_bestw << "\n" << endl;	
	}
	return 0;
}
