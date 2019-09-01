
#include<iostream>
#include<conio.h>
#include<thread>
#include<condition_variable>

using namespace std;



condition_variable cvOdd,cvEven;
mutex mtOdd,mtEven;
class MyThread
{
	int N;
	static int counter;
	int curVal;
public:
	MyThread(int n) :N(n) {

		curVal = 0;
	}
	static unsigned _stdcall Start(void* pInfo)
	{
		MyThread* ptr = (MyThread*)pInfo;
		MyThread::counter++;
		if (MyThread::counter == 1)
			ptr->printOdd();
		else if (MyThread::counter == 2)
			ptr->printEven();
		//std::cout << "\nThread exited";
	
		return 0;
	}

	 void print(void*  n)
	{

	
	}
	

	void printEven()
	{
		//std::cout << "Thread Started\n";
		for (int i = 2; i <= N; i = i + 2)
		{
			std::unique_lock<mutex> lg(mtEven);			
			cvEven.wait(lg);
			cout << i << endl;			
			cvOdd.notify_one();
		}
		//std::cout << "reached end of even";

	}

	void printOdd()
	{
		//std::cout << "Thread Started\n";
		for (int i = 1; i <= N; i = i + 2)
		{
			std::unique_lock<mutex> lg(mtOdd);
			cvOdd.wait(lg);
			cout << i << endl;
			cvEven.notify_one();
			

		}


	}

};

int MyThread::counter = 0;

int main()
{
	int N = 100000;
	MyThread obj(N), obj1(N);


	std::thread t1(MyThread::Start,&obj);
	std::thread t2(MyThread::Start, &obj);

	cvOdd.notify_one();


	t1.join();
	t2.join();

	
	
	
	
	//_getch();
	return 0;
}