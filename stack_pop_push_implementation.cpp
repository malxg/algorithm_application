/*
自定义函数 实现 出栈 入栈,
输入 一段 序列（以 -1 为结束标志），
并 按照与输入相反的次序输出，
用栈来实现 这一功能 
*/
#include <iostream>
#include <stdio.h>
//#include <stack> //当然也可直接调用 stack库 
#define MaxsizeStack 30
using namespace std;
typedef struct stack{
	
	double data[MaxsizeStack];//作为 栈的 数据 保存 区 
	int top;                  //作为 栈顶 "指针"                   
}stack;

void push(stack *q,double data)
{
	if(q->top >= MaxsizeStack)
	{
		cout << "stack is full !" << endl;
		return;
	}
	
	q->data[++q->top] = data;//equivalent test->top ++
	
	return;
}

void pop(stack *q)
{
	if(q->top == -1)
	{
		return;
	}
	double data = q->data[q->top --];
	cout << "the element is out of the stack :" << data << endl;
	return;
}

int main()
{
	stack test;
	double data = 0;
	test.top = -1;
	
	do//以 -1 为结束标志 
	{
	    
		printf("Please,enter the element: ");
		scanf("%lf",&data);//输入 入栈 数据 
	    
		if(data != -1)
			push(&test,data);

	}while(data != -1);
	
	//出栈 并 打印 出栈 数据 
	while(test.top != -1)//当有 元素入栈 
	{
		pop(&test);
	}
	
	return 0;
}

