#include<iostream>
#include<vector>
#include<algorithm>



using namespace std;


int main()
{
	int N;
	cin >> N;
	vector<int> arr(2*N);
	for (int i = 0; i < 2*N; i++)
		cin >> arr[i];
	sort(arr.begin(), arr.end());
	int maxS = 0;
	for (int i = 0; i < 2*N - 1; i += 2)
	{
		maxS += min(arr[i], arr[i + 1]);

	}

	cout << maxS;
	return 0;
}