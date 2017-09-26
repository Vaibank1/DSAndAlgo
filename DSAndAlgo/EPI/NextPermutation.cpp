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
	std::copy(arr.begin(), arr.end(), ostream_iterator<int>(cout, "\t"));
	cout << endl;
}

template<typename T, size_t N>
void nextPermutation( array<T, N> & a)
{
	//find the point, where or after it we have to make change
	int k = a.size()-2;
	while (a[k] >= a[k + 1] && k >= 0)
		k--;
	if (k <=0)
		return ;
	//if all the numbers are in increasing order after k, then we have to change a[k].
	int l = 0;
	for (int i = k + 1; i < a.size(); ++i)
	{
		if (a[i] > a[k])
			l = i;
		else
			break;
	}
	swap(a[k], a[l]);
	reverse(a.begin() + k + 1, a.end());



}



//template<typename T, size_t N>
//void previousPermutation(array<T, N> & a)
//{
//	//find the point, where or after it we have to make change
//	int k = a.size() - 2;
//	while (a[k] >= a[k + 1] && k >= 0)
//		k--;
//	if (k <= 0)
//		return;
//	//if all the numbers are in increasing order after k, then we have to change a[k].
//	int l = 0;
//	for (int i = k + 1; i < a.size(); ++i)
//	{
//		if (a[i] > a[k])
//			l = i;
//		else
//			break;
//	}
//	swap(a[k], a[l]);
//	reverse(a.begin() + k + 1, a.end());
//
//
//
//}

int main()
{
	array<int, 4> arr = { 0,1,2,3 };


	print(arr);
	
	nextPermutation(arr);

	print(arr);
	
	return 0;

}