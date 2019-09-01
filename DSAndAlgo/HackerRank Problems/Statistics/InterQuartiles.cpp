#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;


double findMedian(vector<int>&arr, int start, int end)
{
	int N = end - start;
	double median = 0;
	if (N % 2)
	{
		median = arr[start + N / 2];
	}
	else
	{
		median = arr[start + N / 2] + arr[start + N / 2 - 1];
		median /= 2.0;
	}

	return median;

}

int main() {
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */
	int N = 0;
	cin >> N;
	vector<int> num(N),freq(N),arr;
	for (int i = 0; i<N; i++)
		cin >> num[i];
	for (int i = 0; i<N; i++)
		cin >> freq[i];
	for (int i = 0; i < N; i++)
		for (int j = 0; j < freq[i]; j++)
			arr.push_back(num[i]);
	sort(arr.begin(), arr.end());
	N = arr.size();
	//find median


	//find median in left half
	/*cout << findMedian(arr, 0, N / 2) << endl;
	cout << findMedian(arr, 0, N) << endl;
	cout << findMedian(arr, N % 2 ? N / 2 + 1 : N / 2, N) << endl;*/

	cout << std::fixed;
	cout << setprecision(1);

	cout << findMedian(arr, N % 2 ? N / 2 + 1 : N / 2, N) - findMedian(arr, 0, N / 2);



	return 0;
}
