/*
ϡ��������������ԡ������߼�������Ϣ������Ԫ��
˳����ʾϡ�����

~ʵ������������ӣ����������˵����㡣

~ϡ������������ʽ  ������Ԫ���ʾ������������ ��ͨ��������ʽ�г� 
*/
#include <stdio.h>
#include <string.h>//���� memset() �� ������ (���� ��ʼ����ά����(Ҳ����ֱ�Ӹ�ֵ0������))
int main()
{
	int rows = 0,columns = 0;
	printf("���ľ��� ���� �� ����"); 
	scanf("%d%d",&rows,&columns);//������� �У��д�С �� ֵ�ĸ���
	int a[rows][columns],b[rows][columns];
	int c[rows][columns] = {0};//�洢 �˵Ľ��
	int d[rows][columns] = {0};//�洢 �˵Ľ��
	memset(a,0,sizeof(a));memset(b,0,sizeof(b));
	memset(c,0,sizeof(c));memset(d,0,sizeof(d));
	/*memset֧�� ���� 
	memset(a, 0, sizeof(arr3); ������arr3�е�ÿ��Ԫ�ض�Ϊ0 	
	memset(a, -1, sizeof(arr3);  ������arr3�е�ÿ��Ԫ�ض�Ϊ-1 
	*/
	printf("��Ԫ��1 ��\n");
	/*test_
			[0,0,0,
			1,0,1,
			0,1,1]
	*/
	printf("��,��,ֵ\n");
	int  x = 0, y = 0,v = 0;
	while(1)
	{
		scanf("%d",&x);//��Χ 1~rows 
		if(x == 0)
		{
			break;
		}
		scanf("%d%d",&y,&v);//y��Χ 1~columns
		
		a[x - 1][y - 1] = v;//�޸� ��Ӧ λ�õ�ֵ 
	}
	
	printf("\n");
	
	printf("��Ԫ��2 ��\n");
	/*test_
			[0,0,0,9
			5,0,0,7,
			0,6,0,0]
	*/
	printf("��,��,ֵ\n");
	int  x1 = 0, y1 = 0,v1 = 0;
	while(1)
	{
		scanf("%d",&x1);//��Χ 1~rows 
		if(x1 == 0)
		{
			break;
		}
		scanf("%d%d",&y1,&v1);//y��Χ 1~columns
		
		b[x1 - 1][y1 - 1] = v1;//�޸� ��Ӧ λ�õ�ֵ 
	}
	printf("\n");
	
	//���� ��� 
	for(int i = 0;i < rows;i ++)
	{
		for(int j = 0;j < columns;j ++)
		{
			c[i][j] = a[i][j] + b[i][j];
		}
	}
	
	//���� ��� 
	for(int i = 0;i < rows;i ++)
	{
		for(int j = 0;j < columns;j ++)
		{
			d[i][j] = a[i][j] * b[i][j];
		}
	}
	
	/////////////////////////////////////////
	printf("�ӵĽ��:\n");
	//��������� 
	for(int i = 0;i < rows;i ++)
	{
		for(int j = 0;j < columns;j ++)
		{
			printf("%d\t",c[i][j]);
		}
		
		printf("\n");
	}
	
	//////////////////////////////////////////
	printf("\n�˵Ľ��:\n");
	//��������� 
	for(int i = 0;i < rows;i ++)
	{
		for(int j = 0;j < columns;j ++)
		{
			printf("%d\t",d[i][j]);
		}
		
		printf("\n");
	} 
	
	return 0;
}
