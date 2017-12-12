#include<iostream>

using namespace std;


class A
{
public:
	A()
	{
		cout << "Default Ctor called..\n";
	}
	A(int a):x(a){}
	~A()
	{
	}

	void f() { cout << "A\n"; }
	
private:
	int x;
	int y;
	char ab;
};

class B: virtual public A
{
public:
	B(int a):A(a)
	{
	}

	~B()
	{
	}

	
private:

};


class C:virtual public A
{
public:
	C(int a):A(a)
	{
	}

	~C()
	{
	}

	
private:

};




class D : public C, public B
{


public:
	//virtual void a() {}
	//D(int a) :C(a), B(a) {}
	D(int a) : A(a),C(a),B(a)
	{
	}


};


class Base
{

	int a;
};

class Derived : public Base
{};

int main()
{

	D obj(5);
	obj.f();
	

	cout << sizeof(int) << endl;
	B b(1);
	C c(2);
	cout<<sizeof(A)<<endl;
	cout << sizeof(B) << endl;
	cout << sizeof(C) << endl;
	cout << sizeof(D) << endl;

	Base* bPtr = new Base();
	Derived * dPtr = new Derived();
	cout << sizeof(Derived) << endl;
	Derived* dPtr = static_cast<Derived*>( bPtr);
	
	

	return 0;
}