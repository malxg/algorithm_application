#include <iostream>//���� memcpy ��ά���� ���ƺ��� 
#include <stdio.h>

#include <queue>  
/*
q.empty()               �������Ϊ�շ���true�����򷵻�false
q.size()                ���ض�����Ԫ�صĸ���
q.pop()                 ɾ��������Ԫ�ص���������ֵ
q.front()               ���ض���Ԫ�ص�ֵ������ɾ����Ԫ��
q.push()                �ڶ�βѹ����Ԫ��
q.back()                ���ض���βԪ�ص�ֵ������ɾ����Ԫ��

*/

#define task_size 4//���� ���� ��С 
using namespace std;

int task[task_size][task_size]={{0}};//�� ��Ϊ 0������ ���� ���� ��ʼ�� 
int upper = 0;                       // ͬ �� 
int lower = 0;                       // ͬ �� 
int row_min[task_size] = {0};        // ͬ �� 

typedef struct Node
{
	int lb;        //Ŀ�꺯��ֵ 
	int visited[task_size];    //����ѷ������� 
 }Node;

queue<Node> middle; //���� һ�� ͷ��� ���У�Ϊ�� ʹ ÿ��lb �� ÿ�� ����״̬ ��ϵ ���� 

void get_upper(int task[][task_size]);//��ȡ��� ���� 
void get_lower(int task[][task_size]);//��ȡ��С ���� 
void init_task();                    //��ʼ task[num][num],upper,lower 
void bfs(int task[][task_size]);      //bfs ���� ���� 



int minn = 1001;//��ȡ��� �� ��� 

int main()
{
	init_task();//��ʼ task[num][num],upper,lower 
	
	printf("�½磺%d �Ͻ�%d\n\n",lower,upper);
	
	bfs(task);  //bfs ���� ����    
	
	cout << "end result:" << minn;
	return 0;
}

// ���� ���� 
void bfs(int task[][task_size])//get lb,middle_lb
{
	//���� һ�� ��ʼ�� ��ʼ ��㣨ͷ��㣩
	/*********************************************/ 
	
	Node begin;
	begin.lb = lower;
	
	//��ʼ ͷ��� 
	for(int j = 0;j < task_size;j ++)
	{
		begin.visited[j] = {false};
	}
	
	/********************************************/
	
	middle.push(begin);//ͷ��� ��ӣ���ͷ�� 
	
	int i = 0,flag = 1;
    
    //bfs begin
	while(middle.size() != 0)//���� ��С Ϊ0 ʱ �Ƴ�����Ϊ0 ���� ѭ�� 
	{
		
		/***************************************************************************/
		int count = 0;
		for(int m = 0;m < task_size;m ++)//���� ���� ÿ�� һ�� ���䣬��Ϊ�� ���󣬹� ���� ���� ÿ�� һ�� ���䣬�� ˵�� ����� ���� �ǲ� ��dfs���� �÷�����һ��Ա���� 
		{
			if(middle.front().visited[m] == 1)
			{
				count ++;
			}
			    
		}
		i = count;
		if(i == 4)//�Ƿ� ���� �����ܷ����� 
		{
			if(middle.front().lb < minn)//���� ������� ȥ ��С����� 
			{
				minn = middle.front().lb;//�� ���� ���� ��������ʱ �� 1111 
			}
		}
		/**************************************************************************/ 
		
		int k[task_size] = {false};
		
		Node layer_node = middle.front();//ÿ�� ���� һ���� �Ӻ� �Ľ�㣬���ں��洦�� 
		middle.pop();                     //�γ� ÿ���� һ�� ��� �ʹ��� һ�����Ӷ�ͷ ���� 
		 
		for(int m = 0;m < task_size;m ++)//���� ��һ�� ������У�û�о�Ϊ ��ʼ���� ���������У����ʼ Ϊ0000 Ȼ��1000 etc. 
		{
			k[m] = layer_node.visited[m];
		}
		
		for(int j = 0;j < task_size;j ++)
		{
			//��� ����  lb=�ѷ�������Ա���ܳɱ�+δ����Ա����С�ɱ�֮��
			if( layer_node.visited[j] == false && ( task[i][j] + (layer_node.lb - row_min[i]) ) <= upper)
			{
				Node p;
				
				for(int m = 0;m < task_size;m ++)//ÿ��һ���������Ҫ �̳� ��һ�� ��� �� ������� 
				{
					p.visited[m] = k[m];
				}
				p.visited[j] = true;             //���� ��� �ĸ��µ� 
				
				p.lb = task[i][j] + (layer_node.lb - row_min[i]);//��ֵ lb=�ѷ�������Ա���ܳɱ�+δ����Ա����С�ɱ�֮�� 
				
				//��� ÿ�� ��� �µ� ��һ�� ������Լ�������� 
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
				
				//ÿһ�� ��� ��Ҫ ���� һ�� �� ��㣬Ȼ�� ��ӣ���β�� 
				middle.push(p);
				
			}
			
		}
		
		cout << endl;
		
	}
	
	
	
	return;
}

void init_task()//��ʼ�� 
{
	int middle_arr[task_size][task_size] = //��ʼ�� 
	{
		{9,2,7,8},
		{6,4,3,7},
		{5,8,1,8},
		{7,6,9,4}
	};
	memcpy(task, middle_arr, sizeof(task));//middle_arr ->��ֵ�� taskȫ�� ��ά���� 
	get_upper(task);//�޷���ֵ 
	get_lower(task);//�޷���ֵ 
	
	return;
}

void get_upper(int (*task)[task_size])//get upper
{
	
	int index[task_size] = {false};
	
	for(int i = 0;i < task_size;i ++)//���� ��ȡ  ȡÿһ�ݵ� ��С ֵ �� �Ͻ� 
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
		
		upper = upper + column_min;//���� 
		index[flag] = true;
	}
	return;
}

void get_lower(int (*task)[task_size])//get lower
{
	
	for(int i = 0;i < task_size;i ++)//ȡÿһ�� ����Сֵ Ȼ����� Ϊ���� 
	{
		row_min[i] = 1001; 
		
		for(int j = 0;j < task_size;j ++)
		{
			if(task[i][j] < row_min[i])
			{
				row_min[i] = task[i][j];
			}
		}
		
		printf("��%d����С��%d\n",i + 1,row_min[i]); 
		lower = lower + row_min[i];//���� 

	}
	
	return;
}
