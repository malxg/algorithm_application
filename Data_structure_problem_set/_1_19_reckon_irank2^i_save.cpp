/*
����i!*2^i(i=0,1,...,n-1)��ֵ���ֱ��������a[arrsize]�ĸ��������С�
����������������������ֵΪMAXINT,��n>arrsize���ĳ��k(0<=k<=n-1)
ʹk!*2^k>MAXINTʱ��Ӧ�ð�������ע��ѡ������Ϊ�Ϻõĳ��������� 
*/
#define MAXINT 1<<25//������Ϊ�����ʶ 
#define arrsize 1001
#include <stdio.h>
#include <cmath>

long long int a[arrsize] = {0};//���������� 

void reckon_(long int n)
{
	if(n > arrsize)
	{
		printf("n����");
		return;
	}
	
	for(long int i = 0;i < n;i ++)//i=0,1,...,n-1
	{
		if(i == 0)
		{
			a[i] = 1;
			continue;
		}
		
		long int rank = 1;//����i�Ľ׳˵�ֵ 
		long int j = i;
		while( j != 0)
		{
			rank *= j;
			j --;
		}
		
		if(abs(rank * pow(2,i)) > MAXINT)
		{
			printf("������,����!");
			break;
		}
		a[i] = rank * pow(2,i);
		
		
	}
	return;
}
void print_array();//��ӡ���� 
int main()
{
	long int n = 0;
	scanf("%d",&n);//����n 
	reckon_(n);//calculation
	print_array();//��ӡ���� 
	return 0;
} 

void print_array()
{
	for(int i = 0;a[i] != 0;i ++)
	{
		printf("%lld ",a[i]);
	}
	printf("\n");
	return;
}
