/*
����һ��ʮ���������������Ӧ��ʮ�������� 
*/

#include <stdio.h>
#include <cmath>//��pow(value,number)�η����� 
#define  n 101
//ʮ������ת��Ϊʮ���� 
int decimal_hex(char a[],int size)//����ʮ����������,���䳤�� 
{	
	//ȥ��������� 
	if(a == '\0' && size < 1)
	{
		return 0;
	}
	//���� 
	int result = 0;//����ʮ���ƽ�� 
	int i = size - 1;//�������һ���±� �ǳ��ȼ�һ 
	while(i >= 0)
	{
		if(a[i] >= 'A' && a[i] <= 'F')//Ϊ�ַ���ĸʱ
		{
			result = result + (int(a[i] - 'A') + 10) * pow(16,size - i - 1);
		}
		else if(a[i] >= '0' && a[i] <= '9')///Ϊ�ַ�����ʱ 
		{
			result = result + int(a[i] - '0') * pow(16,size - i - 1);
		}
		else//�����ʮ���������� 
		{
			printf("���ڷǷ��ַ�������,end!\n");
			break;
		}
		//������һ����ʮ�����������ַ� 
		i --;
	}
	
	
	return result;
}
int main()
{
	char a[n] = {'2','B','A'};//2BA
	printf("ʮ���� %d ",decimal_hex(a,3));
	return 0;
} 
