/*
�Խ���СΪ1���Ҵ���ͷ��������ṹ��ʾ����
ʵ�ִ������ִ��Ļ�������StrAssign,StrCopy,StrCompare,
StrLength,Concat��SubString�ĺ��� 
*/

//��� 
typedef struct node{
	char data;
	struct node *next;
}node,*pnode;
#include <stdio.h>
#include <malloc.h>
#define N 51
//�����ַ����� ���� ������
pnode create_link(char c[]);
//�ͷ�������
void free_link(pnode a);
//��ӡ �� 
void print_linkstring(pnode a);
//��Ա����assign()���ڷ��䣬��һ�� string b����Ĵ�index�±꿪ʼ�Ĳ������ݿ�������һ�� string a�����ϲ�����ԭ���ݡ�
pnode StrAssign(pnode a,pnode b,int index);//--1
//���ĸ��� ���� b���Ƹ�a 
pnode StrCopy(pnode a,pnode b);//--2
//���ıȽϲ��� 
void StrCompare(pnode a,pnode b);//--3
//��ȡ���ĳ��� 
int StrLength(pnode a);//--4
//�������� b���ӵ�a��ĩβ 
pnode Concat(pnode a,pnode b);//--5
//���ڽ�ȡ�ַ�����ĳ���֣�������﷨Ϊsubstring(�ַ���,��ʼλ��(�±�),��ȡ����)
pnode SubString(pnode a,int begin,int length);//--6

//������ 
int main()
{
	//test_one
	pnode a,b,sub;
	char c1[N] = {'a','b','c','d','e','f','g','h','f','a','b','c','d','e','f','g','h','f'};
	char c2[N] = {'a','b','g','f','e','d','c','b','a'};
	a = create_link(c1);b = create_link(c2);//�����ַ����� ���������� 
	//��ӡ����
	print_linkstring(a);
	print_linkstring(b);
//	print_string(sub);

	//test each function
	
	//a = StrAssign(a,b,2);//���� --1
	//print_linkstring(a);
	
	
	
	//a = StrCopy(a,b);//--2
	//print_linkstring(a);
	
	
	
	//StrCompare(a,b);//--3
	
	
	
	//printf("a: %d b: %d",StrLength(a),StrLength(b));//--4
	
	
	
	//Concat(a,b);//--5
	//print_linkstring(a);
	
	
	
	sub = SubString(a,10,3);
	print_linkstring(sub);
	
	
	//�ͷ�a,b 
	free_link(a);
	free_link(b);
	
	return 0;
}

//��Ա����assign()���ڷ��䣬��һ�� string b����Ĵ� index�±� ��ʼ�Ĳ������ݿ�������һ�� string a�����ϡ�
pnode StrAssign(pnode a,pnode b,int index)//--1
{
	//a��b��Ϊ�� 
	if(a == NULL || b == NULL)
	{
		return NULL;
	}
	//�����Ǹ���ʽ���� ֱ���ͷ�a����
	free_link(a);
	
	//aΪ�պ󣬿�ʼѰ�ҿ�����,Ѱ�ҵ��󣬰Ѻ���ֵ ��ֵ�����飬Ȼ���������������¹���a���� 
	int count = 0;
	pnode p = b->next;
	while(p != NULL)
	{
		count ++;
		if(count == index + 1)//�ҵ�Ԫ��λ�� 
		{
			break;
		}
		p = p->next;
	}
	
	//�ַ�����
	char c[N] = {'\0'};
	int k = 0; 
	while(p != NULL)
	{
		c[k ++] = p->data;
		p = p->next;
	}
	
	//Ȼ������������� ����һ����aΪͷ��� ������ 
	a = create_link(c);

	return a;
}
//���ĸ��� ���� b���Ƹ�a 
pnode StrCopy(pnode a,pnode b)//--2
{
	//b��Ϊ�� 
	if(b == NULL)
	{
		return NULL;
	}
	
	//�����Ǹ���ʽ���� ֱ���ͷ�a����
	free_link(a);
	
	//�ַ�����
	char c[N] = {'\0'};
	int k = 0;pnode p = b->next;
	while(p != NULL)
	{
		c[k ++] = p->data;
		p = p->next;
	}
	//Ȼ������������� ����һ����aΪͷ��� ������ 
	a = create_link(c);
	
	return a;
}
//���ıȽϲ��� 
void StrCompare(pnode a,pnode b)//--3
{
	pnode p1 = a->next,p2 = b->next;
	//�Ƚ� 
	while(  p1 != '\0' || p2 != '\0')
	{
		//ֵ��� 
		if(p1->data == p2->data)
		{
			//���� 
			p1 = p1->next;
			p2 = p2->next;
			continue;
		}
		else;
		
		if(p1->data > p2->data)//ǰ��ֵ�� 
		{
			printf("ǰ���״β���ͬ�ַ���ǰ�ߴ�");
		}
		else if(p1->data < p2->data)//����ֵ�� 
		{
			printf("�����״β���ͬ�ַ��󣬺��ߴ�");
		}
		else;

		break;
	}
	
	if(p1 == '\0' && p2 == '\0')//ͬʱ���� 
	{
		printf("һ����");
	}
	else if(p1 != '\0' && p2 == '\0')//�����Ƚ��� 
	{
		printf("�����ַ���,ǰ�ߴ�");
	}
	else if(p1 == '\0' && p2 != '\0')//ǰ���Ƚ��� 
	{
		printf("ǰ���ַ��٣����ߴ�");
	}
	else;
	
	return;
}

