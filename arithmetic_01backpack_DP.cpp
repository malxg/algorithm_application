//arithmetic_01backpack_DP
#include <iostream>
#include <stdio.h>

#include <string.h>//����memset ��ʼ������ 
#define num 4
using namespace std;

//01 ���� ��̬�滮 0222  0235 02357
 
int value[num] = {2,4,3,7},weight[num] = {2,3,5,5};

void dynamic_programming(int Backpack_Capacity) //���� ������� 
{
	if(Backpack_Capacity <= 0)
	{
		printf("dp error!");
	}
	int c = Backpack_Capacity;
	
	int dp[num + 1][c + 1];
	memset(dp,0, (num + 1) * (c + 1) * sizeof(int) );
	
	for(int i = 0;i < num;i ++)
	{
		for(int j = 1;j < c + 1;j ++)
		{
			if(j < weight[i])//�����i������̫�� ����û�м��룬�ʴ�ʱ ���� û��i�� ����ʱ�� ����ֵ�� 
			{
				dp[i + 1][j] = dp[i][j];
			}
			else
			{
				dp[i + 1][j] = max(dp[i][j],dp[i][j - weight[i]] + value[i]);//�� ǰһ�� �� �������ݱȽϣ���ȥ i������ ����ֵ�� 
			}
			
		}
	}
	
	for(int i = 0;i < num + 1;i ++)
	{
		//��ӡdp���� 
		for(int j = 0;j < c + 1;j ++)
		{
			printf("%d\t",dp[i][j]);
		}
		printf("\n");
	}
	
	return;
}
int main()
{
	int back_v = 0;
	while(1)//ѭ�� 
	{
		printf("Please,enter the volume of the backpack: ");
		scanf("%d",&back_v);//cin>>back_v;
		
		if(back_v <= 0)
		{
			printf("volume <= 0,program end.");
			break;
		}
		
		dynamic_programming(back_v);
	}
	
	return 0;
}
