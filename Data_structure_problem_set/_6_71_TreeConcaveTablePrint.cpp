/*
�Ժ���-�ֵ�����Ϊ���Ĵ洢�ṹ���������ʽ��ӡһ�������㷨�� 
*/

/*������ �������ֵܷ�ת�� 
					   A        -->�����ֵܱ�ʾ��   A 
				 B     C     D                    B
		       E   F   G                        E    C
		                                         F  G  D
//�۲����� ���Է��ֶ�ԭ������ �����ʽ��ӡ ���� ������������ֵܷ������, ʵ��ʵ�� �����ֵܵ�������� 
*///�簴���򹹽���ʱ ����ABE#F##CG##D### �����������ABEFCGD 
#include "stdio.h"//���� getchar() scanf() printf() 
#include "malloc.h"//malloc()��̬����ռ� ����

//������ ��� ����-�ֵܱ�ʾ �� 
struct node{
	char data;
	struct node *lchild,*rchild;//��ָ��ָ�� ���ӣ���ָ��ָ�� �ұ��ֵ� 
}bnode;
typedef struct node * blink;

//���������Ҷ�ӽ�����Ŀ 
//���� ���� ������ 
blink create_binary();
//�ͷŶ����� 
void FreeTree(blink T);

//��Ҷ�ӽ�����

//�ݹ飬������� �����ֵܽṹ 
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
