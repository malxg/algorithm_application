/*
给出年、月、日，计算该日是该年的第几天。 
*/

#include <stdio.h>
#define n 8
//大多数情况下列出 每个月的默认天数（如果是闰年后面再修改）
//默认 1、3、5、7、8、10、12每月31天，二月闰年29天，平年28天，其余月份30天 
int month[13] = {0,31,28,31,30,
				 31,30,31,31,
				 30,31,30,31 
								};
//判断年份是否为闰年 
int judgement_leap(int i)
{
	if(i % 4 == 0 && i % 100 != 0 || i % 100 == 0 && i % 400 == 0)
	{
		return 1;
	}
	return 0;
}
//获取其为该年的第几天 
void get_date(int a[])
{
	int date = 0,year = 0,mon = 0,day = 0;
	year = a[0] * 1000 + a[1] * 100 + a[2] * 10 + a[3];//年 
	mon = a[4] * 10 + a[5];//月 
	day = a[6] * 10 + a[7];//日 
	
	if(mon > 2)//如果月份大于2月，说明需要判断该年是否为闰年（闰年和平年 2月份天数不一样）
	{
		if(judgement_leap(year) == 1)//是闰年
		{
			month[2] = 29;//2月份天数变为29天.(数组第一个下标没有用，方便月份与下标统一) 
		}
		else;//不是闰年 是平年，就保存默认28天 
	} 
	
	
	//该年第几天(数组从1开始,停止再mon前)
	//加前几个月天数 
	for(int i = 1;i <= mon - 1;i ++ )
	{
		date = date + month[i];
	}
	//加当前月份天数
	date = date + day; 
	//打印 
	printf("是%d年的第%d天",year,date);
	return;
}
 
int main()
{
	//数组构成 年 4位，月份2位，日 2位
	int a[n] = {0};
	for(int i = 0;i < n;i ++)
	{
		scanf("%d",a + i);
	}
	
	get_date(a);//获取第几天,并打印结果 
		
	return 0;
}
