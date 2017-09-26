#include <vector>
#include <iostream>
#include <conio.h>
#include <math.h>
#include <string>

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include<array>

using namespace std;



template<typename T,size_t N>
int findPivot(array<T, N> arr)
{

	if (arr.size() == 0)
		return -1;

	int start = 0, end = arr.size() - 1;
	
	while (start <= end) {

		int mid = (start + end) / 2;

		if (mid < arr.size() - 1 && arr[mid] > arr[mid + 1]) {
			return (mid + 1);

		}
		else if (arr[start] <= arr[mid]) {
			start = mid + 1;

		}
		else {
			end = mid ;
		}

	}
	return -1;
}

int main()
{
	array<int, 5> arr= {1,2,3,4,5};
	int res =  findPivot(arr);
	cout <<  (res != -1 ? arr[res] : -1 );




	return 0;
}