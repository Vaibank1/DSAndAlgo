#include <iostream>
#include <vector>

#include <conio.h>
#include <math.h>
#include <string>
using namespace std;


int countWays(int n)
{
	if (n <= 0)
		return 0;
	if (n == 1)
		return 1;
	if (n == 2)
		return 2;
	if (n == 3)
		return 4;
	return countWays(n - 1) + countWays(n - 2) + countWays(n - 3);

}

int countWaysTopDown(int n,vector<int>& dp)
{
	if (n < 0)
		return 0;
	if (n == 1 || n==0)
		return 1;

	if(dp[n] == 0)
		dp[n] = countWaysTopDown(n - 1,dp) + countWaysTopDown(n - 2,dp) + countWaysTopDown(n - 3,dp);
	return dp[n];

}

int countWaysBottomUp(int n)
{
	vector<int> vec(n + 1);
	vec[0] = 0;
	vec[1] = 1;
	vec[2] = 2;
	vec[3] = 4;

	for (int i = 4; i <= n; ++i)
	{
		vec[i] = vec[i - 1] + vec[i - 2] + vec[i - 3];
	}

	return vec[n];
}

int main()
{


	int n = 5
		;
	cout << countWays(n) << endl;
	vector<int> vec(n+1) ;
	cout << countWaysTopDown(n,vec) << endl;
	cout << countWaysBottomUp(n) << endl;
	return 0;

}