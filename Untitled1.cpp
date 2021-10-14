//chessboard covering divide and conquer method
#include <iostream>
#define Maxnum 10001
using namespace std;
int board[Maxnum][Maxnum];
int order = 0;//The order of filling dominoes is not the execution order of code filling

// 以左上角为坐标 零点，向下为 x的正轴，向右为 y的正轴 

int divide_conquer(int x,int y,int size)
{
	if(size < 1)
	{
		return 0;
	}
	
	int s = size / 2;
	order ++;
	
	if(x < s - 1 && y < s - 1)//top left corner
	{
		divide_conquer(x,y,s);
	}
	else
	{
		board[s - 1][s - 1] = order;
	}
	
	if(x < s - 1 && y >= s - 1)//upper right corner
	{
		divide_conquer(x,y,s);
	}
	else
	{
		board[s - 1][s - 1] = order;
	}
	
	if(x >= s - 1 && y <s - 1)//down left quarter
	{
		divide_conquer(x,y,s);
	}
	else
	{
		board[s - 1][s - 1] = order;
	}
	
	if(x >= s - 1 && y >= s - 1)//lower right corner
	{
		divide_conquer(x,y,s);
	}
	else
	{
		board[s - 1][s - 1] = order;
	}
	return 1;
}

int main()
{
	int x,y,size;
	while(1)
	{
		cin >> x >> y >> size;
		if(size <= 0 || x >= size || y>=size)//0 <= x,y < size
		{
			cout << "size is error" << endl;
			continue;
		}
		break;
	}
}
