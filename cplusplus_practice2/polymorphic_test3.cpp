#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

class B1
{
public :
	B1()
		:_b1(1)
	{}
	virtual void FunTest1()
	{
		cout << "B1::FunTest1()" << endl;
	}
	virtual void FunTest2()
	{
		cout << "B1::Funtest2()" << endl;
	}
	virtual void FunTest3()
	{
		cout << "B1::FunTest3()" << endl;
	}
	int _b1;
};

class B2
{
public :
	B2()
		:_b2(2)
	{}
	virtual void FunTest4()
	{
		cout << "B2::FunTest4()" << endl;
	}
	virtual void FunTest5()
	{
		cout << "B2::Funtest5()" << endl;
	}
	virtual void FunTest6()
	{
		cout << "B2::FunTest6()" << endl;
	}
	int _b2;
};

class C :public B1, public B2//��̳�
{
public :
	C()
		:_c(3)
	{}
	virtual void FunTest1()//��дB1
	{
		cout << "C::FunTest1()" << endl;
	}
	virtual void FunTest6()//��дB2
	{
		cout << "C::Funtest6()" << endl;
	}
	virtual void FunTest7()//C�����е��麯��
	{
		cout << "C::FunTest7()" << endl;
	}
	int _c;
};

typedef void(*_pFun_t)();//_pFunΪһ������ָ��
void PrintVfptr(_pFun_t* _pPfun)
{
	while (*_pPfun)
	{
		(*_pPfun)();//�����麯��
		_pPfun = (_pFun_t*)((int*)_pPfun + 1);
	}
}

void Test1()
{
	C c;
	B1& b1 = c;
	_pFun_t* pPFun = (_pFun_t *)(*(int*)&b1); 
	PrintVfptr(pPFun);
	cout << "----------------" << endl;
	B2& b2 = c;
    pPFun = (_pFun_t *)(*(int*)&b2); 
	PrintVfptr(pPFun);
}
int main()
{
	Test1();
	return 0;

}

