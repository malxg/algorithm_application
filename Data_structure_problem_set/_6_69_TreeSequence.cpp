/*
�Զ�������洢�Ķ������У�ÿ�������������Ԫ�ؾ�Ϊ������ĸ������״��ӡ���������㷨�� 
*/
//�۲����� ���Է�����״���� ���� ��������� ����, ʵ��ʵ�� ������������� 
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

//�ݹ飬������� ��
//���� ������
char mid[101] = {'\0'};
int count = 0;//���д�С 
void midorder(blink a)
{
	
	//�ݹ���� 
	if(a == NULL)
	{
		return;
	}
	//��������� 
	midorder(a->lchild);
	mid[count ++] = a->data;
	midorder(a->rchild);
	
	return;
}

//���Ժ��� 
int main()
{
	blink T;
	//���������� 
	T = create_binary();
	//������� �� ͬʱ��countͳ��Ҷ�ӽ��(count�����ȫ�ֱ���)
	midorder(T);
	//���� ��� ��������,����ĿҪ�� 
	for(int i = count - 1;i >= 0;i --)
	{
		printf("%c ",mid[i]);
	} 
	
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
    
    /*   ����abc##d##ef##g##  �� AB#D##CE#F### 
    
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
