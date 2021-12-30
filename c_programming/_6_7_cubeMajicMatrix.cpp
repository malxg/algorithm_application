/*
求魔方阵，1~n次方的自然数构成的魔方阵（奇数矩阵）。 
*/
/*魔方阵规律 
一,第一行 最中间一列为1（是奇数矩阵一定存在中间列）
二,数字x(1< x <= n*n),如果其x - 1能被n整除,行位置向下移动则其列位置和 上一位一样不变. 
三,数字x(1< x <= n*n),如果不能被整除,其行需要往上移动一行,列需要向右移动一行
四,移动需要注意是 自上而下,自右而左的循环着移动,需要求余运算 
*/
#include <stdio.h>
#define n 5//阶数 
//构成魔方阵 
void solve_magic(int a[][n])
{
	int i,j;
	i = 0;//row
	j = n / 2;//column
	a[i][j] = 1;
	for(int k = 2;k <= n * n;k ++)
	{
		if((k - 1) % n == 0)//如果其k - 1能被n整除
		{
			i ++;//只用变化i这个行位置向下移动,其列位置和 上一位一样不变. 
		}
		else//如果不能被整除,其行需要往上移动一行,列需要向右移动一行
		{
			//移动需要注意是 自上而下,自右而左的循环着移动,需要求余运算 
			//行 
			i --;
			i = (i + n) % n;
			//列 
			j ++;
			j = j % n; 
		}
		a[i][j] = k;
	}
	return;
}
//打印二维数组 
void prin_arr(int a[][n]);
//main
int main()
{
	int a[][n] = {{0}};//初始化 
	solve_magic(a);//magic matrix
	prin_arr(a);
	return 0;
}
//打印二维数组 
void prin_arr(int a[][n])
{
	for(int i = 0;i < n;i ++)
	{
		for(int j = 0;j < n;j ++)
		{
			printf("%d\t",a[i][j]);
		}
		printf("\n");
	}
	return;
}
