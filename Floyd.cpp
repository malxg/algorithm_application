#include <stdio.h>
#include <stdlib.h>

#include <iostream>
using namespace std;

int main()
{
	int n = 3;
	int A[20][20],path[20][20];
	for (int k = 0; k < n;k ++)
	{
		for(int i = 0;i < n;i ++)
		{
			for(int j = 0;j < n;j ++)
			{
				if(A[i][j]>A[i][k]+A[k][j])
				{
					A[i][j] = A[i][k] + A[k][j];
					path[i][j] = k;
				}
			}
		}
	}
	return 0;
}
