/*
�Զ��庯�� ʵ�� ��ջ ��ջ,
���� һ�� ���У��� -1 Ϊ������־����
�� �����������෴�Ĵ��������
��ջ��ʵ�� ��һ���� 
*/
#include <iostream>
#include <stdio.h>
//#include <stack> //��ȻҲ��ֱ�ӵ��� stack�� 
#define MaxsizeStack 30
using namespace std;
typedef struct stack{
	
	double data[MaxsizeStack];//��Ϊ ջ�� ���� ���� �� 
	int top;                  //��Ϊ ջ�� "ָ��"                   
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
	
	do//�� -1 Ϊ������־ 
	{
	    
		printf("Please,enter the element: ");
		scanf("%lf",&data);//���� ��ջ ���� 
	    
		if(data != -1)
			push(&test,data);

	}while(data != -1);
	
	//��ջ �� ��ӡ ��ջ ���� 
	while(test.top != -1)//���� Ԫ����ջ 
	{
		pop(&test);
	}
	
	return 0;
}

