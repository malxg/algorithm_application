/*
�򵥲��������������������м�����֤:
49,38,65,97,76,13,27,49 
*/
#include <stdio.h>

//��������(�ȶ��㷨)
void insertSort(int a[])
{
    int i;
    int j;
    int temp;  //����һ����ʱ���������ڽ�������ʱ�洢 
    for(i=1;i<8;i++)
	{  //�����н��б��� 
        for(j=0;j<i;j++)
		{  //����ɨ��
            if(a[i] < a[j])//��С�������� 
			{//����λ�� 
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
   }
 }

//��ӡ���� 
void prin_a(int a[]);
int main()
{
	int a[8] = {49,38,65,97,76,13,27,49};
	//�������� 
	insertSort(a);
	//��ӡ���� 
	prin_a(a);
	
	return 0;
}
//��ӡ���� 
void prin_a(int a[])
{
	for(int i = 0;i < 8;i ++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
	return;
}
