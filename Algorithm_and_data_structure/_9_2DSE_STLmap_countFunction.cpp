/*
ʹ��STL��map����ʵ��ͳ�ƹ��ܡ�
�磺����һ�����ݣ��ľߣ��������� stationery,amount��,ͳ�Ƹ����ľߵ����� 
*/
#include <map>//���������ظ����Ԫ�� 
#include <stdio.h>
#include <string>
#include <iostream>
#define N 3
using namespace std;//map��std�ռ����� 

typedef struct node{
	char stationery[20];
	int amount;
}node,*pnode;

//ͳ�� 
void count_m(node data[])
{
	
	map<string,int>m;
	
	//����ṹ�� ������������(����)
	int j = 0;
	while(j < N)
	{
		m[data[j].stationery] = data[j].amount;//����Ԫ�ء��������ַ��true��PairҲ���Զ����һ��������ʽ�ġ� 
		j ++;//������һ�� Ԫ�� 
	};
//	int count = m.count("�ľߺ�");//����ֵk��Ӧ��Ԫ�ش��ڣ��򷵻�1������0��
	//ͳ��
	char a[3][10] = {{"�ľߺ�"},{"Ǧ��"},{"��Ƥ"}};//Ҫ���ҵ��ľ�����
	for(int i = 0;i < 3;i ++)
	{
		int sum = 0;//���ľߵ� ����
		//map�����ı��� 
		map<string,int>::reverse_iterator iter;//ָ��;
		for(iter = m.rbegin();iter != m.rend();iter ++)
		{
			if(iter->first == a[i])
			{
				cout<<iter->first<<"���� "<<iter->second<<endl;
			}
			
		}
	}
	
	return;
}

int main()
{
	//map�ǲ������ظ���ֵ������������ж��ͬ��ֵ�ģ�ֻ������׸���ֵ��Ԫ�ء� 
	node data[N] =
	{
		{"Ǧ��",9},
		{"��Ƥ",4},
		{"�ľߺ�",4},
	};
	
	count_m(data);
	
	return 0;
}
