/*
�ж�����ͼG�Ƿ���ͨ��
����ͨ����1�����򷵻�0 
*/

#define N 1 >> 8 //���������Ĭ�� �ڽӾ��� 
#define size 6
#include <stdio.h>

int flag[size] = {0};//����ͼ ֻҪÿ������������һ���� ����ͨ 
int judgment(int a[][size])
{
	for(int i = 0;i < size;i ++)
	{
		for(int j = 0;j <= i;j ++)
		{
			if(a[i][j] != N && flag[j] != 1)
			{
				flag[j] = 1;
			}
		}
	}
	
	int k = 0;
	while(flag[k]){k ++;}

	if(k == size)
	{
		return 1;
	}

	return 0;
}

int main()
{
	//���� �ڽӾ������ڽӾ��� ��ʾͼ�� 
	int a[size][size] = 
	{
		1,N,N,N,N,N,
		N,2,N,N,N,N,
		N,N,3,N,N,N,
		N,N,N,4,N,N,
		N,N,N,N,5,N,
		N,N,N,N,N,6,
	};
	
	printf("%d",judgment(a));
	
	return 0;
}
