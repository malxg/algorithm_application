/*
ʹ��STL��set���������ض�Ԫ�������Ӽ��������弯�ϵ�
������㡣 
*/

#include <set>
#include <string>
#include <iostream>
using namespace std;

int num;
class Set
{
	
private:
    int *pa;   //ָ�������ָ��
	int a;	 //���ϳ�Ա����
	
public:
	Set operator +(Set A);
	Set operator -(Set A);
	Set operator *(Set A);
};

Set Set::operator +(Set A)
{

	/*
	Set Tpa;   //�����µ�Set���󽫼���ԭ����Ԫ�ظ��ƽ�ȥ�������ָ�룬���������鳤��
	for(int i=1;i<=a;i++)   //i=1��j=1��ʱ����ѭ����ʹi=0ʱ������ӵ�һ��Ԫ��
		Tpa+=pa[i];
	a++;
	if(pa!=NULL) delete[]pa;
	pa=new int[a+1];   //�����µ����飬���ȼ�һ
	for(int j=1;j<a;j++)
		pa[j]=Tpa.pa[j];
	pa[a]=b;
	*/
	return *this;
}

Set Set::operator -(Set A)
{
	/*
	if(!isin(b))   {cout<<"��Ԫ�ز��ڼ�����"; return *this;}
	a--;
	for(int i=num;i<=a;i++){
		pa[i]=pa[i+1];   //b���Ԫ�ض���ǰ�ƶ�һλ
	}*/
	return *this;
}

Set Set::operator *(Set A)
{
	/*
	if(!isin(b))   {cout<<"��Ԫ�ز��ڼ�����"; return *this;}
	a--;
	for(int i=num;i<=a;i++){
		pa[i]=pa[i+1];   //b���Ԫ�ض���ǰ�ƶ�һλ
	}*/
	return *this;
}

int main()
{
	set<int> s1,s2;//������ֵ�� ����Ҫpair�����һ������Ϊ�����ڶ���Ϊֵ������ 
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
