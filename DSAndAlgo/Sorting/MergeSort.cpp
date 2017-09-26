#include "stdafx.h"
#include <vector>
#include <iostream>
#include <conio.h>
#include <cmath>
#include <string>

#include <algorithm>

using namespace std;


int auxArr[14] ;

int min(int a, int b)
{
	return a < b ? a : b;
}

void Merge(int arr[], int low, int mid, int high)
{
	/*if (high - low == 1)
		return;*/
		
	for (int i = low; i <= high; ++i)
	{
		auxArr[i] = arr[i];
	}
	int l = low;
	int h = mid+1;
	
	for (int i = low; i <= high; i++)
	{
		if (l > mid)
		{
			arr[i] = auxArr[h];
			h++;
		}
		else if (h > high)
		{
			arr[i] = auxArr[l];
			l++;
		}
		else if (auxArr[l] < auxArr[h])
		{
			arr[i] = auxArr[l];
			l++;
		}
		else
		{
			arr[i] = auxArr[h];
			h++;
		}

	}



}


void MergeSort(int arr[], int low, int high)
{
	if (low >= high)
		return;
	int mid = low + high;
	mid /=  2;
	

	MergeSort(arr, low, mid);
	MergeSort(arr, mid + 1, high);
	Merge(arr,low, mid, high);

}
void print(int arr[], int n)
{
	for (int i = 0; i < n; ++i)
	{
		cout << arr[i] << '\t';
	}
}

int main()
{

	/*int x = 5;
	x= (x++)*(x++);*/

	int arr[] = { 1,2,432,213,43,24,5,233,534,4,2134,65,12 };
	int arrDup[] = { 1,2,432,5,5,24,5,233,534,5,2134,5,12 };
	int n = sizeof(arr) / sizeof(arr[0]);

	

	MergeSort(arr, 0, n-1);
	print(arr, n);
	cout << endl;
	MergeSort(arrDup, 0, n - 1);
	print(arrDup, n);

	return 0;

}