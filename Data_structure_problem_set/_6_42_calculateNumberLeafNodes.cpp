/*
��д�ݹ��㷨�����������Ҷ�ӽ�����Ŀ�� 
*/

#include "stdio.h"//���� getchar() scanf() printf() 
#include "malloc.h"//malloc()��̬����ռ� ����
//������ ��� 
struct node{
	char data;
	struct node *lchild,*rchild;
}bnode;
typedef struct node * blink;

//���������Ҷ�ӽ�����Ŀ 
//���� ���� ������ 
blink create_binary();
//�ͷŶ����� 
void FreeTree(blink T);

//��Ҷ�ӽ�����

//�ݹ飬������� �� ͬʱͳ��Ҷ�ӽ�� 
int count = 0;//Ҷ�ӽ����� 
void preorder(blink a)
{
	
	//�ݹ���� 
	if(a == NULL)
	{
		return;
	}
	//��������� 
	printf("%c ",a->data);
	preorder(a->lchild);
	preorder(a->rchild);
	//ͳ��Ҷ�� ��� 
	if(a->lchild == NULL && a->rchild == NULL)
	{
		count ++;
	}
	
	return;
}

//���Ժ��� 
int main()
{
	blink T;
	//���������� 
	T = create_binary();
	//������� �� ͬʱ��countͳ��Ҷ�ӽ��(count�����ȫ�ֱ���)
	preorder(T);
	printf("\n");
	//��ӡcountҶ�ӽ�������
	printf("The number of leaf nodes is %d \n",count);
	
	//�ͷŶ����� 
	FreeTree(T);
	return 0;
}
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
    
    /*   ����abc##d##ef##g## 
    
				    	a
				    b       e
				c     d   f    g
    */
    return bt;
}
//�ͷŶ����� 
void FreeTree(blink T)
{
	if(T)
	{
		FreeTree(T->lchild);            //�ݹ��ͷ��������� 
		FreeTree(T->rchild);           //�ݹ��ͷ��������� 
		
		free(T);                      //�ͷŸ��ڵ� 
		T = NULL;                     //�ͷ�ָ����ڵ��ָ�� 
	}
	
	return;          

}
