#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

class Date
{
public:
	Date()
	{
		cout << "Date()" << this << endl;
	}
	~Date()
	{
		cout << "~Date()" << this <<endl;
	}
private:
	int _data;
};

void Delete(Date* p)
{
	int count = *((int*)p);
	for (int idx = count - 1; idx >= 0; idx--)
	{
		((Date*)p + idx)->~Date();
	}
	free(p);
}
void Test2()
{
	Date* pd = (Date*)malloc(10 * sizeof(Date) + 4);
	if (pd == NULL)
	{
		return;
	}
	*((int *)pd) = 10;
	int count = *((int *)pd);

	for (int idx = 0; idx < count; idx++)
	{
		new(pd + idx) Date;
	}
	Delete(pd);
}


//��new��λ����mallocʵ��new�Ĺ���
void Test1()
{
	Date* pd = (Date*)malloc(sizeof(Date));
	if (pd == NULL)
	{
		return;
	}
	new(pd)Date;//�����캯��
	pd->~Date();//������������
	free(pd);
}

int main()
{
	Test1();
	Test2();
	return 0;
}