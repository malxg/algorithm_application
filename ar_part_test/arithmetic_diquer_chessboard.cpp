
//chessboard covering divide and conquer method
#include <iostream>
#define Maxnum 1001
using namespace std;
int chessboard[Maxnum][Maxnum];//chessboard max num
int Order = 0;//The order of filling dominoes is not the execution order of code filling
// 以左上角为坐标 零点，向下为 x的正轴，向右为 y的正轴 
void divide_conquer(int ox,int oy,int x,int y,int size)
{
	if(size <= 1)
	{
		return;
	}
	
	size = size / 2;
    Order ++;
	int order = Order;
	if(x <= ox + size - 1 && y <= oy + size - 1)//top left corner
	{
		divide_conquer(ox,oy,x,y,size);
	}
	else
	{
		chessboard[ox + size - 1][oy + size - 1] = order;
		divide_conquer(ox,oy,ox + size - 1,oy + size - 1,size);
	}
	
	if(x <= ox + size - 1 && y > oy + size - 1)//upper right corner
	{
		divide_conquer(ox,oy + size,x,y,size);
	}
	else
	{
		chessboard[ox + size - 1][oy + size] = order;
		divide_conquer(ox,oy + size,ox + size - 1,oy + size,size);
	}
	
	if(x > ox + size - 1 && y <= oy + size - 1)//down left quarter
	{
		divide_conquer(ox + size,oy,x,y,size);
	}
	else
	{
		chessboard[ox + size][oy + size - 1] = order;
		divide_conquer(ox + size,oy,ox + size,oy + size - 1,size);
	}
	
	if(x > ox + size - 1 && y > oy + size - 1)//lower right corner
	{
		divide_conquer(ox + size,oy + size,x,y,size);
	}
	else
	{
		chessboard[ox + size][oy + size] = order;
		divide_conquer(ox + size,oy + size,ox + size,oy + size,size);
	}
	
}

int main()
{
	int x,y,size;
	
	while(1)
	{
		cout << "Coordinates of special points,then (X,Y),size :";
		cin >> x >> y >> size;
		
		if(size <= 0 || x >= size || y >= size)//0 <= x,y < size !!size 必须是 4的k倍数 (1 < k < +∞) 
		{
			cout << "size or x,y is error" << endl;
			continue;
		}
		break;
	}
	
	divide_conquer(0,0,x,y,size);
	
	for(int i = 0;i < size;i ++)//print chessboard's result
	{
		for(int j = 0;j < size;j ++)
		{
			cout << chessboard[i][j] << "\t";
		}
		cout << endl;
	}
	return 0;	
}

