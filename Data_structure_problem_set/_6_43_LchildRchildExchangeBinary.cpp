/*
�������������н������������໥������ 
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
blink create_binary();
//�ݹ� �� ����� ��
void midOrder(blink a);
//�ͷŶ����� 
void FreeTree(blink T);

//�ݹ�,������������ 
void exchage(blink a)
{
	
	//�ݹ���� 
	if(a == NULL)
	{
		return;
	}
	//�ݹ� �������� 
	exchage(a->lchild);
	exchage(a->rchild);
	//������ǰ ��������
	blink t = NULL;
	t = a->lchild; 
	a->lchild = a->rchild;
	a->rchild = t;
	
	return;
}
/*
����abc##d##ef##g## 
    
				    	a         -->������       a 
				    b       e                  e     b
				c     d   f    g             g   f  d  c
*/
//���Ժ��� 
int main()
{
	blink T;
	//���������� 
	T = create_binary();
	midOrder(T);//�鿴�������
	printf("\n");
	//������������ 
	exchage(T);
	//�鿴��������
	midOrder(T); 
	printf("\n");
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

//�ݹ� �� ����� ��
void midOrder(blink a)
{
	
	//�ݹ���� 
	if(a == NULL)
	{
		return;
	}
	//��������� 
	
	midOrder(a->lchild);
	printf("%c ",a->data);
	midOrder(a->rchild);
	
	return;
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
