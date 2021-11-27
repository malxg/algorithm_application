#include <iostream>
#include <cmath>
using namespace std;


typedef struct point{
	double x;
	double y;
}point;

double end_min = 100001;
//strength_closest_pair
double strength_closest_pair(point a[],int n)
{
	if (n == 0)
	{
		cout << "error,n=0" << endl;
		return -1;
	}
	
	for (int i = 0;i < n - 1 ;i ++)
	{
		double local_min = 100001;
		int index = 0;
		for (int j = i+1;j < n;j ++)
		{
			double d = sqrt( pow(a[i].x - a[j].x,2) + pow(a[i].y - a[j].y,2) );
			
			if (local_min > d)
			{
				local_min = d;
				index = j;
			}
			
		}
		
		if( end_min > local_min)
		{
			end_min = local_min;
		}
		
		printf("%d 点 %d 点 最近,是 %.3lf 目前最近点距%.3lf \n",i,index,local_min,end_min);
	}
	
	return end_min;
}

int main()
{
	point a[10] = {{1,3},{7,3},{5,4},{6,2},{7,8},{3,9},{10,4},{11,2},{9,8},{7,9}};
	end_min = strength_closest_pair(a,10);
	return 0;
}
