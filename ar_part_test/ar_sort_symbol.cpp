/*
ģ�� sort() ���� ��������-1�� �� ������1�� �Ĵ��� �ź�
ʱ�临�Ӷ� o(n)
�ռ临�Ӷ� o(1) 
*/
#include <stdio.h>
#define Maxsize 10

// ģ�� ���� 
void sort(int a[])
{
	int count_plus = 0,count_minus = 0,count_zero = 0;//��¼ ������ �Ĵ�����ͳ�ƺ� ֱ�� ���� ʽ��ֵ 
	printf("star \n");
	//Start statistics
	for(int i = 0;i < Maxsize;i ++)
	{
		
		if(a[i] == -1)//-1
		{
			
			count_minus ++;
			
		}
		
		else if(a[i] == 0)//zero
		{
			
			count_zero ++;
			
		}
		
		else if(a[i] == 1)//1
		{
			
			count_plus ++;
			
		}
		
		else
		{
			
			printf("being error value!");
			
		}
	}
	
	//����ʽ ���� 
	int i = 0;
	while(count_minus != 0)//fill value minus
	{
	
		a[i ++] = -1;
		count_minus --;
	
	}
	
	while(count_zero != 0)//fill value zero
	{
	
		a[i ++] = 0;
	    count_zero --;
	    
	}
	
	while(count_plus != 0)//fill value plus
	{
	
		a[i ++] = 1;
	    count_plus --;
	    
	}
	
	return;
} 

//test_one
int main()
{
	int a[Maxsize] = {1,1,1,1,1,0,0,-1,0,-1};//example
	sort(a);                //���� 
	
	int i = 0;
	while(i != Maxsize)  //printf ��ӡ ԭ���� 
	{
		
		printf("%d  ",a[i ++]);
		
	}
	
	return 0;
}
