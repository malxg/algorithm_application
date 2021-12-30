/*
一个球从100m高度自由下落，每次反弹回一半高度，再落下，球10次过程共经过多少米，和第10次反弹多高 
*/
#include <stdio.h>
#define Begin_high 100
int main()
{
	double h = Begin_high,sum = Begin_high;//double float 最开始下落100m 
	int i = 1;
	while(i <= 9)//这里先进行9次反弹 
	{
		h = h / 2;//反弹 
		sum += 2 * h;//统计经过路程，其为 反弹高度的两倍 
		i ++;//下一次 
	}
	//经过的9次反弹，再进行一次反弹
	h = h / 2; 
	printf("球10次下落时共经过%lf米，和第10次反弹%lf",sum,h);
	
	return 0;
}
