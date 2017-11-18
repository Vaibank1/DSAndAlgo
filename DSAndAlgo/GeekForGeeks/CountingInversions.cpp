#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


template<class T>
class BIT
{
	int size = 0;
	vector<T> bit;
public:
	BIT(const int& s) :size(s + 1) {
		bit.resize(size);
	}
	~BIT()
	{
		bit.clear();
	}

	void createBIT(const vector<T>& arr)
	{
		bit[0] = 0;
		for (int i = 1; i <= arr.size(); i++)
		{
			updateBIT(i, arr[i]);

		}
	}
	void updateBIT(int index, int val)
	{
		int bitIndex = index ;

		while (bitIndex < size)
		{
			bit[bitIndex] += val;
			bitIndex += bitIndex&-bitIndex;

		}

	}


	int getValue(int idx)
	{

		//get the actual value at idx
		//index in bit is +1 then of arr
		/*idx++;*/

		//we have to get sum(idx)-sum(idx-1) of bit.
		//instead of calculating the sum(x) twice we trace the path divergence and subtract the difference from that divergence of idx and idx-1

		//getting the lastSameID of idx & idx-1, as idx 
		int lastSameID = idx - (idx&-idx);
		int sum = bit[idx];
		if (idx > 0)
			//get sum of idx-1,we dont need idx , so using idx 
		{
			idx--;

			while (idx != lastSameID)
			{
				sum -= bit[idx];

				idx -= idx&-idx;
			}
		}
		return sum;

	}

	int getSum(int index)
	{
		int sum = 0;
		while (index)
		{
			sum += bit[index];
			index -= index&(-index);
		}
		return sum;
	}
	

};


int countInversionBIT(vector<int> arr)
{
	int maxVal = 0;

	for (const int &i : arr)
	{
		maxVal =  max(maxVal, i);
	}

	BIT<int> bit(maxVal);

	int inversionCount = 0;

	for (int j=arr.size()-1;j>=0;j--)
	{
		int i = arr[j];
		inversionCount += bit.getSum(i-1);

		bit.updateBIT(i, 1);
	}
	return inversionCount;

}



//merge sort modification


int merge(vector<int>& arr, int low, int high, int mid)
{
	vector<int> tmp(arr.size());

	int arrF = low, arrS = mid+1 , inversions=0;
	for (int i = low; i <= high; i++)
	{
		if (arrF >mid)
		{
			tmp[i] = arr[arrS];
			arrS++;
		}
		else if (arrS > high)
		{
			tmp[i] = arr[arrF];
			arrF++;
		}

		else if (arr[arrF] <= arr[arrS])
		{
			tmp[i] = arr[arrF];
			arrF++;
		}
		else if (arr[arrF] > arr[arrS])
		{
			tmp[i] = arr[arrS];
			inversions += (arrS - i);
			arrS++;
		}
	}

	for (int i = low; i <= high; i++)
	{
		arr[i] = tmp[i];
	}

	return inversions;

}

int mergeSort( vector<int>& arr, int low, int high)
{
	if (low >= high)
		return 0;

	int mid = (low + high) / 2;

	int inversion = 0;
	
	inversion+= mergeSort(arr, low, mid);
	inversion+= mergeSort(arr, mid+1 , high);
	inversion += merge(arr, low, high, mid);

	return inversion;
}


int main()
{

	vector<int> arr = { 8,4,2,1,5};

	cout << countInversionBIT(arr)<<endl;


	cout << mergeSort(arr, 0, arr.size()-1);


	return 0;
}