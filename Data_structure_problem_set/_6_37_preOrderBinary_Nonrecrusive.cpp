/*
��ջ�Ļ�������ʵ����������ķǵݹ���ʽ���㷨�� 
*/

#include <stdio.h>
#include <malloc.h>//����������������ռ� 
#include <stack>
using namespace std;//std�ռ� 

typedef struct node{
	char data;
	struct node* lchild;
	struct node* rchild;
}node,*pnode;
//���� ���� ������ 
pnode add(pnode bt,char ch);
//���� �ǵݹ�,ջʵ�� 
void preOrder(pnode root)//����� 
{
	if(root == NULL)
	{
		printf("root is null!");
		return;
	}
	
	//��ʼ �ṹ�� ָ��ջ 
	stack<pnode> s;
	s.push(root);//���ڵ� �Ľṹ��ָ����ջ 
	
	//��ʼ���� root 
	pnode p;//�α� 
	while(!s.empty())//�ȼ�s.empty() == 0,s.empty()ջΪ�շ���1����Ϊ�շ���0 
	{
		p = s.top();//p��ʼ��Ϊջ�� Ԫ��(��һ��Ϊ�����)
		//��������˳���ӡ��ֵ
		printf("%c ",p->data);//��ӡ���ڵ� 
		s.pop();//��ǰ�� ��ջ
		//����ջ���ȴ������ջ�ģ����Һ�������������ջ����֮��ʵ���ȴ������ӣ� 
		if(p->rchild != NULL)//�����Һ��� 
		{
			s.push(p->rchild);//���У����Һ�����ջ 
		}
		if(p->lchild != NULL)//�������� 
		{
			s.push(p->lchild);//���У���������ջ 
		}
	}
	printf("\n");//Enter
	return;
}

int main()
{
	pnode root = NULL;
	char ch;
	//���� ���� ������ 
	//����
	printf("�Կո�� + �س���������:\n");
	while(1)
	{
		ch = getchar();//���� �ַ� getchar�����ӱ�׼�������ȡ��һ���ַ����൱��getc(stdin)��
		if(ch == ' ')
		{
			break;
		}
		root = add(root,ch);// ��ʼ����
	}
	
	//���� �ǵݹ�,ջʵ�� 
	preOrder(root);//���� ����� �ṹ��ָ�� 
	
	return 0;
}

//�������� ��ʽ ���� ������ 
int size = sizeof(node);
pnode add(pnode bt,char ch)
{
	if(bt == NULL)
	{
		bt = (pnode)malloc(size);
		bt->data = ch;
		bt->lchild = bt->rchild = NULL;
	}
	//������ ���������� �Ĺ��� ����,���ڸ���� ����߷����ұ� 
	else
	{
		if(ch < bt->data)
		{
			bt->lchild = add(bt->lchild,ch);
		}
		else
		{
			bt->rchild = add(bt->rchild,ch);
		}
	}
	/*
	test_one���� dbfaceg(���ƶ��������� �Ĳ��� ���� ����)
	              d
	           b     f
	         a  c  e  g
	*/
	return bt;
} 
