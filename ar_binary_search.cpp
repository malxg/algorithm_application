/*
�ٶ�a[n]Ϊ���������������飬
��д����ʵ�� �۰루���֣����� ĳָ���ؼ���Ϊe�Ĳ�����
*/

#include <stdio.h>
#include <algorithm>//include sort()
#include <iostream>
#define n 10
using namespace std;
bool cmp(int a,int b)
{
	return a < b;//ǰ�� С�� ���ߣ����� -> �ǵݼ� 
}


void binary_search(int a[],int e,int low,int high)
{
	//binary search ������ʱ������ȡ�� 
	int mid = (low + high) / 2;
	
	//�ҵ� ���� 
	if(a[mid] == e)//��� ������ �� �ظ���e ��Ϊ ��ǰ���Ǹ�e��mid�� ����ȡ���� 
	{
		printf("search success,position is %d",mid + 1);//��mid + 1��,(mid ���±�) 
		return;
	}
	//�м�ֵ ���� Ŀ��ֵ��˵�� Ŀ��ֵ �����(����������) 
	else if(a[mid] > e)
	{
		high = mid - 1;//���С������ң��Ͻ� ��Ϊ mid - 1,�󲿷�
		binary_search(a,e,low,high);//���µ�high ��Ϊ�Ͻ� ���� �󲿷� 
	}
	//�м�ֵ С�� Ŀ��ֵ��˵�� Ŀ��ֵ ���ұ�(����������) 
	else if(a[mid] < e)
	{
		low = mid + 1;//��ϴ���ұ��ң��½� ��Ϊ mid + 1,�Ҳ���
		binary_search(a,e,low,high);//���µ�low ��Ϊ�½� ���� �Ҳ��� 
	}
	else;
	 
	return;
}

//print function
void print_arrange(int a[])
{
	for(int i = 0;i < 10;i ++)
	{
		printf("%d ",a[i]);
	}
	cout << endl;
}

int main()
{
	int a[n] = {9,2,3,10,1,11,5,2,1,4};// n == 10
	//���� ���� 
	sort(a,a + 10,cmp);//sort ���� ���� 
	print_arrange(a);
	
	int e;//���� ֵ 
	cout << "please,enter the find value: ";
	scanf("%d",&e);
	
	binary_search(a,e,0,n);
	
	return 0;
}
