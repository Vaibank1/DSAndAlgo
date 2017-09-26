#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */
	int n = 0, m = 0;
	vector<int> coins;
	cin >> n >> m;
	int tmp;
	for (int i = 0; i<m; i++)
	{
		cin >> tmp;
		coins.push_back(tmp);

	}
	int** dp = new int*[m];
	for (int i = 0; i <n; i++)
	{
		dp[i] = new int[n+1];
	}
		

	for (int i = 0; i<m; i++)
	{
		
		for (int j = 0; j <n+1; j++)
		{
			dp[i][j] = 0;
			if (j == 0)
			{
				dp[i][j] = 1;
			
			}
			else
			{
				if (i != 0)
					dp[i][j] += dp[i - 1][j];
				if (j - coins[i] >= 0)
					dp[i][j] += dp[i][j - coins[i]];
			}
			
			cout << dp[i][j] << '\t';
		}
		cout <<endl;
	}




	cout << dp[m-1][n];
/*
	for (int i = 0; i <n; i++)
	{
		delete dp[i];

	}
	delete dp;*/

	return 0;
}