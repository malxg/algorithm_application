/*
��1000֮�ڵ������������ӡ� һ����ǡ�õ���������֮�ͣ�������ͳ�Ϊ������
*/
//��6����Ϊ1��2��3����6 = 1 + 2 + 3����6Ϊ����
#include <stdio.h>
#define Size 1000
//������ ����ӡ �������� 
void Find_PerfectNumber()
{
	int sum = 0;
	for(int i = 6;i < Size;i ++)//������ (��Ȼ��6��ʼ)
	{
		sum = 0;//��ʼ��sum������ֵ 
		int a[Size/10] = {0},k = 0;//a������������ ����,k��Ϊ����ı���ָ�� 
		for(int j = 1;j <= i/2;j ++)//����������,��������������,(����ѧ֪ʶ��n�����Ӳ����� > n/2 (�������Ӳ�����������������1))
		{
			//�ܱ�����������Ϊ�������� 
			if(i % j == 0)
			{
				a[k ++] = j;//���Ӵ�������
				sum += j;//����������� �����ж��Ƿ�Ϊ���� 
			}
		}
		if(sum == i)
		{
			//��ӡ��� 
			printf("%d its factors are ",i);
			for(int j = 0;j < k - 1;j ++)
			{
				printf("%d,",a[j]);
			}
			printf("%d\n",a[k - 1]);
		}
	}
	
	return;
}
int main()
{
	Find_PerfectNumber();//Ѱ��Size���ڵ�ȫ�������Լ������� 
	return 0;
}