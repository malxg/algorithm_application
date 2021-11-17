/*
括号匹配
包括 圆括号，方括号，花括号 3种，判断其是否匹配。 
*/

//准备栈实现 
#include <stack>//c++函数空间里面 
#include <stdio.h>//c 的 输入输出 等函数 
#include <string.h>//包含 strlen() 获取 字符串 大小 函数 
using namespace std;//告诉 编译器 要 使用 c ++ std空间，（用stack函数） 

void match(char a[])
{
	int size = strlen(a);//获取 字符数组大小 

	if(size <= 1 || size % 2 == 1)//如果 是 奇数肯定 不满足 
	{
		printf("mismatch! \n");
		return;
	}
	else;
	
	//开始 匹配 
	stack <int>s;//建立 栈 
	int i = 0;

	while(i < size)
	{
		if(*(a + i) == '{' || *(a + i) == '[' || *(a + i) == '(')
		{
			s.push(*(a + i));//进栈 
		}
		else if( (*(a + i) == '}' && s.top() == '{') || (*(a + i) == ']' && s.top() == '[') || (*(a + i) == ')' && s.top() == '(') )//不加括号也行，正常情况 && 优先级 大于 || 
		{
			s.pop();//该 括号 匹配成功 出栈 
		}
		else
		{
			break;
		}
		
		i ++;
	}
	
	if(i == size)
		printf("match successful\n");
	else
		printf("end,mismatch\n");

	return;
}

int main()
{	
	//test 
	char *a = "({[()]}}";
	match(a);//match parenthesis
	return 0;
}
