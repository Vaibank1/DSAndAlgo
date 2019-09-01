#include<Windows.h>
#include<process.h>
#include<iostream>
#include<conio.h>



CONDITION_VARIABLE even;
CONDITION_VARIABLE odd;
CRITICAL_SECTION cs;

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
		std::cout << "\nThread exited";
		//Sleep(1000);

		//WakeConditionVariable(&even);
		//Sleep(1000);
		return 0;
	}

	/*static void print(void*  n)
	{
		int* N = (int*)n;
		static int count = 0;
		for (int i = 0; i < *N; i++)
		{
			
			std::cout << '0' << std::endl;
			LeaveCriticalSection(&cs);			
		}
	}*/

	void printEven()
	{
		//std::cout << "Thread Started\n";
		for (int i = 2; i <= N; i=i+2)
		{
			std::cout << "Enter :Even Thread \n";

			EnterCriticalSection(&cs);
			std::cout << "SleepConditionVariableCS :EVEN Thread \n";
			SleepConditionVariableCS(&even,&cs,INFINITE);
			std::cout << i << std::endl; 				
			WakeConditionVariable(&odd);
			std::cout << "WakeConditionVariable :EVEN Thread \n";

			//Sleep(1000);

			LeaveCriticalSection(&cs);
			std::cout << "Leave :Even Thread \n";

		}
		//std::cout << "reached end of even";
		
	}

	void printOdd()
	{
		//std::cout << "Thread Started\n";
		for (int i = 1; i <= N; i = i + 2)
		{
			std::cout << "Enter :ODD Thread \n";

			EnterCriticalSection(&cs);
			std::cout << "SleepConditionVariableCS :ODD Thread \n";

			SleepConditionVariableCS(&odd, &cs, INFINITE);
			std::cout << i << std::endl;			
			WakeConditionVariable(&even);
			std::cout << "WakeConditionVariable:ODD Thread \n";
			//Sleep(1000);
			LeaveCriticalSection(&cs);
			std::cout << "Leave :ODD Thread \n";

		}
	
	
	}

};

int MyThread::counter = 0;

int main()
{
	int N = 10;
	MyThread obj(N),obj1(N);
	UINT a,b;
	HANDLE  thread=(HANDLE) _beginthreadex(NULL,0, MyThread::Start, &obj, CREATE_SUSPENDED,&a);
	HANDLE  thread1 = (HANDLE)_beginthreadex(NULL, 0, MyThread::Start, &obj1, CREATE_SUSPENDED, &b);
	
	ResumeThread(thread);
	ResumeThread(thread1);
	InitializeCriticalSection(&cs);
	InitializeConditionVariable(&odd);
	InitializeConditionVariable(&even);
	Sleep(100);
	WakeConditionVariable(&odd);	
	WaitForSingleObject(thread,INFINITE);		
	WaitForSingleObject(thread1, INFINITE);
	CloseHandle(thread);	
	CloseHandle(thread1);
	//_getch();
	return 0;
}