/*
���������������������м�����֤:
49,38,65,97,76,13,27,49 
*/

#include <stdio.h>

//��������(���ȶ��㷨)
void quickSort(int a[],int begin,int end)
{
	
	if(begin == end)//���˱ȶ���� 
	{
		return;
	}
	
	int b = begin,e = end;//begin ��Ϊ��ʶ����b = begin + 1 ��Ҫ��������ݵ���� 
	int t = 0,temp = 0;//ǰ�ߴ洢begin��ֵ Ϊ��end��ֵ����,���߱�ʶ������ֵ����
	int flag = 0;//��ʶ ��һ���� �Ƿ����� ����
	while(e != b)//Ѱ�� a[begin]��ʶ���ݵĲ���λ�ã�����߶��Ǳ�a[0]С�ģ��ұ��Ǳ�a[0]��ģ� 
	{

		//�ȶ� endָ�� �ҵ���a[begin]��ʶС�ģ�Ĭ����a[begin]�����֣� 
		while(a[e] >= a[begin] && e > b)
		{
			e --;
		}
		//��beginָ���ҵ���a[begin]��ʶ��� 
		while(a[b] <= a[begin] && b < e)
		{
			b ++;
		}
		
		if(b == e)//˵������ ��ɣ�ֱ���˳���������һ�� 
		{
			break;
		}
		else
		{
			//˵��beginָ���ֵ����a[begin],endָ���ֵС��a[begin] 
			t = a[b];//���� 
			a[b] = a[e];
			a[e] = t;
			flag = 1;
		}
			
	}
	//��ʶ������ֵ����(������ʶ ������һ��)
	temp = a[begin];//���� 
	a[begin] = a[e];
	a[e] = temp;
	
	if(flag == 1)//�����˽���˵�� ����ֵ���м䣬�������߶��� ���� 
	{	
		//���Ͽ������� һ������ ȷ����һ��a[begin]Ԫ�ص�����λ�á� 
		//������� �������� ���� 
		quickSort(a,begin,e - 1);//������ߵݹ� ������һ��
		quickSort(a,e + 1,end);//�����ұߵݹ� ������һ��
	}
	else//û�з�������˵��������ֵ��û���������е�����ߣ���ʶ�̶� ƫ�󣩣�ֻ�������� 
	{
		quickSort(a,begin + 1,end);//���Լ�㣬ֱ���ұߵݹ� ������һ����0,3,2�� 3,2 ����0�ұߣ�ֱ���ú���һλ��0��ʶ���3�� 
	}
	
	return;   
}

//��ӡ���� 
void prin_a(int a[]);
int main()
{
	int a[8] = {49,38,65,97,76,13,27,49};

	//�������� 
	quickSort(a,0,8 - 1);//����:����,begin,end(��ʼ����ֹ�±�) 
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
