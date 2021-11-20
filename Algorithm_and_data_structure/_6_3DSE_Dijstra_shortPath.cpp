/*
����һ����Ȩ·���� ����ͼ,����ͼ,
�����v0������������������·��
����Dijstra�㷨��һ�����㵽�������ж�������·�� 

*/
#define N 1 << 12 //4096,������������Ĭ�� �ڽӾ��� 
#define size 6
#include <stdio.h>

//costΪ��Ȩ����ͼ���ڽӾ���vΪָ���� Դ�㣨���Ǹ��㿪ʼ�� 
void dijstra(int cost[size][size],int v);

int main()
{
	//���� �ڽӾ������ڽӾ��� ��ʾͼ��
	//������ ����ͼ���ԣ�����ͼ ���� �����ڽӾ��������ڶԽ��߶Գ�
	int a[size][size] = 
	{
		N ,N ,10,N ,30,100,
		N ,N ,5 ,N ,N ,N  ,
		N ,N ,N ,50,N ,N  ,
		N ,N ,N ,N ,N ,10 ,
		N ,N ,N ,20,N ,60 ,
		N ,N ,N ,N ,N ,N  ,
	};
	//���� ��Ȩ����ͼ���ڽӾ���vΪָ���� Դ�㣨���Ǹ��㿪ʼ��
	dijstra(a,0);//V0 ~ V(size - 1),һ�� size������ 
	
	return 0;
}
//costΪ��Ȩ����ͼ���ڽӾ���vΪָ���� Դ�㣨���Ǹ��㿪ʼ�� 
void dijstra(int cost[size][size],int v)
{
	printf("Դ����%d\n",v);
	int dist[size],s[size],rear[size];//dist[i]��ǰԴ�㵽����i����С����,s��ʾ���뼯�ϱ�ʶ 
	int q[size][size]; 
	
	int i,j,k,mmin,m;
	//��ʼ��s��rear 
	for(i = 0;i < size;i ++)
	{
		s[i] = 0;
		rear[i] = -1;
	}
	//��ʼ�� dist��q
	for(i = 0;i < size;i ++)
	{
		dist[i] = cost[v][i];
		
		if(dist[i] < N)
		{
			q[i][++ rear[i]] = v;
			q[i][++ rear[i]] = i;
		}
	}
	
	s[v] = 1;//v���� ���� 
	
	//Դ���Լ����룬�ٲ��� size - 1����� 
	for(k = 0;k < size - 1;k ++)
	{
		mmin = N;j = v;
		for(i = 0;i < size;i ++)//ѡ����С��dist[j] 
		{
			if(s[i] == 0 && dist[i] < mmin)//�����ʶΪ0��û�б����������е� i �� ·�� 
			{
				j = i; //������index ��ֵΪi 
				mmin = dist[i];//���� dist   
			}
		}
		if(j != i)
		{
			s[j] = 1;//������ʶ Ϊ 1�������ظ����� 

						
			if(dist[j] == N)//dist[j] ���������˵�� û�е���� ���·��,�޳�Դ�㵽�� û��·����index 
			{
				break;
			}
			
			printf("\nthe %d shortestdistance is %d\n",j,dist[j]);

			for(i = 0;i <= rear[j];i ++)//�鿴 path 
			{
				printf("-->%d",q[j][i]);//��ӡ��Դ�㵽j�����·�� 
			}
			
			for(i = 0;i < size;i ++)//�޸Ĵ�Դ�㵽����������̾��� 
			{
				if( s[i] == 0 && ( (dist[j] + cost[j][i]) < dist[i] ) )
				{
					dist[i] = dist[j] + cost[j][i];    //����Դ�� ��ÿ����� ���·�� 
					for(m = 0;m <= rear[j];m ++)
					{
						q[i][m] = q[j][m]; //�޸���Ӧ��·�� 
					}
				
					rear[i] = rear[j];
					q[i][++ rear[i]] = i;
				}
				
				
			}
		}
		
	}
	
	return;
}
