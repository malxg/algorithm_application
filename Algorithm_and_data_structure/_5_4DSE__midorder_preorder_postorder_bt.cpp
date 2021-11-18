/*
�����Ϸ��ı��ʽ�ַ���ֻ����Ԫ�������ķǿձ��ʽ��
�ö����������㷨�����׺���ʽ��Ӧ�ĺ�׺��ǰ׺���ʽ
*/

#include "stdio.h"//���� getchar() scanf() printf() 
#include "malloc.h"//malloc()��̬����ռ� ����
//������ ��� 
struct node{
	char data;
	struct node *lchild,*rchild;
}bnode;

typedef struct node * blink;

//��׺ ���� ������ (���� ���� ���� ��ʶ�� ���ʽ ���Ȳ㼶,�����Ҳ��Ҫ������)
//�ݹ�ʵ��
static int i = 0;//��� ������ ��һ�� Ҫ����� Ԫ�أ���̬���� ��̳���һ�ε��õ�ֵ 
blink create_binary(char s[])
{
	
    char ch = s[i];//���� ���� ���� Ҫ���� ��Ԫ�� 
    
    //������� 
    blink bt;
	bt = (blink)malloc(sizeof(bnode));
    bt->data = '\0';
    bt->lchild = NULL;
    bt->rchild = NULL;
    
    //ch���������������� ���� 1�е�������(������),�������� 2�е����ݣ��������� ����+1
    i ++; 
	
	//��ʼ �������� ch�����Ԫ�� 
    if(ch == '(')//���ch����� Ԫ�� ��'(' -----------1
    {	
    	bt->lchild = create_binary(s);//���� ��������������----�� 
    	
		bt->data = s[i];//���� ������ Ϊ�ֲ��� �� ----�� 
    	i ++;//����ƶ� ������һ�� Ԫ�� 
    	
    	bt->rchild = create_binary(s);//���� ��������������---�� 
		
		i ++;//������� ���� ������������(������) 
	}
	
	else//���ch����� Ԫ�� ��һ�� ֵ��ֱ�Ӹ�ֵ---------2 
	{
		bt->data = ch;
	} 
    
    /*   ���� ((4-5)*(1+2)) 
                        +
 					-      +
 				4      5  1   2
 	
				    	
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
	char s[50] = {'\0'};
	scanf("%s",s);//���� ��׺ ���ʽ 
	//����
	root = create_binary(s); 
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
