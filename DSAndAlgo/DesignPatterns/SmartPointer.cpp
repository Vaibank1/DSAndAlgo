#include<iostream>
#include<conio.h>
#include<crtdbg.h>


using namespace std;

template<typename T>
class SmartPtr
{
	T* ptr;

	SmartPtr(const SmartPtr<T>& s);
	SmartPtr operator=(const SmartPtr<T>&);
public:
	SmartPtr(T* p) :ptr(p) {}
	~SmartPtr()
	{
		delete ptr;
		cout << "Destructing ptr \n";
	}


	T& operator*()
	{
		return (*ptr);
	}

	T* operator->()
	{
		return ptr;
	}

};


class Test {

public:
	int x;
	int y;

};

int main()
{
	{
		SmartPtr<int> p(new int());
		*p = 1;
		cout << *p << endl;

		SmartPtr<Test> t(new Test());
		t->x = 0;
		t->y = 1;
		cout << (*t).x << endl << t->y << endl;		

	}

	_CrtDumpMemoryLeaks();

	return 0;


}