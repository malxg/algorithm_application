/*
�����·ݺţ�������µ�Ӣ����������ָ�����鴦�� 
*/

#include <stdio.h>
//�ö�ά����ʵ�� 
int main()
{
	char a[][12] = 
	{
		" ",
		
		"January",
		"Febuary",
		"March",
		"April",
		
		"May",
		"June",
		"July",
		"August",
		
		"September",
		"October",
		"November",
		"December",
		
	};
	
	int x = 0;
	scanf("%d",&x);
	if(x > 0 && x <= 12)
		printf("%s",a[x]);
	else
	{
		printf("error!");
	}
}
