/*
��һԪ����ʽpn(x)=a(i)x^i(i~n�ĺ�)��ֵpn(x0),
��ȷ���㷨��ÿһ����ִ�д����������㷨��ʱ�临�Ӷȡ�ע��ѡ������Ϊ�Ϻõ���������������
���������Ϊa(i)(i=0,1,...,n),x0��n�����Ϊpn(x0); 
*/

#include <stdio.h>
#include <cmath>
//���� ��� 
int result = 0;//������ 
void reckon(int a[],int x0,int n)
{
	
	for(int i = 0;i < n;i ++)
	{
		result += a[i]*pow(x0,i);
	}
	return;
}

int main()
{
	int a[101] = {0},x0 = 0,n = 0;
	printf("����x0,n:\n");
	scanf("%d%d",&x0,&n);
	printf("����n��a:\n");
	for(int i = 0;i < n;i ++)
	{
		scanf("%d",&a[i]);
	}
	
	reckon(a,x0,n);//����a(i)x^i 
	
	printf("\nresult is %d",result);
	return 0;
}
