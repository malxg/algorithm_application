/*
�ڶ���˳��洢�ṹ��ʾ�������г��ֵĵ�һ����ظ��Ӵ�����λ�á� 
*/

#include <stdio.h>
#define N 31

//ֱ���Ӵ����Ӵ��Ƚϣ��鿴�����ַ���
//���� �ַ��� aabcbc, �ȱ�����һ��Ԫ��a,�ӵڶ�����ʼ�ң��ҵ�ĳ������һ���ģ�
//��ʼ�α�k++,j++...Ȼ���¼����Ӵ�����;�Դ��ҵ���ظ��Ӵ�

//��a[]������ �Ե�ǰi�±꿪ʼ �� ��k�±꿪ʼ ��ʼ�α�ȶԣ��ҵ���ͬԪ�ص�ʱ����ã�������֮���Ԫ���Ƿ���ƥ�䣩 
int find_SonSize(int i,int k,char a[])//���� ƥ�䳤��ֵ(>= 1) 
{
	int length = 1;//��Ϊ���ҵ���һ����ͬԪ��ʱ���ã��ʳ�ʼ��Ϊ1 
	//�ܵ���,i + k��ֵ���� ��һ��ƥ�����±� 
	int cursor = i + 1;//�����α�1 
	int j = k + 1;//�α�2 
	
	while(cursor < k)//��Ҫ������ i��ʼ ��һ��ƥ��� k�ĵ�ַ��С��k
	{
		
		if(a[cursor ++] == a[j ++])
		{
			length ++;//����+1	
		}
		else//��ƥ�� 
		{
			break;//�˳� 
		}
	}
	return length;
}

int find_MaxSubstring(char a[])
{
	int position = -1;
	
	int k = 0;//�α�1
	int length = 0,local_l = 0;
	for(int i = 0;a[i] != '\0';i ++)
	{
		
		
		k = i;//Ѱ�� �ڶ��γ��ֵĵص� 
		while(a[k] != '\0')
		{
			k ++;
			//˵���ҵ�һ���뵱ǰԪ��ƥ�� ���ظ� 
			if(a[k] == a[i])
			{
				
				length = find_SonSize(i,k,a);//������i�±꿪ʼ �� ��k�±꿪ʼ �Ĵ�ƥ�䳤��
				//printf("i:%d,k:%d,length:%d\n",i,k,length);//���� 
				if(length > local_l)
				{
					local_l = length;//��������� 
					position = i;    //�������׵�ַ 
				}
			}
		}
	}
	
	printf("��ظ� �Ӵ� ����%d \n",local_l);
	return position;
}

//���� 
int main()
{
	//���� �� 
	char a[N] = {'a','a','a','b','c','a','b','c','a','b','c','b','c'};
	
	//��ӡ
	for(int i = 0;a[i] != '\0';i ++)
	{
		printf("%c ",a[i]);
	}
	printf("\n"); 
	//Ѱ��λ�� 
	int position = find_MaxSubstring(a);//���ص�һ����ظ��Ӵ���λ�� 
	
	//��ӡ 
	printf("The position of the substring is %d",position);
	printf("\n");
	
	return 0;
}

