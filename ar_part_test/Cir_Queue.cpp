#include<stdio.h>
#include<iostream>
#include <math.h>
#define Maxsize 10
using namespace std;
//enum alphabet{'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q'};
typedef struct{
	int data[Maxsize];
	int front,rear;
}SqQueue;

void Init_CirQueue(SqQueue &L)
{
	L.rear = L.front = 0;
	for(int i = 0;i < 9;i ++)
	{	
		L.data[L.rear ++] = i;
	}

	return;
}

bool Insert_CirQueue(SqQueue &L,int e)
{
	if( (L.rear+1) % Maxsize == L.front)
	{
		printf("CirQueue is full");
		return false;
	}
	
	L.data[L.rear] = e;
	L.rear = (L.rear + 1) % Maxsize;
	return true;
	
}

bool Delete_CirQueue(SqQueue &L,int &e)
{
	if( L.rear == L.front)
	{
		printf("CirQueue is empty");
		return false;
	}
	e = L.data[L.front];
	L.front = (L.front + 1) % Maxsize;
	return true;
}



int main()
{
	SqQueue L;
	int e;
	Init_CirQueue(L);
	for(int i = L.front;i < abs((L.rear - L.front + Maxsize) % Maxsize);i ++)
		printf("%d",L.data[i]);
    cout<<endl;
    Delete_CirQueue(L,e);
    printf("Delete element is %d\n",e);
	Insert_CirQueue(L,99);
	
	for(int i = L.front;i <= ((L.rear - L.front + Maxsize) % Maxsize);i ++)
		printf("%d",L.data[i]);
	return 0;
}
