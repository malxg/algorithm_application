/*
����China��������룬��ԭ������ĸ�����4����ĸ����ԭ����ĸ����putchar��printf����ַ����顣 
*/
#include <stdio.h>//��printf,scanf�� 

void Decoding(char a[])
{
	int i;
	for(i = 0;a[i] != '\0';i ++)
	{
		if(i == 0)//��һ���ַ� �Ǵ�д�� 
		{
			a[i] = char((int(a[i]) + 4 - 'A')%26 + 'A');//ѭ�� ��X ASCALL�� 88,AΪ65,��ʽ��(88 + 4 - 65)%26 + 65 = 66 
			continue;
		}
		//�����ַ���Сд 
		a[i] = char((int(a[i]) + 4 - 'a')%26 + 'a');//ѭ�� ����ĸ���� ��x ASCALL�� 120,aΪ97,��ʽ��(120 + 4 - 97)%26 + 97 = 98 
	}
	return;
}
//putchar��ӡ�ַ����� 
void ch_putchar(char a[]);
//��ӡ�ַ����� 
void ch_printf(char a[]);
int main()
{
	char a[6] = {'C','h','i','n','a'};//Ҫ��6���ռ䣬�������Զ����'\0'������ 
	ch_printf(a);
	Decoding(a);//���� �ı�ԭ�ַ�����
	ch_printf(a);//pritnf()
	ch_putchar(a);//putchar()
	return 0;
}
//putchar��ӡ�ַ����� 
void ch_putchar(char a[])
{
	for(int i = 0;a[i] != '\0';i ++)
	{
		putchar(a[i]);
	}
	printf("\n");
	return;
}
//printf��ӡ�ַ����� 
void ch_printf(char a[])
{
	for(int i = 0;a[i] != '\0';i ++)
	{
		printf("%c",a[i]);
	}
	printf("\n");
	return;
}
