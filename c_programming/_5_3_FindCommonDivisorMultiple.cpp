/*
��������������m��n���������Լ������С�������� 
*/
#include <stdio.h>
//�����Լ�� ����ӡ 
void Find_MaxCommonDivisor(int m,int n)
{
	if(m == 0 && n == 0)
	{
		printf("Maximum common divisor is zero\n");
		return;
	}
	int mmin = (m > n ? n : m);//ȡm,n�н�Сֵ,��Ϊ���һ������ֵ 
	//���� ���� 
	int divisor = 1;//��Ϊ��һ����Լ�� 
	int i = 1;//�������� 
	while(i <= mmin)//���ܳ������ һ������ֵ 
	{
		i ++;
		//Ѱ�� 
		if(n % i == 0 && m % i == 0)
		{
			divisor = i; 
		}
	}
	printf("Maximum common divisor is %d\n",divisor);
	return;
}
//����󹫱��� ����ӡ 
void Find_MaxCommonMultiple(int m,int n)
{
	if(m == 0 && n == 0)
	{
		printf("Maximum common multiple is zero\n");
		return;
	}
	
	int i = (m > n ? m : n);//ȡm,n�нϴ�ֵ,��Ϊ��һ������ֵ 
	//���� ���� 
	while(1)
	{
		//Ѱ�� 
		if(i % n == 0 && i % m == 0)
		{
			printf("Maximum common multiple is %d\n",i);
			break;//�˳� 
		}
		i ++;//���� 
	}
	return;
}
int main()
{
	int m,n;
	printf("m,n: \n");
	scanf("%d%d",&m,&n);//����m,n 
	if(m < 0 || n < 0)//������ ��ֵ 
	{
		printf("m or n is error!!!");
		return 0;
	}
	//�����Լ�� ����ӡ 
    Find_MaxCommonDivisor(m,n);
	//����󹫱��� ����ӡ 
    Find_MaxCommonMultiple(m,n);
    
	return 0;
}
