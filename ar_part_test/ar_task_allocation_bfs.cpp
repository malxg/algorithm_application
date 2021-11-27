#include <iostream>//包含 memcpy 二维数组 复制函数 
#include <stdio.h>

#include <queue>  
/*
q.empty()               如果队列为空返回true，否则返回false
q.size()                返回队列中元素的个数
q.pop()                 删除队列首元素但不返回其值
q.front()               返回队首元素的值，但不删除该元素
q.push()                在队尾压入新元素
q.back()                返回队列尾元素的值，但不删除该元素

*/

#define task_size 4//任务 序列 大小 
using namespace std;

int task[task_size][task_size]={{0}};//先 置为 0，后面 进行 具体 初始化 
int upper = 0;                       // 同 上 
int lower = 0;                       // 同 上 
int row_min[task_size] = {0};        // 同 上 

typedef struct Node
{
	int lb;        //目标函数值 
	int visited[task_size];    //标记已分配任务 
 }Node;

queue<Node> middle; //生成 一个 头结点 序列，为了 使 每个lb 与 每个 任务状态 联系 起来 

void get_upper(int task[][task_size]);//获取最大 界限 
void get_lower(int task[][task_size]);//获取最小 界限 
void init_task();                    //初始 task[num][num],upper,lower 
void bfs(int task[][task_size]);      //bfs 搜索 求解答案 



int minn = 1001;//获取最后 的 结果 

int main()
{
	init_task();//初始 task[num][num],upper,lower 
	
	printf("下界：%d 上界%d\n\n",lower,upper);
	
	bfs(task);  //bfs 搜索 求解答案    
	
	cout << "end result:" << minn;
	return 0;
}

// 横向 搜索 
void bfs(int task[][task_size])//get lb,middle_lb
{
	//生成 一个 初始化 开始 结点（头结点）
	/*********************************************/ 
	
	Node begin;
	begin.lb = lower;
	
	//初始 头结点 
	for(int j = 0;j < task_size;j ++)
	{
		begin.visited[j] = {false};
	}
	
	/********************************************/
	
	middle.push(begin);//头结点 入队（队头） 
	
	int i = 0,flag = 1;
    
    //bfs begin
	while(middle.size() != 0)//队伍 大小 为0 时 推出，不为0 继续 循环 
	{
		
		/***************************************************************************/
		int count = 0;
		for(int m = 0;m < task_size;m ++)//工作 序列 每有 一个 分配，因为是 方阵，故 工作 序列 每有 一个 分配，就 说明 该情况 到了 那层 的dfs，即 该分配哪一个员工了 
		{
			if(middle.front().visited[m] == 1)
			{
				count ++;
			}
			    
		}
		i = count;
		if(i == 4)//是否 所有 任务都能分配完 
		{
			if(middle.front().lb < minn)//当都 分配完后 去 最小的情况 
			{
				minn = middle.front().lb;//当 所有 任务 都分配完时 即 1111 
			}
		}
		/**************************************************************************/ 
		
		int k[task_size] = {false};
		
		Node layer_node = middle.front();//每次 保存 一个出 队后 的结点，便于后面处理 
		middle.pop();                     //形成 每出队 一个 结点 就处理 一个，从队头 出队 
		 
		for(int m = 0;m < task_size;m ++)//保留 上一次 （如果有，没有就为 初始化） 的任务序列，如初始 为0000 然后1000 etc. 
		{
			k[m] = layer_node.visited[m];
		}
		
		for(int j = 0;j < task_size;j ++)
		{
			//如果 满足  lb=已分配任务员工总成本+未分配员工最小成本之和
			if( layer_node.visited[j] == false && ( task[i][j] + (layer_node.lb - row_min[i]) ) <= upper)
			{
				Node p;
				
				for(int m = 0;m < task_size;m ++)//每下一个情况都需要 继承 上一次 情况 的 任务队列 
				{
					p.visited[m] = k[m];
				}
				p.visited[j] = true;             //本次 情况 的更新点 
				
				p.lb = task[i][j] + (layer_node.lb - row_min[i]);//赋值 lb=已分配任务员工总成本+未分配员工最小成本之和 
				
				//打出 每种 情况 下的 上一种 情况，以及本次情况 
				cout << "k :";
				for(int m = 0;m < task_size;m ++)
				{
					cout <<k[m] << " ";
				}
				cout << "p :";
				for(int m = 0;m < task_size;m ++)
				{
					cout <<p.visited[m] << " ";
				}
				cout << "lb: " <<p.lb <<endl;
				
				//每一种 情况 需要 生成 一个 新 结点，然后 入队（队尾） 
				middle.push(p);
				
			}
			
		}
		
		cout << endl;
		
	}
	
	
	
	return;
}

void init_task()//初始化 
{
	int middle_arr[task_size][task_size] = //初始化 
	{
		{9,2,7,8},
		{6,4,3,7},
		{5,8,1,8},
		{7,6,9,4}
	};
	memcpy(task, middle_arr, sizeof(task));//middle_arr ->赋值给 task全局 二维数组 
	get_upper(task);//无返回值 
	get_lower(task);//无返回值 
	
	return;
}

void get_upper(int (*task)[task_size])//get upper
{
	
	int index[task_size] = {false};
	
	for(int i = 0;i < task_size;i ++)//纵向 获取  取每一纵的 最小 值 当 上界 
	{
		int column_min = 1001,flag = 0; 
		
		for(int j = 0;j < task_size;j ++)
		{
			if(index[j] == false && task[j][i] < column_min)
			{
				column_min = task[j][i];
				flag = j;
			}
		}
		
		upper = upper + column_min;//叠加 
		index[flag] = true;
	}
	return;
}

void get_lower(int (*task)[task_size])//get lower
{
	
	for(int i = 0;i < task_size;i ++)//取每一行 的最小值 然后求和 为下限 
	{
		row_min[i] = 1001; 
		
		for(int j = 0;j < task_size;j ++)
		{
			if(task[i][j] < row_min[i])
			{
				row_min[i] = task[i][j];
			}
		}
		
		printf("第%d行最小：%d\n",i + 1,row_min[i]); 
		lower = lower + row_min[i];//叠加 

	}
	
	return;
}
