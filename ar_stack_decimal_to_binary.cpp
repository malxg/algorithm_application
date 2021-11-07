/*
��д����,��ջʵ��ʮ����ת��Ϊ�����ƵĲ������ٶ���ջ�Ļ���������ʵ�֣�
����������voidpush (elemtype e)/l��ջ��elemtype pop()//��ջ��
voidinitial_stack ()//��ʼ��ջ��int is_empty(stack s)//
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

	while( s.empty() == false )//s.empty() Ϊ�� ���� 1����Ϊ�� ���� 0
	{
		cout << s.top() << " ";//�� s.top()��ȡ ջ�� Ԫ�� 
		s.pop();//s.pop() ���� ɾ��ջ��Ԫ�غ� ���᷵��ֵ,ÿһ��ɾ��ջ��Ԫ�� s.top()���һ 
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
