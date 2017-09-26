#include "stdafx.h"
#include <vector>
#include <iostream>
#include <conio.h>
#include <math.h>
#include <string>


using namespace std;
int n = 0;

void swap(int* p, int* s)
{
	int temp = *p;
	*p = *s;
	*s = temp;
}
void print(int arr[], int n)
{
	for (int i = 0; i < n; ++i)
	{
		cout << arr[i] << '\t';
	}
}


//DO NOT WORK FOR REPETATIVE ELEMENTS
int partition(int arr[],  int low , int high)
{
	//partitioning element
	int k = low;
	int l = low+1, h=high;
	
	while (true)
	{
		while (arr[l] < arr[k])
			l++;
		
			
		
		while (arr[h] > arr[k])
			h--;

		if (l >= h)
			break;
		
		swap(&arr[l], &arr[h]);

	}
	cout << "After partition of " << arr[k] << " in the subarray  " << low << "  " << high << endl;
	swap(&arr[k], &arr[h]);

	
	print(arr, n);
	cout << endl;

	return h;

}



void quickSort(int arr[], int low , int high)
{

	/*for (int i = 0; i < n; i++)
	{
		partition(arr, i, 0, n - 1);
		cout << "After pass " << i + 1 << endl;
		print(arr, n);
		cout << endl;
	}*/
	if (low >= high)
	{
		return;
	}

	//pick the first element , to partition the array
	int pos = partition(arr,low,high);

	quickSort(arr, low, pos);
	quickSort(arr, pos+1, high);



	


}


void ThreeWayPartition(int arr[], int low, int high)
{
	if (low >= high)
		return;

	int k = arr[low];
	int i = low+1;
	int le = low;
	int ge = high;
	
	while (i<=ge)
	{
		if (arr[i] < k)
		{
			//move towards first
			swap(&arr[i], &arr[le]);
			i++; le++;
		}
		else if (arr[i] > k)
		{
			swap(&arr[i], &arr[ge]);
			ge--;
		}
		else
			i++;

	}
	cout << "After partition of " << k << " in the subarray  " << low << "  " << high << endl;
	print(arr, n);
	cout << endl;

	ThreeWayPartition(arr, low, le );
	ThreeWayPartition(arr, ge+1, high);

}




int main()
{

	int arr[] = {1,2,432,213,43,24,5,233,534,4,2134,65,12};
	int arrDup[] = { 1,2,432,5,5,24,5,233,534,5,2134,5,12 };
	 n = sizeof(arr) / sizeof(arr[0]);

	quickSort(arr, 0,n-1);

	ThreeWayPartition(arrDup, 0, n - 1);
	//print(arr, n);
	
	return 0;

}