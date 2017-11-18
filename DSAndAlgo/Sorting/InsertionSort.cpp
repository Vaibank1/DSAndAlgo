#include<iostream>
#include<vector>
#include<iterator>
#include<algorithm>

using namespace std;



void swap(int* a, int* b)
{

}

void InsertionSort(vector<int>& arr)
{

	for (int  i = 1; i < arr.size(); i++)
	{
		int j = i - 1;
		int key = arr[i];

		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j+1] = key;

	}

}


int main()
{


	vector<int> arr = { 1,2,432,213,43,24,5,233,534,4,2134,65,12 };
	vector<int>  arrDup= { 1,2,432,5,5,24,5,233,534,5,2134,5,12 };



	InsertionSort(arr);
	copy(arr.begin(), arr.end(), ostream_iterator<int>(cout, " "));
	cout << endl;
	InsertionSort(arrDup);
	copy(arrDup.begin(), arrDup.end(), ostream_iterator<int>(cout, " "));


	return 0;

}