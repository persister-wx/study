#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

class Date
{
public:
	Date()
	{}
	Date(int y, int m, int d)
		:year(y)
		, month(m)
		, day(d)
	{}
	Date* operator&()
	{
		return this;
	}
	const Date* operator&()const
	{
		return this;
	}
private:
	int year;
	int month;
	int day;
};
void Test1()
{
	Date d2;
	cout << &d2 << endl;//���õ�һ��&��������غ���
	const  Date d1(2017, 2, 15);
	cout << &d1 << endl;//���õڶ���&��������غ���
}

int main()
{

	Test1();
	return 0;
}