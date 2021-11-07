/*
编写函数,用栈实现十进制转换为二进制的操作。假定堆栈的基本操作已实现，
基本操作有voidpush (elemtype e)/l入栈，elemtype pop()//出栈，
voidinitial_stack ()//初始化栈，int is_empty(stack s)//
*/

#include <stack>
#include <iostream>
using namespace std;

stack<int> s;

void conversion_binary(int e)//change decimal to binary(change e -> result)
{
	s.push(e % 2);
	int divisor = e / 2;
	
	while(divisor >= 1)// divisor == 0
	{
		s.push(divisor % 2);
		divisor = divisor / 2;
	}
	
	cout << "result is :";

	while( s.empty() == false )//s.empty() 为空 返回 1，不为空 返回 0
	{
		cout << s.top() << " ";//用 s.top()获取 栈顶 元素 
		s.pop();//s.pop() 不会 删除栈顶元素后 不会返回值,每一次删除栈顶元素 s.top()会减一 
	}
	
	cout << endl;
	
}

//main function
int main()
{
	int e;
	cin >> e;
	
	conversion_binary(e);
	
	return 0;
}
