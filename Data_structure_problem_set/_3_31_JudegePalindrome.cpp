/*
�����ͷ�������ͬ���ַ�����Ϊ�����ġ���
���б����һ����'@'Ϊ���������ַ������Ƿ�Ϊ�����ġ��� 
*/
#include <stdio.h>
#define N 30

//��ȡ�ַ����鳤�� 
int get_arrsize(char a[])
{
	int length = 0;
	while(a[length ++] != '\0');
	return length - 1;
}
//�ж��Ƿ��ǻ��� 
void judege_Palindrome(char a[])
{
	int length = get_arrsize(a),i;//��ȡ�ַ����鳤��
	if(length == 0)
	{
		printf("����Ϊ��!\n");
		return;
	}
	//�������м� ��£ 
	for(i = 0;i < length/2;i ++)
	{
		//���ڲ����Ԫ�� ���ǻ��� 
		if(a[i] != a[length - i - 1])
		{
			printf("no palindrome!!!");
			break;
		}
	} 
	
	//��������������� ���� 
	if(i == length / 2)
	{
		printf("is palindrome");
	}
	
	return;
}

int main()
{
	char a[N] = {'\0'},c = {'\0'};
	
	int i = 0;
	//��@�ж� �Ƿ�������� 
	while(1)
	{
		scanf("%c",&c);
		if(c == '@')
		{
			break;
		}
		a[i ++] = c;
		
	}

	//��ʼ�ж��Ƿ��ǻ��ģ��޷���ֵ 
	judege_Palindrome(a);
	
	return 0;
}
