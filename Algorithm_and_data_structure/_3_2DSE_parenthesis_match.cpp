/*
����ƥ��
���� Բ���ţ������ţ������� 3�֣��ж����Ƿ�ƥ�䡣 
*/

//׼��ջʵ�� 
#include <stack>//c++�����ռ����� 
#include <stdio.h>//c �� ������� �Ⱥ��� 
#include <string.h>//���� strlen() ��ȡ �ַ��� ��С ���� 
using namespace std;//���� ������ Ҫ ʹ�� c ++ std�ռ䣬����stack������ 

void match(char a[])
{
	int size = strlen(a);//��ȡ �ַ������С 

	if(size <= 1 || size % 2 == 1)//��� �� �����϶� ������ 
	{
		printf("mismatch! \n");
		return;
	}
	else;
	
	//��ʼ ƥ�� 
	stack <int>s;//���� ջ 
	int i = 0;

	while(i < size)
	{
		if(*(a + i) == '{' || *(a + i) == '[' || *(a + i) == '(')
		{
			s.push(*(a + i));//��ջ 
		}
		else if( (*(a + i) == '}' && s.top() == '{') || (*(a + i) == ']' && s.top() == '[') || (*(a + i) == ')' && s.top() == '(') )//��������Ҳ�У�������� && ���ȼ� ���� || 
		{
			s.pop();//�� ���� ƥ��ɹ� ��ջ 
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
