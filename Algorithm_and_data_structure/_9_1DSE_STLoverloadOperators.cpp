/*
使用STL的set容器，重载二元操作符加减乘来定义集合的
并差交运算。 
*/

#include <set>
#include <string>
#include <iostream>
using namespace std;

int num;
class Set
{
	
private:
    int *pa;   //指向数组的指针
	int a;	 //集合成员个数
	
public:
	Set operator +(Set A);
	Set operator -(Set A);
	Set operator *(Set A);
};

Set Set::operator +(Set A)
{

	/*
	Set Tpa;   //建立新的Set对象将集合原本的元素复制进去，并清除指针，以增加数组长度
	for(int i=1;i<=a;i++)   //i=1（j=1）时进入循环，使i=0时可以添加第一个元素
		Tpa+=pa[i];
	a++;
	if(pa!=NULL) delete[]pa;
	pa=new int[a+1];   //建立新的数组，长度加一
	for(int j=1;j<a;j++)
		pa[j]=Tpa.pa[j];
	pa[a]=b;
	*/
	return *this;
}

Set Set::operator -(Set A)
{
	/*
	if(!isin(b))   {cout<<"该元素不在集合内"; return *this;}
	a--;
	for(int i=num;i<=a;i++){
		pa[i]=pa[i+1];   //b后的元素都向前移动一位
	}*/
	return *this;
}

Set Set::operator *(Set A)
{
	/*
	if(!isin(b))   {cout<<"该元素不在集合内"; return *this;}
	a--;
	for(int i=num;i<=a;i++){
		pa[i]=pa[i+1];   //b后的元素都向前移动一位
	}*/
	return *this;
}

int main()
{
	set<int> s1,s2;//如果需键值对 则需要pair，其第一个参数为键，第二个为值的类型 
	//s1 TEST
	s1.insert(1);
	s1.insert(5);
	s1.insert(7);
	s1.insert(9);
	s1.insert(10);
	//s2 TEST
	s2.insert(1);
	s2.insert(11);
	s2.insert(9);
	s2.insert(2);
	s2.insert(3);

	return 0;
}
