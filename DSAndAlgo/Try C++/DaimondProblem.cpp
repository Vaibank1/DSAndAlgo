#include<iostream>

using namespace std;


class A
{
public:
	A()
	{
	}

	~A()
	{
	}

	virtual void f()
	{
		cout << "A \n";
	}
private:
	int x;
};

class B:public A
{
public:
	B()
	{
	}

	~B()
	{
	}

	void f()
	{
		cout << "B\n";
	}
private:

};


class C:public A
{
public:
	C()
	{
	}

	~C()
	{
	}

	virtual void f()
	{
		cout << "C \n";
	}
private:

};




class D : public A/*, public B*/
{
public:
	//virtual void a() {}

};


int main()
{

	D obj;
	cout << sizeof(int) << endl;
	obj.A::f();
	cout<<sizeof(A)<<endl;
	cout << sizeof(B) << endl;
	cout << sizeof(C) << endl;
	cout << sizeof(D) << endl;
	return 0;
}