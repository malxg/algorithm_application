/*
��һ�������A�У�����˳������㷨����ֵΪx��Ԫ�أ�
����������λ�� 
*/

#include <stdio.h>

//˳����� 
void Sequential_search(int A[],int data)
{
	int i = 0;
	while(A[i] != 0)
	{
		if(A[i ++] == data)
		{
			printf("position: %d",i);//��ӡ �ǵڼ���Ԫ��(���������±�Ļ� ��ӡi - 1) 
			break;
		}
	}
	printf("����ʧ�ܣ�A����û�и�Ԫ��");
	return;
}

int main()
{
	int A[101] = {2,3,4,5,6,11,34,56,88,44};
	int s = 0;
	scanf("%d",&s);
	//˳�����
	Sequential_search(A,s); 
	return 0;
}
