#include<iostream>


using namespace std;



unsigned long long fibonacci(unsigned long long n , unsigned long long N)
{
	if (n == 1)
		return N;
	N = n*N;
	return fibonacci(n - 1, N);
	
}


unsigned long long fib(int N)
{
	if (N < 1)
		return N;

	return fibonacci(N -1, N);
	
}

int main()
{

	int N = 3
		;

	cout<<fib(N);

	return 0;

}