/*
���ӳ������⡣���һ�칲ժ�˶��ٸ����ӡ� 
*/
#include <stdio.h>
//�ݹ� 
int days = 0;//���� 
int MonkeyEat(int n)
{
	days ++;
	if(n <= 1)
	{
		return n;
	}
	return MonkeyEat(n / 2 - 1);
}

int main()
{
	//���� ���� 
	for(int i = 10;i < 2000;i ++)
	{
		days = 0;//��ʼ������ 
		//�� ��������Ϊ1534ʱ����ʮ��ֻ��һ������ 
		if(MonkeyEat(i) == 1 && days == 10)
		{
			printf("peaches:%d",i);
			break;
		}
	}
	return 0;
}
