/*
�����û������ż��(������0��ʾ����)����������ͼ���ڽӱ�
�������һ�������������к����������򣬲��ж��Ƿ��л�· 
*/

#include <stdio.h>
#include <malloc.h>
#include <stack>
#define size 6
using namespace std;
typedef struct node{
	int aimdex;//��ͷָ����ı�� 
	struct node *next;//ָ����һ����� 
}node;

typedef struct listnode{
	int index;   //����� 
	int indegree;//���
	int outdegree;//���� 
	node *first; //��һ�� �߽�� (�� ͷ�巨 ����)
}listnode;

//���� �ڽӱ�,ͬʱͳ�� ÿ������ ���� 
int len = sizeof(node);//���� ���� ���ռ� 
void create_list(listnode a[])
{
	listnode *p = a;//���� 
	node *q;//ָ��߽�� 
	//��ʼ N�� ���� 
	for(int i = 0;i < size;i ++)
	{
		p[i].index = i + 1;//1~n���
		p[i].indegree = 0;
		p[i].outdegree = 0;
		p[i].first = NULL;
	}
	
	//���� �߽�� 
	printf("\nplease input the edge node(��ͷβ��&ͷ��(���)(0,0)Ϊ����):\n");
	int k = 0,m = 0;
	scanf("%d%d",&k,&m);//kΪ ����ߣ���ͷβ����mΪ ͷ������� 
	
	while(k != 0 && m != 0)//����(0,0)����
	{
		q = (node*)malloc(len);
		
		q->aimdex = m;//��ʶ��ָ ����� 
		//ͷ�巨 ˼�� 
		q->next = p[k - 1].first;//���ν��next ָ���ϴβ�����Ǹ���㣨û�о�ָ�� NULL�� 
		p[k - 1].first = q;//ͷ�巨 �µ� �߽�� ���뵥����ı�ͷ 
		
		p[k - 1].outdegree ++;//���� ����
		p[m - 1].indegree ++;//��� ����
		
		scanf("%d%d",&k,&m);
	}
	return;
}

//��������
int top[size] = {0};//���� ���������� ���������� 
int topsort(listnode a[])
{
	stack<int>s1;
	node *q;
	for(int i = 0;i < size;i ++)
	{
		if(a[i].indegree == 0)//�������㣬�������Ϊ0�Ķ���ջ 
		{
			s1.push(a[i].index);//���� �±��ջ 
		}
	}
	int count = 0;//����� �����������countС�ڽ������˵���л� 
	
	int j;//�����ʱ Ҫ����ı����±�
	while(s1.empty() != 1)//ջ��Ϊ�� 
	{
		j = s1.top();//ȡջ�� Ԫ�ص��±�(���δ�������±�) 
		s1.pop();//��ջ 
		
		//printf("%5d",a[j - 1].index);//��ӡ �ý���±꣬��ΪΪ��������һ���� 
		top[count] = a[j - 1].index;//���� �ý���±꣬��ΪΪ��������һ���� 
		count ++;//�ý�������������ɹ������� + 1 
		
		//������±�Ϊ ����±�-1(�����0��ʼ��ţ�����1��ʼ���) 
		q = a[j - 1].first;//����Ϊ ��ȡ�±�� �����㣨���������� ��� ���-1��
		
		int k = 0;//k����Ҫ������� �±� 
		while(q != NULL)//����ö��������������Ľ�� 
		{
			k = q->aimdex;//kҪ������� �±� 
			
			//������±�Ϊ ����±�-1(�����0��ʼ��ţ�����1��ʼ���) 
			a[k - 1].indegree --;  //�ý����ȼ�1(��Ϊ��֮������j�Ѿ�����) 
			if(a[k - 1].indegree == 0)//��� ��һ���Ϊ0˵�� �Ǵ�������� �����±���ջ 
			{
				s1.push(k);//��ջ ���±� 
			}
			q = q->next;//���Ƿ��� ��j �����Ľ�㣬q��������j�ı߽�� 
		} 
	}
	
	if(count < size)//����н��û�о��� ��ջ��ջ��û�д���count != size�� 
	{
		printf("the graph has recycle");
		return -1;//˵�� ��������ʧ�� 
	}
	
	return 1; //˵�� ��������ɹ� 
}

/*
test_one(���Ի������) 
�����  �߽��         indegree(���)    outdegree(����)
1        -->4-->3-->2    1                 3
2        -->5            2                 1
3        -->5-->2        1                 2
4        -->5            2                 1
5        -->1            4                 1
6        -->5-->4        0                 2

test_one(�����޻������) 
�����  �߽��         indegree(���)    outdegree(����)
1        -->2            0                 1
2        -->3            1                 1
3        -->4            1                 1
4        -->5            1                 1
5        -->6            1                 1
6                        1                 0
*/
//��ӡ�������򣨻����������� ���� 
void print_array(int a[],int flag)
{
	if(flag == 0)//��ӡ���� ���� 
		for(int i = 0;i < size;i ++)
		{
			printf("%d ",a[i]);
		}
	else//������������������ת����� 
		for(int i = size - 1;i >= 0;i --)
		{
			printf("%d ",a[i]);
		}
	printf("\n");
}
int main()
{
	listnode a[size];
	//���� �ڽӱ�,ͬʱͳ�� ÿ������ ���� 
	create_list(a);
	
	//��������
	int flag = topsort(a);
	if(flag == 1)//���û�л���top����ɹ� 
	{
		printf("����������:");
		print_array(top,0);
		
		//����������
		printf("������������:");
		print_array(top,1);//������������������ת����� 
	}
	else;
	
	
	return 0;
}
