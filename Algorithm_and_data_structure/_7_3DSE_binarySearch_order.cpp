/*
���ö��ֲ����㷨��������һ��Ԫ�����ȽϵĴ��� 
*/

#include <stdio.h>
#define END 1 << 12//4096��Ϊ ��������Ľ�����ʶ 

int get_len(int a[]);//��ȡ���鳤�� 
void print_array(int a[]);//��ӡ����

int len = 0;//��������ĳ��� 
int count = 0;//��¼��������һ��Ԫ�����ȽϵĴ��� 
//���ֲ���
int c[20] = {0};
int BinarySearch(int a[],int low,int high,int data)
{
	if(low > high)//����ʧ�� 
	{
		return 0;
	}
	
	int mid = (low + high)/2;//��ȡ �м�ֵ
	
	c[count] = a[mid];
	int flag = 0;//��ȡ���ҽ�� 
	count ++;//���Ҵ��� + 1
	
	if(a[mid] < data)//midС��data �����������˵�� ������ ������mid���ұ� 
	{
		flag = BinarySearch(a,mid + 1,high,data);
	}
	else if(a[mid] > data)//mid����data �����������˵�� ������ ����mid����� 
	{
		flag = BinarySearch(a,low,mid - 1,data);
	}
	else//���ҳɹ� 
	{
		return 1;
	}
	
	
	return flag;
}

int main()
{
	int a[101] = {1,2,2,15,16,18,20,20,30,33,END};//test ����� ENDΪ��������Ĭ��Ϊ0���������0��Ҫ�Լ������������ 
	len = get_len(a);//��ȡԪ�ظ��� ������(END) 

	//print��ӡ ԭ���� 
    print_array(a);

	//����Ҫ���ҵ�ֵ
	int data = 0;

	scanf("%d",&data); 
	
	//���ֲ��� 
    int flag = BinarySearch(a,0,len - 1,data);
    
    //print��ӡ���� 
    if(flag == 1)//���ҳɹ�
    {
    	printf("���ҳɹ������Ҵ���:%d \n������\n",count);
    	for(int i = 0;c[i] != 0;i ++)
    	{
    		printf("%d ",c[i]);
		}
	}
	else
	{
		printf("����ʧ�ܣ�û�и�Ԫ��");
	}
	
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

