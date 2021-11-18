/*
实现按层次遍历二叉树 
*/

#include "stdio.h"//包含 getchar() scanf() printf() 
#include "malloc.h"//malloc()动态申请空间 函数
#include <queue>   //包含队列函数 
using namespace std;//std空间，包含<queue>库 
//二叉树 结点 
struct node{
	char data;
	struct node *lchild,*rchild;
}bnode;

typedef struct node * blink;


//先序 建立 二叉数 
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
    
    /*   输入*-4##5##+1##2## 
    
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
		FreeTree(T->lchild);            //递归释放其左子树 
		FreeTree(T->rchild);           //递归释放其右子树 
		
		free(T);                      //释放根节点 
		T = NULL;                     //释放指向根节点的指针 
	}
	
	return T;           //返回释放后的根节点NULL 便于释放 

}


/*test 输入样式:124##3##76##8##  ( #为结束符号,不看#则是 按照 先序序列录入) 

		  1
	   2    7 
	4   3  6  8

层次遍历结果:1274368 
*/

void sequence(blink bt)
{
	queue<blink> s;
	s.push(bt);
	while(s.empty() == 0)//该函数返回0说明不为空（为空 会返回1） 
	{
		printf("%c",s.front()->data);//打印 将出队结点 的元素值 
		s.push(s.front()->lchild);   //左孩子 进队 
		s.push(s.front()->rchild);   //右孩子 进队 
		
		s.pop();//该元素 处理完毕,出队
		
	}
	
	return;
}

int main()
{
	blink root = NULL;//根 结点

	//建树
	root = create_binary(); 
	//遍历 
	printf("层次遍历  二叉树\n");
	sequence(root);//层次遍历  二叉树 
	printf("\n");
	
	//free 
	free(FreeTree(root));//释放 空间
	 
	return 0;
}

