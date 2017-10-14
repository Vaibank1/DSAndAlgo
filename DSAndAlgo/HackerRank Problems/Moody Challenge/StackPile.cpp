#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

unsigned long long dp[7][4] = { 0 };






int main() {
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */

	unsigned long long n = 3, m = 3, k = 2;
//	cin >> n >> m >> k;
	//int n = 7, k = 3,m=2;
	int arr[7] = {0,1,1,2,2,3,3};
	for (int i = 1; i <= k*m; i++)
	{
		dp[i][1] = 1;

	}

	//for each length of p
	for (int p = 2; p <= n;p++)
	{
		vector<int> num(m+1,0);
		//calc num of sequence of length p-1 and one less element
		for (int i = 2; i <= k*m; i++)
		{
			num[arr[i - 1]] += dp[i - 1][p - 1];

			//add all the sequences which are less than arr[i] and off length p-1 ,as now with current element we can make sequence of length p.
			for (int j = 1; j < arr[i]; j++)
			{
				dp[i][p] += num[j];
			}
		}

	}
			return 0;
}