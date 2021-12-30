/*
����һ����������ÿһ�����ֵΪx�Ľ�㣬ɾȥ����Ϊ�����������ͷſռ䡣 
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

//�ݹ�,����Ŀ��ֵΪx�Ľ�� ��ɾ�������� 
void find_dataFree(blink a,char x)
{
	
	//�ݹ���� 
	if(a == NULL)
	{
		return;
	}
	//judgement
	if(a->data == x)
	{
		//ɾ���ý����������豣���ø��ڵ� 
		FreeTree(a->lchild);//�ҵ� �����ͷ��Ըý��Ϊ����ȫ�����
		FreeTree(a->rchild);
		a->lchild = a->rchild = NULL;//��ʼ  ��ֹ���ַǷ�ָ�� �������ʱ�򱨴� 
		return;//�Ѿ��ͷ��� ���� ���õݹ����� 
	}
	
	//�ݹ� �������� 
	find_dataFree(a->lchild,x);
	find_dataFree(a->rchild,x);
	
	
	
	return;
}
//���Ժ��� 
    /*   ������abc##d##ef##g## 
    
				    	a
				    b       e
				c     d   f    g
    */
int main()
{
	blink T;
	//���������� 
	T = create_binary();
	midOrder(T);//�鿴�������
	printf("\n");
	char eat = '\0';//�Ե�������������� �س���������Ӱ��x�Ķ���(���x�����ַ��Ϳ��Բ��ü�)
	scanf("%c",&eat);
	
	
	printf("please,enter the data to delete: \n");
	char x = '\0';
	scanf("%c",&x);
	//ɾ��ָ�� ����xԪ�ؽ�� ���������� 
	find_dataFree(T,x);
	//�鿴ɾ������
	midOrder(T);
	printf("\n");
	
	//������ϣ��ͷ���������� 
	FreeTree(T);
	T = NULL;//��ʼTָ���ָ�� 
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
