/*
��д�Դ�����ĵ����㷨�� 
*/
#include <stdio.h>
#define N 30
//��ȡ���鳤�� 
int get_arrSize(char a[]);
//��ӡ����
void print_arr(char a[]);
//ת�� 
char * string_reverse(char *s)
{
	int size = get_arrSize(s);//��ȡ���ĳ��� 
	size = size - 1;//���� ��������Զ���һ��������'\0',�ʿմ��ĳ���Ϊ1,���������ü�ȥ1 
	if(size <= 0)//������ȷ 
	{
		printf("�����Ϸ�");
		return NULL;
	} 
	else;
	
	//�м����飬��ʼת�� 
	char a[N] = {'\0'};
	for(int i = 0;i < size;i ++)
	{
		a[i] = *(s + size - 1 - i);
		printf("%c ",a[i]);
	}
	return a;
}

int main()
{
	//��ʼ���� 
	char *s = "abcdefghijk";//ע�����ָ�ֵ�������ܸı�ֵ(�����������ȡת��)
	//��ʼת��
	s = string_reverse(s);
	//�鿴ת�ý�� ��ӡ 
//	print_arr(s);
	return 0;
}
//��ӡ����
void print_arr(char a[])
{
	for(int i = 0;a[i] != '\0';i ++)
	{
		printf("%c ",a[i]);
	}
	printf("\n");
	return;
} 
//��ȡ���鳤�� 
int get_arrSize(char a[])
{
	int length = 0;
	while(a[length ++] != '\0');
	return length;
}
