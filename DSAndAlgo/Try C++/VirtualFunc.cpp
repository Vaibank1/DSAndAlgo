
#include<iostream>
using namespace std;

class A
{
private:
	virtual void f()
	{
	
		cout << "A" << endl;
	}

	const static void f(int a)
	{
	}

public:


};


class B : public A
{
public:
	B() {}

	~B(){}

	virtual void f()
	{
		cout << "B" << endl;
	}
private:

};



class test
{
	int a;
public:
	void set()
	{
		a = 5;
	}


	test& operator=(const test& b)	
	{
		if (this != &b)
		{
			a = b.a;

		}

		return *this;

	}
};

int main()
{
	test a, b,c;
	c.set();
	a = b;
	a = b = c;


	//B* ptr = static_cast<B*>( new A());

	//ptr->f();

	////B* ptr = dynamic_cast<B*>(new A());
	////ptr->f();

	//int arr[] = {10,23,34};
	//int *p = arr;
	//cout<<++*p<<endl;//incremeent 10
	//cout << *p++ << endl;//pointe inc
	//cout << *(++p) << endl;//pointer inc
	//cout << *(++p) << endl;//pointer inc
	//cout << *++p << endl;//pointer inc
	return 0;
}