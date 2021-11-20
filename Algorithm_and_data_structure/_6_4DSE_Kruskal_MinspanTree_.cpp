/*
����Kruskal�㷨��������С������������������������̵���ͨ������
���ı���ʽ����������и�����·�����Լ���Ȩֵ�� 
*/

#include<algorithm>
#include<stdio.h>
#include <string.h>
using namespace std;

int dep[1001];//���ڻ��ݵ����� 
struct node{
	int x,y,v;
}a[1001];

int c[20] = {0},flag = 0;//���� �м���̱�����Ϊ�� ���·�� 
int depth(int x)
{
	if(dep[x] == x)
	{
		return x;
	}
	else
	{
		c[flag ++] = x;//��� �����˻��ݣ��ͱ��� �м����й����� �ͽ�����������ж��ò��� 
		return dep[x] = depth(dep[x]);
	}
}

//cmp ��дsort����������� 
int cmp(const node &a,const node &b)
{
	return a.v<b.v;       //��С���� ����  
}
/*TEST_ONE
put: 
5 6 
1 2 4 
1 5 2
2 3 3
2 5 3
2 4 6
3 4 4
			v1 --4-- v2--3--v3
			|        | |     |
			2        | |     4
			|        | |     |
			v5----3--| |--6-v4
*/
int main()
{
	int n = 0,m = 0,lowcost = 0,d1 = 0,d2 = 0,k = 0;//f1 f2Ϊ������������ 
	scanf("%d%d",&n,&m);//������,�ߵ����� 
	
	for(int i = 1;i <= n;i ++)//��ʼ�� ���ı��1~n 
	{
		dep[i] = i;
	}
	
	for(int i = 1;i <= m;i ++)//¼��� ���ߵ�������㣬�Լ���Ȩֵ��,�����б����� ����ȫ������ 
	{
		scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].v);//���ߵ�������㣬�Լ���Ȩֵ�� 
	}
	
	sort(a + 1,a + 1 + m,cmp); //��a�ṹ�� ����[a + 1,a + 1 + m] ��С���� ����
	
	for(int i = 1;i <= m;i ++)
	{	
	
		d1 = depth(a[i].x);
		d2 = depth(a[i].y);
		
		if(d1 == d2)        //��� ���㣬˵��c���� ��flag���� ʧЧ����ʹ�ã���Ϊ��� ���ݽ����ʧ�� 
		{
			flag = 0;
			memset(c,0,sizeof(c));
			continue;
		}
		
		printf("path:");
		dep[d1] = d2;      //��¼Ϊ �������� ·��f1->f2 ������f1 f2�����ڽ�������
		printf("%d \t",d2);//�յ� ����flag �������������� 
		if(flag == 1)//˵��c���� ��flag������ʹ�ã���Ϊ��� ���ݽ���ǳɹ� 
		{
			for(int j = 0;c[j] != 0;j ++)
				printf("%d->",c[j]);
		}
		else
			printf("%d->",d1);
		
		
		flag = 0;    //��ʼ flag ·����ʶ  
		memset(c,0,sizeof(c));//����ʹ����ɣ���ʼ c���� ׼����һ�α�������� 
		
		lowcost += a[i].v;//�洢 ��С��������Ȩֵ 
		
		k ++; //������ �ɹ������� + 1 
		if(k == n-1)//��С���ɶ����� �߸��� ���� �����-1 
		{
			break;
		}
	}
	
	printf("��С������Ȩֵ: %d\n",lowcost);
}
