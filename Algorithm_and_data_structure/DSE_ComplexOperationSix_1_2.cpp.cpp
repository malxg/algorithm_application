//设计 进行 复数运算的演示程序，实现以下 6 种运算 
#include <stdio.h>
#include <iostream>
using namespace std;

typedef struct complex{
	int real;//实部 
	int imaginary;//虚部 
}complex;//虚部 与 实部 初始化 

//由输入的 实部和虚部 生成一个 复数 --1
complex generate_complex();

//两个复数求和 --2
void sum_complex(complex a,complex b);

//两个复数求差 --3
void subtract_complex(complex a,complex b);

//两个复数求积 --4
void quadrature_complex(complex a,complex b);

//复数求实部 --5
void separate_real(complex a);

//复数求虚部 --6
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

//由输入的 实部和虚部 生成一个 复数 --1
complex generate_complex()
{
	complex a;
	printf("enter real-imaginary: ");
	scanf("%d%d",&a.real,&a.imaginary);
	printf("%d + %di\n",a.real,a.imaginary);
	
	return a;
}
//两个复数求和 --2
void sum_complex(complex a,complex b)
{
	printf("sum is %d + %di\n",a.real + b.real,a.imaginary + b.imaginary);
	return;
}

//两个复数求差 --3
void subtract_complex(complex a,complex b)
{
	printf("subtract is %d + %di\n",a.real - b.real,a.imaginary - b.imaginary);
	
	return;
}

//两个复数求积 --4
void quadrature_complex(complex a,complex b)
{
	printf("quadrature is %d + %di\n",a.real * b.real,a.imaginary * b.imaginary);
	
	return;
}

//复数求实部 --5
void separate_real(complex a)
{
	printf("first complex real is %d\n",a.real);
	
	return;
}

//复数求虚部 --6
void separate_imaginary(complex a)
{
	printf("first complex imaginary is %d\n",a.imaginary);
	
	return;
}