//��ȡ���ĳ��� 
int StrLength(pnode a)//--4
{
	int length = 0;
	pnode p = a->next;
	while(p != NULL ){p = p->next;length ++;}
	return length;
}

//�������� b���ӵ�a��ĩβ 
pnode Concat(pnode a,pnode b)//--5
{
	
	pnode tail = a;
	//�ҵ�a�����ĩβ 
	while(tail->next != NULL)
	{
		tail = tail->next;
	}
	
	//����b�ĵ�һ��Ԫ�ؽ�� 
	tail->next = b->next;
	//��������ͷ�b��ͷ��� 
	free_link(b);
	b = NULL;
	
	return a;
}

//���ڽ�ȡ�ַ�����ĳ���֣�������﷨Ϊsubstring(�ַ���,��ʼλ��(�±�),��ȡ����)
pnode SubString(pnode a,int begin,int length)//--6
{
	if(begin < 0 || length <= 0)
	{
		printf("begin,��length �����Ϲ��ƣ�");
		return NULL;
	}
	
	pnode p = a->next;
	//������strcopy�������Ȱ�a��Ҫ��ȡ������ ����һ���ַ�����
	char c[N] = {'\0'}; 
	//���ҵ���ʼλ�� 
	int k = 0;
	while(p != NULL)
	{
		k ++;
		//�ҵ���ʼλ�� 
		if(k == begin + 1)
		{
			break;
		}
		p = p->next;
	}
	//��ʼ��ֵ ������ 
	k = 0;
	while(p != NULL)
	{
		k ++;
		c[k - 1] = p->data;
		//���Ƴ��� 
		if(k == length)
		{
			break;
		}
		p = p->next;
	}
	
	//�������鹹��һ���µ�sub���� 
	pnode sub = NULL;
	sub = create_link(c);
	
	return sub;
}
//��ӡ �� 
void print_linkstring(pnode a)
{

	if(a == NULL)
	{
		printf("a is null,error!");
		return;
	}
	else;
	

	pnode q = a->next;
	while(q != NULL)
	{
		printf("%c ",q->data);
		q = q->next;
	}
	
	printf("\n");
	return;
}

//�ͷ�������
void free_link(pnode a)
{
	//�Ѿ��ͷŹ� 
	if(a == NULL)
	{
		return;
	}
	else;
	
	pnode p = a->next;
	while(p != NULL)
	{
		//�޳�p��� 
		a->next = p->next;
		//�ͷ� 
		free(p);
		//������ʼ�� p 
		p = a->next;
	}
	//������ �ͷ�ͷ��� 
	free(a); 
	
	a = NULL;//��ͷ���ָ��,pָ��Ϊ��
	p = NULL;
	return;
} 
//�����ַ����� ���� ������
pnode create_link(char c[])
{
	//�����ַ����� ���� ������
	int size = sizeof(node);
	pnode a = (pnode)malloc(size);
	a->next = NULL;
	a->data = '\0';
	pnode head = a;//ͷ���
	//�������ݽ�� 
	int i = 0;
	pnode p = NULL;
	while(c[i] != '\0')
	{
		//��ʼp 
		p = (pnode)malloc(size);
		p->next = NULL;
		p->data = c[i];
		//����p 
		head->next = p;
		head = p;//����
		
		//�����ַ�����
		i ++; 
	}
	return a;
}
