/*
����׺���ʽ������������
��� ���ʽ��Ӧ�ĺ�׺����׺���ʽ
*/

#include "stdio.h"//���� getchar() scanf() printf() 
#include "malloc.h"//malloc()��̬����ռ� ����
//������ ��� 
struct node{
	char data;
	struct node *lchild,*rchild;
}bnode;

typedef struct node * blink;


//���� ���� ������ 
blink create_binary()
{
    blink bt;
    char ch;
    ch = getchar();
    if (ch == '#')
    {
        bt = NULL;
    }
    else
    {
        bt = (blink)malloc(sizeof(bnode));
        
        bt->data = ch;
        bt->lchild = NULL;
        bt->rchild = NULL;
        bt->lchild = create_binary();
        bt->rchild = create_binary();
        
    }
    
    /*   ����*-4##5##+1##2## 
    
				    	*
				    -       +
				4     5   1    2
    */
    return bt;
}

//���� ����  ���� ע��Ҫ �����ţ�ǰ׺���ʽ ��׺ ���ʽ ���� ��˼һ�� 
void inorder(blink bt)
{
	/*
	����test_one
	��� Ϊ abcdefg(��Ȼ���� Ҳ���Է���,������� ����������ʵ���� ��������) 
	*/
	
	if(bt != NULL)//���� ����� 
	{
		printf("(");
		inorder(bt->lchild); //��
		printf("%c",bt->data);//��
		inorder(bt->rchild); //�� 
		printf(")");
	}
	
	return;
}

//������� 
void preorder(blink bt)
{
	/*
	����test_one
	*/
	
	if(bt != NULL)//���� ����� 
	{
		printf("%c",bt->data);//��
		preorder(bt->lchild); //��
		preorder(bt->rchild); //��
		
	}
	
	return;
}

//������� 
void postorder(blink bt)
{
	/*
	����test_one
	*/
	
	if(bt != NULL)//���� ����� 
	{
		postorder(bt->lchild); //��
		postorder(bt->rchild); //��
		printf("%c",bt->data);//��
	}
	
	return;
}



blink FreeTree(blink T)
{
	if(T)
	{
		FreeTree(T->lchild);            //�ݹ��ͷ��������� 
		FreeTree(T->rchild);           //�ݹ��ͷ��������� 
		
		free(T);                      //�ͷŸ��ڵ� 
		T = NULL;                     //�ͷ�ָ����ڵ��ָ�� 
	}
	
	return T;           //�����ͷź�ĸ��ڵ�NULL 

}

int main()
{
	blink root = NULL;//�� ���

	//����
	root = create_binary(); 
	//���� 
	printf("\n�� �� �������  ������\n");
	preorder(root);//�������  ������ 
	printf("\n");
	inorder(root);//�������  ������ 
	printf("\n");
	postorder(root);//���� ���� ������ 
	
	printf("\n");
	free(FreeTree(root));//�ͷ� �ռ�
	 
	return 0;
}
