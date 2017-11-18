#include<iostream>
#include<vector>

using namespace std;



int search(const vector<int> & arr, int num)
{
	int low = 0,high= arr.size()-1;

	while (low<=high)
	{
		int mid = (low + high) / 2;
		if (num == arr[mid])
			return mid;

		//if this range is sorted
		if (arr[low] <= arr[mid])
		{
			if (arr[low] <= num && arr[mid] > num)
				high = mid-1;
			else 
				low = mid + 1;

		}
		else if (num > arr[mid] && num <= arr[high])
			low = mid + 1;
		else
			high = mid - 1;
	}
	

	return -1;

}


int main()
{

	vector<int> arr={6,7,8,9,1,2,3,4,5};
	cout<<search(arr,9);
	return 0;
}