#include"Node.h"
#include<numeric>
#include<climits>
#include<iterator>

using namespace std;
void findMaxSubArray(vector<int> arr, int k)
{
	vector<int> prefixSum;
	partial_sum(arr.begin(), arr.end(), back_inserter(prefixSum));

	vector<int> min_prefixSum(prefixSum);
	for (int i = (min_prefixSum.size() - 2); i >= 0; i--)
	{
		min_prefixSum[i] = min(min_prefixSum[i], min_prefixSum[i + 1]);
	}

	pair<int, int> arr_idx(0, upper_bound(min_prefixSum.begin(), min_prefixSum.end(), k) - min_prefixSum.begin() - 1);

	for (int i = 0; i < prefixSum.size(); i++)
	{
		int idx = upper_bound(min_prefixSum.begin(), min_prefixSum.end(), k + prefixSum[i]) - min_prefixSum.begin() - 1;

		if (idx - i - 1 > arr_idx.second - arr_idx.first)
		{
			arr_idx = {i + 1, idx};
		}
	}


}


int main()
{
	vector<int> arr = { 1,5,7,-16,1,2,3,4 };
	findMaxSubArray(arr, 11);

	return 0;
}