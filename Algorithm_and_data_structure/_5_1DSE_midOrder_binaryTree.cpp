/*
����һ�������� �� 
�������������
*/
#include "stdio.h"//���� getchar() scanf() printf() 
#include "malloc.h"//malloc()��̬����ռ� ����

//������ ��� 
struct node{
	char data;
	struct node *lchild,*rchild;
}bnode;

typedef struct node * blink;

//���� ������ 
blink add(blink bt,char ch)
{
	if(bt == NULL)
	{
		bt = (blink)malloc(sizeof(bnode));
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
	test_one���� dbfaceg(�� ���� ���� ����) 
	              d
	           b     f
	         a  c  e  g
	
	*/
	return bt;
} 

void inorder(blink bt)
{
	/*
	����test_one
	��� Ϊ abcdefg(��Ȼ���� Ҳ���Է���,������� ����������ʵ���� ��������) 
	*/
	
	if(bt != NULL)//���� ����� 
	{
		inorder(bt->lchild); //��
		printf("%c",bt->data);//��
		inorder(bt->rchild); //�� 
	}
	
	return;
}

int main()
{
	blink root = NULL;//�� ���
	int i = 0;
	char x = '\0';
	
	//���� 
	printf("�Կո�� + �س���������:\n");
	while(1)
	{
		x = getchar();//���� �ַ� getchar�����ӱ�׼�������ȡ��һ���ַ����൱��getc(stdin)��
		if(x == ' ')
		{
			break;
		}
		root = add(root,x);// ��ʼ����
	} 
	
	inorder(root);//������� 
	printf("\n");
	
	return 0;
}
