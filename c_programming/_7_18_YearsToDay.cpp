/*
�����ꡢ�¡��գ���������Ǹ���ĵڼ��졣 
*/

#include <stdio.h>
#define n 8
//�����������г� ÿ���µ�Ĭ�����������������������޸ģ�
//Ĭ�� 1��3��5��7��8��10��12ÿ��31�죬��������29�죬ƽ��28�죬�����·�30�� 
int month[13] = {0,31,28,31,30,
				 31,30,31,31,
				 30,31,30,31 
								};
//�ж�����Ƿ�Ϊ���� 
int judgement_leap(int i)
{
	if(i % 4 == 0 && i % 100 != 0 || i % 100 == 0 && i % 400 == 0)
	{
		return 1;
	}
	return 0;
}
//��ȡ��Ϊ����ĵڼ��� 
void get_date(int a[])
{
	int date = 0,year = 0,mon = 0,day = 0;
	year = a[0] * 1000 + a[1] * 100 + a[2] * 10 + a[3];//�� 
	mon = a[4] * 10 + a[5];//�� 
	day = a[6] * 10 + a[7];//�� 
	
	if(mon > 2)//����·ݴ���2�£�˵����Ҫ�жϸ����Ƿ�Ϊ���꣨�����ƽ�� 2�·�������һ����
	{
		if(judgement_leap(year) == 1)//������
		{
			month[2] = 29;//2�·�������Ϊ29��.(�����һ���±�û���ã������·����±�ͳһ) 
		}
		else;//�������� ��ƽ�꣬�ͱ���Ĭ��28�� 
	} 
	
	
	//����ڼ���(�����1��ʼ,ֹͣ��monǰ)
	//��ǰ���������� 
	for(int i = 1;i <= mon - 1;i ++ )
	{
		date = date + month[i];
	}
	//�ӵ�ǰ�·�����
	date = date + day; 
	//��ӡ 
	printf("��%d��ĵ�%d��",year,date);
	return;
}
 
int main()
{
	//���鹹�� �� 4λ���·�2λ���� 2λ
	int a[n] = {0};
	for(int i = 0;i < n;i ++)
	{
		scanf("%d",a + i);
	}
	
	get_date(a);//��ȡ�ڼ���,����ӡ��� 
		
	return 0;
}