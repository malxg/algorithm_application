/*����10����������С���һ�����Ի�����������Ի�
 3���Զ��庯��������10���������10���� 
 */ 
 
#include <stdio.h>
#include <limits.h>//����INT_MAX 2147483647  �� INX_MIN -2147483648  
//#include <iostream>
//using namespace std;

//������Сֵ �� ��һλ ����:�������� �޷���ֵ 
void mmin_swap_begin(int a[])
{
	int x = INT_MAX,flag = 0;//��¼�ֲ���С �� ���±� 
	
	for(int i = 0;i < 10;i ++)
	{
		if(a[i] < x)
		{
			x = a[i];
			flag = i;
		}
	}
	
	if(flag != 0)
	{
		int t = a[0];
	    a[0] = a[flag];
	    a[flag] = t;
	}
	else;
	
	return;
}

//�������ֵ �� ���λ ����:�������� �޷���ֵ 
void mmax_swap_end(int a[])
{
	int x = INT_MIN,flag = 0;//��¼�ֲ���� �� ���±� 
	
	for(int i = 0;i < 10;i ++)
	{
		if(a[i] > x)
		{
			x = a[i];
			flag = i;
		}
	}
	
	if(flag != 9)
	{
		int t = a[9];
	    a[9] = a[flag];
	    a[flag] = t;
	}
	else;
	
	return;
}

int main()
{
	int a[10] = {0};
	
	for(int i = 0;i < 10;i ++)
	{
		scanf("%d",&a[i]);//¼�� 10 �� ���� 
	}
	
	mmin_swap_begin(a);//����С���� 
	mmax_swap_end(a);//����� ���� 
	
	for(int j = 0;j < 10;j ++)
	{
		printf("%d ",a[j]);
	}
	
	printf("\n");
	return 0;
}
