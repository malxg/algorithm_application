/*
��д�㷨��
�ù鲢���򷽷�ʵ�ֶ���������a[n]�� ��������
*/


#include <stdio.h>
#include <iostream>
#define n 10
using namespace std;

int a[n] = {9,2,3,3,2,1,6,5,4,10};// n == 10 ���� ��� ��� 
//���� ˼�� ���� �ݹ��㷨 
void merge_manage(int a[],int begin,int mid,int end)
{

    int arr[n]; 
	//��ʼ �Σ���ԭ�Ĺ��� �оֲ����� ��ԭ�� ���� ���� 
	int i = 0;            //arr ���� ���±� 
	int b = begin;        //�� b �� ���� mid ��ߵ� ��ʼ 
	int other_b = mid + 1;//��  other_b ���� mid �ұߵ� ��ʼ
	
	//�� ��� ��һ�� ��ʼ�����ұߵ�һ�� ���бȽϣ��Դ����� 
	while(b <= mid && other_b <= end)
	{
		if(a[b] < a[other_b])  //������� �����������С���ұߡ� 
		{
			arr[i ++] = a[b ++];
		}
		else
		{
			arr[i ++] = a[other_b ++];
		}
	}
	
	//��� mid��� ȫ�� ¼�꣬ʣ�µ� ֱ�Ӹ�ֵ���� 
	if(begin == mid + 1)
	{
		arr[i ++] = a[ other_b ++];
	}
	//��� mid�ұ� ȫ�� ¼�꣬ʣ�µ� ��� ֱ�Ӹ�ֵ���� 
	else if(other_b == end + 1)
	{
		arr[i ++] = a[ b ++];
	}
	
	//�ֲ� ���� ¼����ϣ���ֵ�� ���Ľ�����飬��ֵ ���� ��ȡ ���� ԭ��λ�ã�l �� kҪ��Ӧ�� 
	for(int k = 0,l = begin;k < i;k ++,l ++)
	{
		a[l] = arr[k];
	}
	
	return;
}

void merge_sort(int a[],int begin,int end)
{
	if(begin == end)//��� ����һ��,������С�� 
		return;
		
	int mid = (begin + end) / 2;
	//��ʼ �֣��ֵ� ��� ����һ�� 
	merge_sort(a,begin,mid);//mid ��� ���� 
	merge_sort(a,mid + 1,end);//mid �ұ� ���� 
	
	//�� 
	merge_manage(a,begin,mid,end);
}

//print function
void print_arrange(int a[])
{
	for(int i = 0;i < n;i ++)
	{
		printf("%d ",a[i]);
	}
	cout << endl;
}
//main function
int main()
{
	print_arrange(a);
	
	merge_sort(a,0,n-1);
	print_arrange(a);
	return 0;
}
