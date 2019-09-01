#include<iostream>
#include<chrono>
#include<conio.h>


using namespace std;


template<typename T>
T add(T& a, T&b)
{
	return a + b;
}


template<typename Derived>
class CRTP
{
public:
	
	inline void call()
	{
		impl().tick();
	}
private:

	inline Derived& impl()
	{
		return *static_cast<Derived*>(this);
	}

};


class X: public CRTP<X> 
{
public:
	X ():counter(0)
	{
	}

	~X ()
	{
	}

	inline void tick()
	{
		++counter;
		
	}
private:

	unsigned long long counter;
};



class Base
{
public:
	virtual void tick() = 0;

};

class Derived :public Base
{

public:
	void tick()
	{
		++counter;

	}
private:

	unsigned long long counter;


};
int main()
{
	CRTP<X> *p;
	X obj;
	p = &obj;
	unsigned long long  N = 400000000,i,j;
	typedef std::chrono::high_resolution_clock clock;
	auto before = clock::now();

	for(i =0 ; i<N;i++)		
		p->call();

	auto after = clock::now();
	
	cout << "CRTP"<<endl<<chrono::duration_cast<chrono::milliseconds> (after - before).count()<<" milliseconds"<<endl;

	Base* bp = new Derived();
	 before = clock::now();
	for (i = 0; i<N; i++)	
		bp->tick();

	 after = clock::now();

	cout << "Virtual " << endl << chrono::duration_cast<chrono::milliseconds> (after - before).count() << " milliseconds" << endl;


	_getch();
	return 0;

	
}
