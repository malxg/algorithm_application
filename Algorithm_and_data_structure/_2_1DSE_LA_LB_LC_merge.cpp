/*
--���� �ǵݼ� ���� ���Ա� LA,LB��
--��LA,LB�鲢Ϊ �±�LC��
--��LC��ͬ�� ��ֵ�ݼ� ����
--���LA,LB,LC 
*/
//#include <iostream>
//using namespace std;

#include <stdio.h>
#include <algorithm>//include sort() ������ ������c ++�� 
using namespace std;//c ++�� ���߱������ʹ��std�����ռ� (ʹ��c ++ ����ʱ�������)

#define size 10
//���� ���Ա� ���� �� ���� ���� �������ڰ� �ǵݼ����� ��Ȼ��������� 

bool cmp(int a,int b)
{
	return a <= b;// ǰ�� <= ����  �ǵݼ� ����
}

void print_array(int a[],int range)
{
	int i = 0;
	while(i < range)
	{
		printf("%d ",a[i ++]);
	}
	printf("\n");
} 

//test procedure
int main()
{
	int LA[size] = {4,6,12,4,
					6,7,9,11,
					13,2};
	int LB[size] = {2,4,0,3,
					6,7,5,11,
					15,2};
	int LC[size + size] = {0};//init LC
	
	
	sort(LA,LA + size,cmp);//�ǵݼ� ����LA 
	printf("LA: ");
	print_array(LA,size);  //��� LA 
	
	sort(LB,LB + size,cmp);//�ǵݼ� ����LB
	printf("LB: ");
	print_array(LB,size);  //��� LB 
	
	//�Ⱥϲ� LA,LB -> LC
	int i = 0; 
    while(i < size)
    {
    	LC[i] = LA[i];
    	LC[i + size] = LB[i ++];
	}
	
	//���� lC 
    sort(LC,LC + 2*size,cmp);//�ǵݼ� ����LC 
	printf("LC: ");
	print_array(LC,2*size); //��� LC 
	
	return 0;
}
