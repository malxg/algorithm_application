/*
使用哈希函数：H（k）=3k MOD 11
，并采用链地址法处理冲突。
试对关键字序列（22,41,53,46,30,13,01,67）构造哈希表，
求等概率情况下查找成功的查找长度，并设计构造哈希表的完整算法。  
*/

#include <stdio.h>
#include <malloc.h>
#define N 11

typedef struct node{
	int data;//索引 
	struct node* next;//链接冲突的结点 
}node,*pnode;

int a[101] = {22,41,53,46,30,13,01,67};//关键字序列
int size_a = 0;//保存 关键字数组的 长度 
void prin_hash(pnode list[]);//打印哈希表示结点 
void free_hash(pnode list[]);//释放哈希表 //
//build hash list
void create_hash(pnode list[])
{
 
	int i = 0,flag = 0;//i追踪关键字序列,flag获取余数
	int size = sizeof(node);//获取结点大小用于 申请空间 
	//初始哈哈希表 
	for(int i = 0;i < N;i ++)//申请一个哈希表(为每个 下标索引创造一个结点) 
	{
		list[i] = (pnode)malloc(size);//指针，构造一个结点
		list[i]->data = 0;
		list[i]->next = NULL;
	}
	//开始装入 元素，和链接结点处理冲突 
	while(a[i] != 0)
	{
		
		flag = (3 * a[i]) % N;
		if(list[flag]->data == 0)//从没有装载过元素
		{
			list[flag]->data = a[i];//直接赋值
		}	
		else
		{
			pnode p = (pnode)malloc(size);//指针，构造一个结点 
			p->next = NULL;
			p->data = a[i];//本次冲突数据，保存在即将被链接的结点里
			
			pnode q = list[flag];
			//找到该索引链最末尾，链接到末尾 
			while(q->next != NULL)
			{
				q = q->next;
			}
			
			q->next = p;
		}
			 
		i ++;//处理 下一个关键字 
	}
	size_a  = i;//获取 关键字数组的 长度 
	return;
}

//查找哈希上 某个data元素,返回查找其所花费次数 
int search_hash(pnode list[],int data)
{
	pnode q;
	int count = 0;
	int i = (3 * data) % N;//data 对N（这里是11）求余找到 索引链
	if(data == list[i]->data)//data就是索引链头的元素 
	{
		count ++;
	} 
	else//说明要么不存在,要么在其 索引链表上 
	{
		count = count + 1;//索引次数 +1 
		q = list[i];//赋值q为索引链头 
		//开始 查找 整个 索引链 
		while(q != NULL)
		{
			q = q->next;
			count ++;//向后移动一位，说明查找次数+1 
			if(q->data == data)//找到了 count结束增加，退出循环 
			{
				break; 
			}
		}
		if(q == NULL)//如果q为NULL,都没有找到(不是由break退出)
		{
			printf("查找失败，没有该元素！查找了%d次",count);
			return 0;//为查找失败的标识 
		}
		
	}

	return count;//返回 查找data元素，所需要的查找次数 
	
} 

//平均查找长度 
void average_lenth(pnode list[])
{
	double sum = 0;//保存每个元素查找次数之和; 
	//遍历关键字序列 
	for(int i = 0;i < size_a;i ++)
	{ 
		sum += search_hash(list,a[i]);//search_hash返回查找a[i]这个元素的查找次数，a[i]是关键字序列的元素 
	}
	
	printf("总查找次数%.0lf,平均查找长度%.2lf\n",sum,sum/size_a);//size_a是数组中不同元素的个数，这里表示元素的个数（不存在重复数据）（算平均查找长度） 
	return;
}


int main()
{
	pnode list[N];//创造哈希表 长度为11。
	//创建哈希表 
	create_hash(list);
	//查看哈希表上的头结点 元素
	printf("查看哈希表上的头结点元素:");
	prin_hash(list);
	
	//算并打印出 平均查找长度 
	average_lenth(list);
	
	//释放哈希表 
	free_hash(list);
	//查看哈希表释放效果(只有prin_end 即为释放成功)
	printf("查看哈希表释放效果(什么都没有则为释放成功):");
	prin_hash(list);
	
	return 0;
}

//打印哈希表示结点 
void prin_hash(pnode list[])
{
	for(int i = 0;i < N;i ++)
	{
		printf("%d ",list[i]->data);
	}
	printf("\n");
	return;
}

//释放哈希表 
void free_hash(pnode list[])
{
	pnode q,p;
	for(int i = 0;i < N;i ++)
	{
		//从哈希表上的结点开始释放一直到该索引的链都释放结束，然后进行下一个索引的释放 
		q = list[i];
		while(q != NULL)
		{
			p = q->next;
			free(q);
			q = p;
		}
		
		list[i] = NULL;
	}
	
	return;
}
