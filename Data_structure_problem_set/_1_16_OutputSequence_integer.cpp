/*
�Դ���С�������˳��������������X,Y,Z��ֵ 
*/

#include <stdio.h>


int mmax(int a,int b)//�������������ֵ 
{
	return a > b ? a : b;
}

int main()
{
	int x = 0,y = 0,z = 0;
		
	scanf("%d%d%d",&x,&y,&z);
	int max = mmax(x,mmax(y,z));//��һ�� 
	printf("%d ",max);
	if(max == x)//��һ���� xʱ 
	{
		max = mmax(y,z);//�ҵڶ��� 
		printf("%d ",max);
		if(max == y)
		{
			printf("%d ",z);//�ҵ����� 
		}
		else
		{
			printf("%d ",y);//�ҵ����� 
		}
	}
	
	else if(max == y)//��һ���� yʱ 
	{
		max = mmax(x,z);//�ҵڶ��� 
		printf("%d ",max);
		if(max == x)
		{
			printf("%d ",z);//�ҵ����� 
		}
		else
		{
			printf("%d ",x);//�ҵ����� 
		}
	}
	
	else//��һ���� zʱ 
	{
		max = mmax(x,y);//�ҵڶ��� 
		printf("%d ",max);
		if(max == x)
		{
			printf("%d ",y);//�ҵ����� 
		}
		else
		{
			printf("%d ",x);//�ҵ����� 
		}
	}
	
	return 0;
}
