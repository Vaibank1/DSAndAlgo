#include<iostream>
using namespace std;

class Base
{
public:
	Base() { std::cout << "Base constructor\n"; f(); }

	virtual void f() { std::cout << "Base::f\n"; }
};

class Derived : public Base {
public:
	Derived() 
	{
		std::cout << "Derived constructor\n"; 
	}

	virtual void f() { std::cout << "Derived::f\n"; }
};

int main()
{
	Derived derived;
	return 0;
}