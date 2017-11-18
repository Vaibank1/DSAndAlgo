#include<iostream>
#include<vector>

using namespace std;



int main()
{
	int N = 0;
	cin >> N;
	vector<int> arr(N);
	for (int i = 0; i < N; i++)
		cin >> arr[i];

	long long moves = 0;
	for (int  i = 0; i < N-1; i++)
	{
		if (arr[i + 1] <= arr[i])
		{
			moves += arr[i] - arr[i+1] + 1;
			arr[i + 1] = arr[i] + 1;
		}

	}


	cout << moves;
	return 0;
}