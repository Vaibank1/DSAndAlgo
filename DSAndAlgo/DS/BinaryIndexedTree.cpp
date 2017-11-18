#include<iostream>
#include<vector>

using namespace std;


template<class T>
class BIT
{
	int size=0;
	vector<T> bit;
public:
	BIT(const int& s):size(s+1) {
		bit.resize(size);
	}
	~BIT()
	{
		bit.clear();
	}

	void createBIT(const vector<T>& arr)
	{
		
		for (int i = 0; i < arr.size(); i++)
		{
			updateBIT(i, arr[i]);

		}
	}
	void updateBIT(int index,int val)
	{
		int bitIndex = index + 1;

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
		idx++;
		
		//we have to get sum(idx)-sum(idx-1) of bit.
		//instead of calculating the sum(x) twice we trace the path divergence and subtract the difference from that divergence of idx and idx-1

		//getting the lastSameID of idx & idx-1, as idx 
		int lastSameID = idx - (idx&-idx);
		int sum = bit[idx];
		//get sum of idx-1,we dont need idx , so using idx 
		idx--;

		while (idx != lastSameID)
		{
			sum -= bit[idx];

			idx -= idx&-idx;
		}
		return sum;

	}

};


int main()
{
	vector<int> arr = { 1,	0,	2	,1,	1,	3,	0,	4	,2	,5,	2,	2,	3	,1,	0,	2 };

	BIT<int> bit(arr.size());

	bit.createBIT(arr);

	for (int id = 0; id < arr.size(); id++)
	{
		if (bit.getValue(id) != arr[id])
		{
			cout << "Error in implementation of BIT";
		}
		//else
		//{
		//	cout << "Good!!";
		//}

	}
	return 0;
}