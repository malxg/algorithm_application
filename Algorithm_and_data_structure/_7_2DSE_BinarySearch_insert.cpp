/*
���ö��ֲ����㷨��һ��������в���һ��Ԫ��x��
�����ֱ�������ԡ� 
*/

#include <stdio.h>
#define END 1 << 12//4096��Ϊ ��������Ľ�����ʶ 

int get_len(int a[]);//��ȡ���鳤�� 
void print_array(int a[]);//��ӡ����

int len = 0;//��������ĳ��� 
void insert(int a[],int point,int data)
{
	if(a[point] > data)//˵�� ����ֵ�ò��뵽��ǰ�� 
	{
		for(int i = len - 1;i >= point;i --)
		{
			a[i + 1] = a[i];//����ƶ�һ�� ��λ (ԭpointλ�õ�ֵҲ����ƶ�)
		}
		
		a[point] = data;//Ŀ��ֵ���뵽pointλ�� 
	}
	else//������ڵ�����ֵ�� ���뵽Ŀ��� ���� 
	{
		for(int i = len - 1;i > point;i --)
		{
			a[i + 1] = a[i];//����ƶ�һ�� ��λ (ԭpointλ�õ�ֵҲ����ƶ�)
		}
		
		a[point + 1] = data;//Ŀ��ֵ���뵽pointλ��
	}
	
}

//���ֲ��� ����λ�� ������ 
void BinarySearch(int a[],int low,int high,int data)
{
	if(low == high)//�ҵ� ����� 
	{
		insert(a,low,data);//����:���飬����㣬�������� 
		return;
	}
	int mid = (low + high)/2;//��ȡ �м�ֵ
	
	if(a[mid] < data)//midС��data �����������˵�� �ò���������mid���ұ� 
	{
		BinarySearch(a,mid + 1,high,data);
	}
	else if(a[mid] > data)//mid����data �����������˵�� �ò�����mid����� 
	{
		BinarySearch(a,low,mid - 1,data);
	}
	else//������ںͲ���ֵһ������� ֱ�Ӳ��� 
	{
		insert(a,mid,data);//����:���飬����㣬�������� 
		return; 
	}
	
	return;
}

int main()
{
	int a[101] = {1,2,2,15,16,18,20,20,30,33,END};//test ����� ENDΪ��������Ĭ��Ϊ0���������0��Ҫ�Լ������������ 
	len = get_len(a);//��ȡԪ�ظ���
	
	//print��ӡ ԭ���� 
    print_array(a);

	//����Ҫ�����ֵ
	int data = 0;

	scanf("%d",&data); 
	
	//���ֲ��� ����λ�� ������ 
    BinarySearch(a,0,len - 1,data);
    
    a[len + 1] = END;//����һ�� Ԫ�� ��� ���Ͻ����� 
    //print��ӡ ��������� ���� 
    print_array(a);
	
	return 0;
} 

//��ӡ���� 
void print_array(int a[])
{
	int size = get_len(a);//��ȡ ���������Ԫ�س��� 
	for(int i = 0;i < size;i ++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
	return;
}
//��ȡ���鳤�� 
int get_len(int a[])
{
	int i = 0;
	while(a[i] != END)
	{
		i ++;
	}

	return i;
}

