#include <iostream>
#include <stdio.h>
#define num 4
using namespace std;

//01 ���� ���ݷ� ���ÿ�� ��� �����Ȼ�� �õ�ǰ�����ͱ������һ�������壨�����ڣ� ��ֵ ��֮ǰ���ݼ�ֵ ȡ�ϴ�ֵ 
 
int value[num] = {2,4,3,7},weight[num] = {2,3,5,5};

int dynamic_programming(int Backpack_Capacity) //���� ������� 
{
	if(Backpack_Capacity <= 0)
	{
		printf("BC error!");
	}
	int c = Backpack_Capacity;
	int index[c + 1] = {0};
	int t_value = 0;
	
	//iΪweight �� value���±�,i + 1����������� 
	for(int i = 0;i <= c;i ++)
	{
		
		//��ʼ��ֵΪ ֮ǰû��ͳ�ƹ��� ǡ�����ص��� ��ǰbp����� ���� 
		for(int k = 0;k < num;k ++)
		{
			if(weight[k] == i + 1)
			{
				index[i + 1] = value[k];
			}
		}
		
		//���� �米�����Ϊ5��ֵ �ĵ��� �������Ϊ4�ļ�ֵ + �������Ϊ1�ļ�ֵ��2+3�� 
		for(int j = 1;j <= i/2;j ++) 
		{
			t_value = index[j] + index[i + 1 - j];//����j + i + 1 - j =i + 1 =��ǰ��������� 
			if(t_value > index[i + 1])//������ �ļ�ֵ ���� ��ʼ���ļ�ֵ ���� 
			{
				index[i + 1] = t_value;
			}
		}
	}
	
	return index[c];
}

void print()
{
	int back_v = 0;
	
	while(1)
	{
		printf("Please,enter the volume of the backpack: ");
		scanf("%d",&back_v);//cin>>back_v;
		
		if(back_v <= 0)
		{
			printf("volume <= 0,program end.");
			break;
		}
		
		cout << "end result: "<< dynamic_programming(back_v) << endl;
	}
	
	return;
}

int main()
{
	print();
	return 0;
}
