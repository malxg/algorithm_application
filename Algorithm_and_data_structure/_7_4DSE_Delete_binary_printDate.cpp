/*
����һ���������������Ӧ�Ķ�����������
��������ɾ������һ��ֵ�����û�����ֵ�Ľ�㡣 
*/

#include "stdio.h"//���� getchar() scanf() printf() 
#include "malloc.h"//malloc()��̬����ռ� ����

//������ ��� 
struct node{
	char data;
	struct node *lchild,*rchild;
}bnode;

typedef struct node * blink;

//�������Ӧ�Ķ���������(�ݹ�)
blink add(blink bt,char in)
{
	if(bt == NULL)
	{
		bt = (blink)malloc(sizeof(bnode));
		bt->data = in;
		bt->lchild = bt->rchild = NULL;
	}
	//���������� �Ĺ��� ����,���ڸ���� ����߷����ұ� 
	else
	{
		if(in < bt->data)
		{
			bt->lchild = add(bt->lchild,in);
		}
		else
		{
			bt->rchild = add(bt->rchild,in);
		}
	}
	return bt;
}

//���ҵ���dataֵ�Ľ�� 
blink search_node(blink root,blink *pre,int elem)
{
	blink p = root;
	*pre = root;
	//���ҵ�һ���и�ֵ�Ľ�� 
	while(p != NULL)//p���н��Ž���ѭ�� 
	{
		//ƽ������� ��ȸ�ֵС �ұȸ�ֵ�� 
		
		if(p->data < elem)//elem����,������ 
		{
			*pre = p;
			p = p->rchild;
		}
		else if(p->data > elem)//elem��С��������
		{
			*pre = p;
			p = p->lchild;
		}
		else//dataֵ�����˸�����ֵ 
		{
			break;
		}
	}
	 
	if(p == NULL)
	{
		printf("�����ڸ�ֵ�Ľ��");
		return NULL;
	}
	else
	{
		return p;
	}
}

void delete_node(blink root,int data)
{
		//���� ����
		blink q;//���� Ҫɾ�����
		blink pre;//��ȡҪɾ������ǰ���
		q = search_node(root,&pre,data);
		if(q != NULL)
		{
			
			if(q == root)//��Ҫɾ�����Ǹ��ڵ�ʱ ��ʱ����� û�� ͷ���,��ͷ��㷨 ʧЧ������ 
			{
				
				if(q->lchild == NULL && q->rchild == NULL)//˵�����ڵ�û�������� 
				{
					q = NULL;//��Ϊ�� 
					free(q);//�ͷ�
					return;
				}
				else if(q->lchild != NULL && q->rchild == NULL)//˵�������ֻ�������� 
				{
					//����Ҫɾ���ĸ� ���  
					blink s = q;
					root = q->lchild;//�޸ĸ����ָ�� ���������׽��
					s = NULL;//��Ϊ�� 
					free(s);//�ͷ�
					return;
				}
				else if(q->lchild == NULL && q->rchild != NULL)//˵������� ֻ�������� 
				{
					//����Ҫɾ���ĸ� ��� 
					blink s = q;
					root = q->rchild;//�޸ĸ����ָ�� ���������׽��
					s = NULL;//��Ϊ�� 
					free(s);//�ͷ�
					return;
				}
				else;
			}
			
			if(q->lchild == NULL && q->rchild == NULL)//˵��q�Ѿ���Ҷ�ӽ���˲����� 
			{
				q = NULL;//��Ϊ�� 
				free(q);//�ͷ�
				return;
			}
			else if(q->lchild != NULL && q->rchild == NULL)//˵��qֻ�������� 
			{
				if(pre->lchild == q)//���q����ǰָ������� 
				{
					pre->lchild = q->lchild;
				}
				else//���Һ��� 
				{
					pre->rchild = q->lchild;
				}	
					q = NULL;//��Ϊ�� 
					free(q);//�ͷ� 
					return;//���ظ����p 
			}
				
			else if(q->lchild == NULL && q->rchild != NULL)//˵��qֻ�������� 
			{
				if(pre->lchild == q)//���q����ǰָ������� 
				{
					pre->lchild = q->rchild;
				}
				else//���Һ��� 
				{
					pre->rchild = q->rchild;
				}
				
				q = NULL;//��Ϊ�� 
				free(q);//�ͷ�
				return;
			}
				//�����������е���� 
				//һ�ַ��� �ҵ� �ý�㣨�����������Ȼ��һֱ��,��Ϊ�գ�ֱ��ǰ���滻����������ǰ�����ɾ��(���� ���ǰ�� �������� �ض���һ������Ϊ��) 
				//��һ���� �ҵ� �ý�㣨����������ң�Ȼ��һֱ��,��Ϊ�գ�ֱ�Ӻ���滻��������ǰ�����ɾ��(���� ���ǰ�� �������� �ض���һ������Ϊ��)
			else
			{ 
				//�������������� ǰ�� s 
				blink s = q->rchild;
				blink s_pre = q;//����ǰ��s�� ǰ��� 
				while(s->lchild != NULL)
				{
					s_pre = s;s = s->lchild;
				}
				//�ҵ��� �滻��������ֵ 
				int t = 0;
				//�滻 
				t = q->data;
				q->data = s->data;
				s->data = t;
				//����Ҫɾ���Ľ�� �����s����s�Ѿ������ ������Ϊ�յ����
					
				if(s_pre == q)//���ǰ ����Ǹ����Ļ� 
				{
					s_pre->rchild = s->rchild;
					s = NULL;
					free(s);
				}
				
				else
				{
					s_pre->lchild = s->rchild;
					s = NULL;
					free(s);
				}
			}
		}
		
	return;
}

//������� 
void inorder(blink bt);
int main()
{
	blink root = NULL;//�� ���
	int i = 0;
	int x = 0;
	
	//���� 
	printf("��-99��������:\n");
	while(1)
	{
		scanf("%d",&x);
		if(x == -99)//������ʶ 
		{
			break;
		}
		root = add(root,x);// ��ʼ����
	}
	printf("��������(����)\n");
	inorder(root);//���� ��ӡ 
	
	//ɾ�� 
	printf("����Ҫɾ���İ����Ǹ�ֵ�Ľ�㣺");
	int del = 0;
	scanf("%d",&del);
	delete_node(root,del);
	
	printf("ɾ��ĳ�������(����)\n");
	inorder(root);//���� ��ӡ 
	printf("\n");
	
	return 0;
}
//������� 
void inorder(blink bt)
{
	/*
	����test_one
	��� Ϊ abcdefg(��Ȼ���� Ҳ���Է���,������� ����������ʵ���� ��������) 
	*/
	
	if(bt != NULL)//���� ����� 
	{
		inorder(bt->lchild); //��
		printf("%d",bt->data);//��
		inorder(bt->rchild); //�� 
	}
	
	return;
}
