/*
������������ȷ� ������ ���ʽ ��ֵ
��������ȷ� ��ʽ �� �ն� �����﷨��ȷ������������ ���� ���ʽ
ʵ�� ������ ������� ���ʽ �� ��ֵ ������ �����ջ�������ַ�����Ҫ�����仯���� 
*/

#include <stdio.h>
#include <string.h>//���� strlen() 
#include <queue>
using namespace std;

//������ �� ���� �ֱ���� ����ջ�� 
queue<char> symbol,data;
//��ȡ ���� �� ���� ���� 
void extrct(char a[])
{
	int size = strlen(a);
	
	if(a[0] == '-' || a[0] == '+')
	{
		data.push('0');
	}
	
	for(int i = 0;i < size;i ++)//���� ��ȡ 
	{
		if(a[i] == '*' || a[i] == '/' || a[i] == '+' || a[i] == '-')
		{
			symbol.push(a[i]);//���Ž��� 
		}
		else
		{
			data.push(a[i]);//���� ���� 
		}
	}
	
	return;
}

//���� ���� ����������� ���� ���� 
int oporator(int flag)//falg ���� ��ʶ �� �˳� ��ʽ�Ƿ� �� ��(1) ��(0) 
{

	int result = 0;
	char b[2];//��� ���� 
	
	while( symbol.empty() != 1)//empty() ��ջΪ���򷵻���
	{ 
		
		if(result == 0)//��� result Ϊ ��ʼ״̬���� ��ֵ�����������Ԫ�أ���ֵ ��ʼֵ 
		{
			b[0] = data.front();//������ ԭʽ ƫǰ 
			data.pop();       //���� 
			
			result = int(b[0] - '0');
		}
		
		
		if(symbol.front() == '*')// �˷� �� 3*2 ��3 �Ѿ��� result ��ȡ��ֻ��Ҫ ��ȡ2  
		{
			b[1] = data.front();
			data.pop();
			result *= int(b[1] - '0');
			symbol.pop();
		}
		
		else if(symbol.front() == '/')//���� �� 3/2 ��3 �Ѿ��� result ��ȡ��ֻ��Ҫ ��ȡ2  
		{
			b[1] = data.front();
			data.pop();
			result /= int(b[1] - '0');
			symbol.pop();
		}
		
		else if(symbol.front() == '+')//Ϊ +�� ��flag = 1 
		{
			symbol.pop();
			if(flag == 0)//˵�� ʽ��ǰ���и� -��,��� �������� ���� + ʵ��Ϊ -��-ʵ��Ϊ +
			{
				if(symbol.front() == '*' || symbol.front() == '/')
					result -= oporator(1);//Ϊ +�� ��flag = 1 ���� ���� ��һ�� �˳�ʽ ������ 
				else
				{
					b[1] = data.front();
					data.pop();
					result -= int(b[1] - '0');
				}
				continue;
			}
			else;
			
			//ǰ���� ���ţ����÷�ת ������� 
			if(symbol.front() == '*' || symbol.front() == '/')
				result += oporator(1);
			else
			{
				b[1] = data.front();
				data.pop();
				result += int(b[1] - '0');
			}
		}
		
		else if(symbol.front() == '-')//Ϊ +�� ��flag = 0 
		{	
			symbol.pop();
			if(flag == 0)//˵�� ʽ��ǰ���и� -��,��� �������� ���� + ʵ��Ϊ -��-ʵ��Ϊ +
			{
				if(symbol.front() == '*' || symbol.front() == '/')
					result += oporator(0);//���� ���� ��һ�� �˳�ʽ ������  
				else
				{
					b[1] = data.front();
					data.pop();
					result += int(b[1] - '0');
				}
				continue;
			}
			else;
			
			//ǰ���� ���ţ����÷�ת ������� 
			if(symbol.front() == '*' || symbol.front() == '/')
				result -= oporator(0);
			else
			{
				b[1] = data.front();
				data.pop();
				result -= int(b[1] - '0');
			}
				
		}
		
	}

	return result;
}

int main()
{
	char a[20];
    
	//֧�� 0~9 ��Χ �� -3*1+2*4-9/3 
	printf("�������������ʽ: ");
	scanf("%s",a);// ������̣�Ĭ�� �� �Իس�������
	
	extrct(a);//��ȡ ���� �� ���� �� �������У������-������+������ǰ�� ���� ���� �÷��� ǰ��0,������� 
	
	printf("result:%d",oporator(1));// �����ʼ��-�������ǰ��Ӹ�0���� ��ʼ���ݱ�Ϊ�� ���� 0 
	
	return 0;
}
