/*
ʹ�ù�ϣ������H��k��=3k MOD 11
������������ַ�������ͻ��
�ԶԹؼ������У�22,41,53,46,30,13,01,67�������ϣ��
��ȸ�������²��ҳɹ��Ĳ��ҳ��ȣ�����ƹ����ϣ��������㷨��  
*/

#include <stdio.h>
#include <malloc.h>
#define N 11

typedef struct node{
	int data;//���� 
	struct node* next;//���ӳ�ͻ�Ľ�� 
}node,*pnode;

int a[101] = {22,41,53,46,30,13,01,67};//�ؼ�������
int size_a = 0;//���� �ؼ�������� ���� 
void prin_hash(pnode list[]);//��ӡ��ϣ��ʾ��� 
void free_hash(pnode list[]);//�ͷŹ�ϣ�� //
//build hash list
void create_hash(pnode list[])
{
 
	int i = 0,flag = 0;//i׷�ٹؼ�������,flag��ȡ����
	int size = sizeof(node);//��ȡ����С���� ����ռ� 
	//��ʼ����ϣ�� 
	for(int i = 0;i < N;i ++)//����һ����ϣ��(Ϊÿ�� �±���������һ�����) 
	{
		list[i] = (pnode)malloc(size);//ָ�룬����һ�����
		list[i]->data = 0;
		list[i]->next = NULL;
	}
	//��ʼװ�� Ԫ�أ������ӽ�㴦���ͻ 
	while(a[i] != 0)
	{
		
		flag = (3 * a[i]) % N;
		if(list[flag]->data == 0)//��û��װ�ع�Ԫ��
		{
			list[flag]->data = a[i];//ֱ�Ӹ�ֵ
		}	
		else
		{
			pnode p = (pnode)malloc(size);//ָ�룬����һ����� 
			p->next = NULL;
			p->data = a[i];//���γ�ͻ���ݣ������ڼ��������ӵĽ����
			
			pnode q = list[flag];
			//�ҵ�����������ĩβ�����ӵ�ĩβ 
			while(q->next != NULL)
			{
				q = q->next;
			}
			
			q->next = p;
		}
			 
		i ++;//���� ��һ���ؼ��� 
	}
	size_a  = i;//��ȡ �ؼ�������� ���� 
	return;
}

//���ҹ�ϣ�� ĳ��dataԪ��,���ز����������Ѵ��� 
int search_hash(pnode list[],int data)
{
	pnode q;
	int count = 0;
	int i = (3 * data) % N;//data ��N��������11�������ҵ� ������
	if(data == list[i]->data)//data����������ͷ��Ԫ�� 
	{
		count ++;
	} 
	else//˵��Ҫô������,Ҫô���� ���������� 
	{
		count = count + 1;//�������� +1 
		q = list[i];//��ֵqΪ������ͷ 
		//��ʼ ���� ���� ������ 
		while(q != NULL)
		{
			q = q->next;
			count ++;//����ƶ�һλ��˵�����Ҵ���+1 
			if(q->data == data)//�ҵ��� count�������ӣ��˳�ѭ�� 
			{
				break; 
			}
		}
		if(q == NULL)//���qΪNULL,��û���ҵ�(������break�˳�)
		{
			printf("����ʧ�ܣ�û�и�Ԫ�أ�������%d��",count);
			return 0;//Ϊ����ʧ�ܵı�ʶ 
		}
		
	}

	return count;//���� ����dataԪ�أ�����Ҫ�Ĳ��Ҵ��� 
	
} 

//ƽ�����ҳ��� 
void average_lenth(pnode list[])
{
	double sum = 0;//����ÿ��Ԫ�ز��Ҵ���֮��; 
	//�����ؼ������� 
	for(int i = 0;i < size_a;i ++)
	{ 
		sum += search_hash(list,a[i]);//search_hash���ز���a[i]���Ԫ�صĲ��Ҵ�����a[i]�ǹؼ������е�Ԫ�� 
	}
	
	printf("�ܲ��Ҵ���%.0lf,ƽ�����ҳ���%.2lf\n",sum,sum/size_a);//size_a�������в�ͬԪ�صĸ����������ʾԪ�صĸ������������ظ����ݣ�����ƽ�����ҳ��ȣ� 
	return;
}


int main()
{
	pnode list[N];//�����ϣ�� ����Ϊ11��
	//������ϣ�� 
	create_hash(list);
	//�鿴��ϣ���ϵ�ͷ��� Ԫ��
	printf("�鿴��ϣ���ϵ�ͷ���Ԫ��:");
	prin_hash(list);
	
	//�㲢��ӡ�� ƽ�����ҳ��� 
	average_lenth(list);
	
	//�ͷŹ�ϣ�� 
	free_hash(list);
	//�鿴��ϣ���ͷ�Ч��(ֻ��prin_end ��Ϊ�ͷųɹ�)
	printf("�鿴��ϣ���ͷ�Ч��(ʲô��û����Ϊ�ͷųɹ�):");
	prin_hash(list);
	
	return 0;
}

//��ӡ��ϣ��ʾ��� 
void prin_hash(pnode list[])
{
	for(int i = 0;i < N;i ++)
	{
		printf("%d ",list[i]->data);
	}
	printf("\n");
	return;
}

//�ͷŹ�ϣ�� 
void free_hash(pnode list[])
{
	pnode q,p;
	for(int i = 0;i < N;i ++)
	{
		//�ӹ�ϣ���ϵĽ�㿪ʼ�ͷ�һֱ���������������ͷŽ�����Ȼ�������һ���������ͷ� 
		q = list[i];
		while(q != NULL)
		{
			p = q->next;
			free(q);
			q = p;
		}
		
		list[i] = NULL;
	}
	
	return;
}
