/*
һ�����100m�߶��������䣬ÿ�η�����һ��߶ȣ������£���10�ι��̹����������ף��͵�10�η������ 
*/
#include <stdio.h>
#define Begin_high 100
int main()
{
	double h = Begin_high,sum = Begin_high;//double float �ʼ����100m 
	int i = 1;
	while(i <= 9)//�����Ƚ���9�η��� 
	{
		h = h / 2;//���� 
		sum += 2 * h;//ͳ�ƾ���·�̣���Ϊ �����߶ȵ����� 
		i ++;//��һ�� 
	}
	//������9�η������ٽ���һ�η���
	h = h / 2; 
	printf("��10������ʱ������%lf�ף��͵�10�η���%lf",sum,h);
	
	return 0;
}
