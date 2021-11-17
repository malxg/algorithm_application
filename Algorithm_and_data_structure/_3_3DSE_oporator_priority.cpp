/*
演视用算符优先法 对算术 表达式 求值
以算符优先法 形式 从 终端 输入语法正确，不含变量的 整数 表达式
实现 对四则 混合运算 表达式 的 求值 ，运用 运算符栈，输入字符和主要操作变化过程 
*/

#include <stdio.h>
#include <string.h>//包含 strlen() 
#include <queue>
using namespace std;

//将符号 和 数据 分别放入 两个栈中 
queue<char> symbol,data;
//提取 符号 和 数据 进队 
void extrct(char a[])
{
	int size = strlen(a);
	
	if(a[0] == '-' || a[0] == '+')
	{
		data.push('0');
	}
	
	for(int i = 0;i < size;i ++)//遍历 提取 
	{
		if(a[i] == '*' || a[i] == '/' || a[i] == '+' || a[i] == '-')
		{
			symbol.push(a[i]);//符号进队 
		}
		else
		{
			data.push(a[i]);//数据 进队 
		}
	}
	
	return;
}

//算术 操作 运算符，进行 四则 运算 
int oporator(int flag)//falg 用来 标识 该 乘除 项式是否 是 正(1) 负(0) 
{

	int result = 0;
	char b[2];//提出 数据 
	
	while( symbol.empty() != 1)//empty() 堆栈为空则返回真
	{ 
		
		if(result == 0)//如果 result 为 初始状态，则 数值队列里面的首元素，赋值 起始值 
		{
			b[0] = data.front();//先来的 原式 偏前 
			data.pop();       //出队 
			
			result = int(b[0] - '0');
		}
		
		
		if(symbol.front() == '*')// 乘法 如 3*2 ，3 已经被 result 获取，只需要 获取2  
		{
			b[1] = data.front();
			data.pop();
			result *= int(b[1] - '0');
			symbol.pop();
		}
		
		else if(symbol.front() == '/')//除法 如 3/2 ，3 已经被 result 获取，只需要 获取2  
		{
			b[1] = data.front();
			data.pop();
			result /= int(b[1] - '0');
			symbol.pop();
		}
		
		else if(symbol.front() == '+')//为 +号 传flag = 1 
		{
			symbol.pop();
			if(flag == 0)//说明 式子前面有个 -号,则对 该数而言 后面 + 实际为 -，-实际为 +
			{
				if(symbol.front() == '*' || symbol.front() == '/')
					result -= oporator(1);//为 +号 传flag = 1 回溯 进行 下一个 乘除式 的运算 
				else
				{
					b[1] = data.front();
					data.pop();
					result -= int(b[1] - '0');
				}
				continue;
			}
			else;
			
			//前面是 负号，不用反转 后面符号 
			if(symbol.front() == '*' || symbol.front() == '/')
				result += oporator(1);
			else
			{
				b[1] = data.front();
				data.pop();
				result += int(b[1] - '0');
			}
		}
		
		else if(symbol.front() == '-')//为 +号 置flag = 0 
		{	
			symbol.pop();
			if(flag == 0)//说明 式子前面有个 -号,则对 该数而言 后面 + 实际为 -，-实际为 +
			{
				if(symbol.front() == '*' || symbol.front() == '/')
					result += oporator(0);//回溯 进行 下一个 乘除式 的运算  
				else
				{
					b[1] = data.front();
					data.pop();
					result += int(b[1] - '0');
				}
				continue;
			}
			else;
			
			//前面是 正号，不用反转 后面符号 
			if(symbol.front() == '*' || symbol.front() == '/')
				result -= oporator(0);
			else
			{
				b[1] = data.front();
				data.pop();
				result -= int(b[1] - '0');
			}
				
		}
		
	}

	return result;
}

int main()
{
	char a[20];
    
	//支持 0~9 范围 如 -3*1+2*4-9/3 
	printf("求输入算术表达式: ");
	scanf("%s",a);// 输入过程，默认 会 以回车键结束
	
	extrct(a);//提取 符号 和 数据 到 两个队列，如果“-”，“+”符号前于 数据 则在 该符号 前填0,结果不变 
	
	printf("result:%d",oporator(1));// 如果开始是-，则会在前面加个0，故 开始数据必为正 或者 0 
	
	return 0;
}
