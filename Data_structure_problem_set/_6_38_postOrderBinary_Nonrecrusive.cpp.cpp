/*
��������ķǵݹ���ʽ���㷨�� 
*/

#include <stdio.h>
#include <malloc.h>//����������������ռ� 
#include <stack>
using namespace std;//std�ռ� 

typedef struct node{
	char data;
	int flag;//����Ƿ����ջ ��ʶ ����ʼΪ0 
	struct node* lchild;
	struct node* rchild;
}node,*pnode;
//���� ���� ������ 
pnode add(pnode bt,char ch);
//���� �ǵݹ�,ջʵ�� 
void postOrder(pnode root)//����� 
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
	pnode p = s.top();//�α�p��ʼ��Ϊջ�� Ԫ��(��һ��Ϊ�����)
	while(!s.empty())//�ȼ�s.empty() == 0,s.empty()ջΪ�շ���1����Ϊ�շ���0 
	{
		//���պ���˳���ӡ��ֵ
		//����ջ���ȴ������ջ�ģ����Һ�������������ջ����֮��ʵ���ȴ������ӣ� 
		if(p->rchild != NULL && p->rchild->flag == 0)//�����Һ��� 
		{
			s.push(p->rchild);//���� �� ֮ǰû�����ջ�����Һ�����ջ 
			p->rchild->flag = 1;//��ջ��ʶ
		}
		if(p->lchild != NULL && p->lchild->flag == 0 )//�������� 
		{
			s.push(p->lchild);//���� �� ֮ǰû�����ջ����������ջ 
			p->lchild->flag = 1;//��ջ��ʶ
		}
		
		p = s.top();//p��ʼ��Ϊջ�� Ԫ��
		//���û�к��ӣ����ߺ��Ӷ��Ѿ����������ջ �� ��ӡ 
		if( (p->lchild == NULL && p->rchild == NULL) || (p->lchild->flag == 1 && p->rchild->flag == 1) )
		{
			printf("%c ",p->data);//��ӡ��ʱջ�����
			s.pop();//����ջ 
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
	postOrder(root);//���� ����� �ṹ��ָ�� 
	
	return 0;
}

//�������� ��ʽ ���� ������ 
int size = sizeof(node);
pnode add(pnode bt,char ch)
{
	if(bt == NULL)
	{
		bt = (pnode)malloc(size);
		bt->data = ch;//��ֵ���� 
		bt->flag = 0;//��ʼ��ʶ 
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
