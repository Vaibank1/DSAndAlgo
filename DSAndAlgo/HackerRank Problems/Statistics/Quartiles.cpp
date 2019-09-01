#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


long long findMedian(vector<int>&arr, int start, int end)
{
	int N = end - start;
	long long median = 0;
	if (N % 2)
	{
		median = arr[start + N / 2];
	}
	else
	{
		median = arr[start + N / 2] + arr[start + N / 2 - 1];
		median /= 2;
	}

	return median;

}

int main() {
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */
	int N = 0;
	cin >> N;
	vector<int> arr(N);
	for (int i = 0; i<N; i++)
		cin >> arr[i];

	sort(arr.begin(), arr.end());
	//find median


	//find median in left half
	cout << findMedian(arr, 0, N/2) << endl;
	cout << findMedian(arr, 0, N) << endl;
	cout << findMedian(arr, N % 2 ? N / 2 + 1 : N / 2, N) << endl;




	return 0;
}
