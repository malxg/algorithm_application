/*
输入一串整数，构造其对应的二叉排序树，
并在其上删除任意一个值等于用户输入值的结点。 
*/

#include "stdio.h"//包含 getchar() scanf() printf() 
#include "malloc.h"//malloc()动态申请空间 函数

//二叉树 结点 
struct node{
	char data;
	struct node *lchild,*rchild;
}bnode;

typedef struct node * blink;

//构造其对应的二叉排序树(递归)
blink add(blink bt,char in)
{
	if(bt == NULL)
	{
		bt = (blink)malloc(sizeof(bnode));
		bt->data = in;
		bt->lchild = bt->rchild = NULL;
	}
	//二叉排序数 的构建 过程,大于根结点 在左边否则右边 
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

//查找等于data值的结点 
blink search_node(blink root,blink *pre,int elem)
{
	blink p = root;
	*pre = root;
	//先找到一个有该值的结点 
	while(p != NULL)//p得有结点才进入循环 
	{
		//平衡二叉树 左比根值小 右比根值大 
		
		if(p->data < elem)//elem若大,往右走 
		{
			*pre = p;
			p = p->rchild;
		}
		else if(p->data > elem)//elem若小，往左走
		{
			*pre = p;
			p = p->lchild;
		}
		else//data值等于了根结点的值 
		{
			break;
		}
	}
	 
	if(p == NULL)
	{
		printf("不存在该值的结点");
		return NULL;
	}
	else
	{
		return p;
	}
}

void delete_node(blink root,int data)
{
		//采用 后者
		blink q;//保存 要删除结点
		blink pre;//获取要删除结点的前结点
		q = search_node(root,&pre,data);
		if(q != NULL)
		{
			
			if(q == root)//当要删除的是根节点时 此时根结点 没有 头结点,用头结点法 失效换方法 
			{
				
				if(q->lchild == NULL && q->rchild == NULL)//说明根节点没有子树了 
				{
					q = NULL;//置为空 
					free(q);//释放
					return;
				}
				else if(q->lchild != NULL && q->rchild == NULL)//说明根结点只有左子树 
				{
					//保存要删除的根 结点  
					blink s = q;
					root = q->lchild;//修改根结点指向 左子树的首结点
					s = NULL;//置为空 
					free(s);//释放
					return;
				}
				else if(q->lchild == NULL && q->rchild != NULL)//说明根结点 只有右子树 
				{
					//保存要删除的根 结点 
					blink s = q;
					root = q->rchild;//修改根结点指向 右子树的首结点
					s = NULL;//置为空 
					free(s);//释放
					return;
				}
				else;
			}
			
			if(q->lchild == NULL && q->rchild == NULL)//说明q已经是叶子结点了不用找 
			{
				q = NULL;//置为空 
				free(q);//释放
				return;
			}
			else if(q->lchild != NULL && q->rchild == NULL)//说明q只有左子树 
			{
				if(pre->lchild == q)//如果q是其前指针的左孩子 
				{
					pre->lchild = q->lchild;
				}
				else//是右孩子 
				{
					pre->rchild = q->lchild;
				}	
					q = NULL;//置为空 
					free(q);//释放 
					return;//返回根结点p 
			}
				
			else if(q->lchild == NULL && q->rchild != NULL)//说明q只有右子树 
			{
				if(pre->lchild == q)//如果q是其前指针的左孩子 
				{
					pre->lchild = q->rchild;
				}
				else//是右孩子 
				{
					pre->rchild = q->rchild;
				}
				
				q = NULL;//置为空 
				free(q);//释放
				return;
			}
				//左右子树都有的情况 
				//一种方法 找到 该结点（根结点先向左，然后一直右,不为空）直接前驱替换，再类似于前面情况删除(中序 后继前驱 左右子树 必定有一个子树为空) 
				//另一方法 找到 该结点（根结点先向右，然后一直左,不为空）直接后继替换，再类于前面情况删除(中序 后继前驱 左右子树 必定有一个子树为空)
			else
			{ 
				//在右子树上搜索 前驱 s 
				blink s = q->rchild;
				blink s_pre = q;//保存前驱s的 前结点 
				while(s->lchild != NULL)
				{
					s_pre = s;s = s->lchild;
				}
				//找到后 替换两个结点的值 
				int t = 0;
				//替换 
				t = q->data;
				q->data = s->data;
				s->data = t;
				//现在要删除的结点 变成了s，且s已经变成了 左子树为空的情况
					
				if(s_pre == q)//如果前 结点是根结点的话 
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

//中序遍历 
void inorder(blink bt);
int main()
{
	blink root = NULL;//根 结点
	int i = 0;
	int x = 0;
	
	//建树 
	printf("以-99结束输入:\n");
	while(1)
	{
		scanf("%d",&x);
		if(x == -99)//结束标识 
		{
			break;
		}
		root = add(root,x);// 开始建树
	}
	printf("创建的树(中序)\n");
	inorder(root);//中序 打印 
	
	//删除 
	printf("输入要删除的包含那个值的结点：");
	int del = 0;
	scanf("%d",&del);
	delete_node(root,del);
	
	printf("删除某结点后的树(中序)\n");
	inorder(root);//中序 打印 
	printf("\n");
	
	return 0;
}
//中序遍历 
void inorder(blink bt)
{
	/*
	依照test_one
	结果 为 abcdefg(当然这里 也可以发现,中序遍历 二叉排序树实际是 递增序列) 
	*/
	
	if(bt != NULL)//中序 左根右 
	{
		inorder(bt->lchild); //左
		printf("%d",bt->data);//根
		inorder(bt->rchild); //右 
	}
	
	return;
}
