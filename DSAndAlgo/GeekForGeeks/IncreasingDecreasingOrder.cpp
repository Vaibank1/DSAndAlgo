#include "stdafx.h"

#include <vector>
#include <iostream>
#include <conio.h>
#include <math.h>
#include <string>
#include <queue>
#include <array>
#include <stack>


using namespace std;



template<typename T, size_t N>
void print(const array<T, N> & arr)
{
	for (const auto & a : arr)
	{
		cout << a << '\t';
	}
	cout << endl;
}

//template<typename T, size_t N>
//void Swap(array<T, N> & arr, int a, int b)
//{
//	T c = arr.at(a);
//	arr.at(a) = arr.at(b);
//	arr.at(b) = c;
//}

template<typename T, size_t N>
void increasingDecreasingOrder(array<T, N>& arr)
{
	for (int  i = 0; i < arr.size()-1; i++)
	{
		if (i % 2 && arr[i] < arr[i+1])
		{
			swap(arr[i], arr[i + 1]);

		}
		else if(i%2==0 && arr[i]>arr[i+1])
		{
			swap(arr[i], arr[i + 1]);

		}
	}

}

int main()
{
	array<int, 10> arr;
	for (auto &a : arr)
	{
		a = rand() % 100 + 1;
	}

	print(arr);
	increasingDecreasingOrder(arr);
	print(arr);

	return 0;

}