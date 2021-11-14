//��� ���� �����������ʾ����ʵ������ 6 ������ 
#include <stdio.h>
#include <iostream>
using namespace std;

typedef struct complex{
	int real;//ʵ�� 
	int imaginary;//�鲿 
}complex;//�鲿 �� ʵ�� ��ʼ�� 

//������� ʵ�����鲿 ����һ�� ���� --1
complex generate_complex();

//����������� --2
void sum_complex(complex a,complex b);

//����������� --3
void subtract_complex(complex a,complex b);

//����������� --4
void quadrature_complex(complex a,complex b);

//������ʵ�� --5
void separate_real(complex a);

//�������鲿 --6
void separate_imaginary(complex a);

//test procedure
int main()
{
	complex a,b;
	a = generate_complex();
	b = generate_complex();
	
	sum_complex(a,b);        //sum a + b
	subtract_complex(a,b);   //subtract a - b
	quadrature_complex(a,b); //quadrature a * b
	separate_real(a);      //separate real part
	separate_imaginary(a); //separate imaginary part
	
	return 0;
}

//������� ʵ�����鲿 ����һ�� ���� --1
complex generate_complex()
{
	complex a;
	printf("enter real-imaginary: ");
	scanf("%d%d",&a.real,&a.imaginary);
	printf("%d + %di\n",a.real,a.imaginary);
	
	return a;
}
//����������� --2
void sum_complex(complex a,complex b)
{
	printf("sum is %d + %di\n",a.real + b.real,a.imaginary + b.imaginary);
	return;
}

//����������� --3
void subtract_complex(complex a,complex b)
{
	printf("subtract is %d + %di\n",a.real - b.real,a.imaginary - b.imaginary);
	
	return;
}

//����������� --4
void quadrature_complex(complex a,complex b)
{
	printf("quadrature is %d + %di\n",a.real * b.real,a.imaginary * b.imaginary);
	
	return;
}

//������ʵ�� --5
void separate_real(complex a)
{
	printf("first complex real is %d\n",a.real);
	
	return;
}

//�������鲿 --6
void separate_imaginary(complex a)
{
	printf("first complex imaginary is %d\n",a.imaginary);
	
	return;
}
