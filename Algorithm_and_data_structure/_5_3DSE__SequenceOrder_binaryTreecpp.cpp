/*
ʵ�ְ���α��������� 
*/

#include "stdio.h"//���� getchar() scanf() printf() 
#include "malloc.h"//malloc()��̬����ռ� ����
#include <queue>   //�������к��� 
using namespace std;//std�ռ䣬����<queue>�� 
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

blink FreeTree(blink T)
{
	if(T)
	{
		FreeTree(T->lchild);            //�ݹ��ͷ��������� 
		FreeTree(T->rchild);           //�ݹ��ͷ��������� 
		
		free(T);                      //�ͷŸ��ڵ� 
		T = NULL;                     //�ͷ�ָ����ڵ��ָ�� 
	}
	
	return T;           //�����ͷź�ĸ��ڵ�NULL �����ͷ� 

}


/*test ������ʽ:124##3##76##8##  ( #Ϊ��������,����#���� ���� ��������¼��) 

		  1
	   2    7 
	4   3  6  8

��α������:1274368 
*/

void sequence(blink bt)
{
	queue<blink> s;
	s.push(bt);
	while(s.empty() == 0)//�ú�������0˵����Ϊ�գ�Ϊ�� �᷵��1�� 
	{
		printf("%c",s.front()->data);//��ӡ �����ӽ�� ��Ԫ��ֵ 
		s.push(s.front()->lchild);   //���� ���� 
		s.push(s.front()->rchild);   //�Һ��� ���� 
		
		s.pop();//��Ԫ�� �������,����
		
	}
	
	return;
}

int main()
{
	blink root = NULL;//�� ���

	//����
	root = create_binary(); 
	//���� 
	printf("��α���  ������\n");
	sequence(root);//��α���  ������ 
	printf("\n");
	
	//free 
	free(FreeTree(root));//�ͷ� �ռ�
	 
	return 0;
}

