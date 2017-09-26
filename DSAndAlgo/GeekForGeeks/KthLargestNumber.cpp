#include "stdafx.h"
#include <vector>
#include <iostream>
#include <conio.h>
#include <math.h>
#include <string>
#include <array>


using namespace std;


template<typename T , size_t N>
void print(array<T, N> const & arr)
{
	for (const auto& a : arr)
		cout << a << '\t';
	cout << endl;
}


template<typename T,size_t N>
void Swap(array<T,N> & arr, int a, int b)
{
	T c = arr.at(a);
	arr.at(a) = arr.at(b);
	arr.at(b) = c;
}

template<typename T, size_t N>
int partition(array<T, N>  & arr , int l , int h)
{	
	int k = l++;
	while (l<=h)
	{
		while (arr[l] > arr[k])
		{
			++l;
		}
		while (arr[h] < arr[k])
		{
			--h;
		}
		if (l >= h)
			break;
		Swap(arr,l,h);

	}
	Swap(arr,k, h);
	return h;

}


template<typename T, size_t N>
int kLargestElement(array<T, N>  & arr, int k,int low , int high)
{
	

	int j = 0;
	while (low <=high)
	{
		j=partition(arr, low, high);

		if (j == k)
			return arr[k];
		if (j > k)
		{
			
			high = j-1;
		}
			
		else
		{
			
			low = j+1;
		
		}


	}


	return arr[j];


	

}


int main()
{

	array<int, 10> arr{ 13,4,543,235,23,42,342,6,53,435};
	//print (arr);
	int k = 0;

	//cout << typeid(arr).name();
	cout << "Enter K: ";
	cin >> k;

	cout << endl<<k <<" largest integer in " << endl;
	print(arr);	
	cout << "\n is  " << kLargestElement(arr, k-1, 0, arr.size()-1);
	
	return 0;
}