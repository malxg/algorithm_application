/*
��� һ�� �㷨�� ���������ַ����������� ���У�

������ algorithm ���е�reverse����
���� ʹ��string.h���е�strrev����
*/

#include <stdio.h>

char c[101] = {'\0'};
/*s�ַ��� ���ܱ�ֱ�� ��ԭ�� ��ֵ(ֻ�ܴ��봮��ֵ)��
���� �Ӹ�ý��c[]����,�� �ַ�����ֵ ������,Ȼ��ת��c */

//��ת �� �������ַ� 
void weak_reverse(char *s)
{
	int len = 0;//s�ַ��� ���� 
	for(len = 0;*(s + len) != '\0';len ++);//��ȡs �ַ��� ���� 
	
	for(int i = 0;i < len;i ++)
	{
		c[i] = *(s - i + (len - 1));
	}
	
	return;
}

//��ӡ 
void prin_char(char *c)
{
	for(int i = 0;*(c + i) != '\0';i ++)
	{
		printf("%c",*(c + i));
	}
	printf("\n");
	
	return;
}

int main()
{
	char *s = "abcdefgh";
	prin_char(s);
	//��ת s �ַ��� 
	weak_reverse(s);
	//��� c �ַ���
	prin_char(c);
	 
	return 0;
}
