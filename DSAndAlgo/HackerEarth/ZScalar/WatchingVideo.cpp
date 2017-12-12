#include<vector>
#include<iostream>
#include<algorithm>
#include<iterator>
#include<numeric>
using namespace std;



int main()
{

	int N = 0, D = 0;
	cin >> N >> D;
	vector<int> videoBuffer(N);
	for (int i = 0; i < N; i++)
	{
		cin >> videoBuffer[i];
	}

	partial_sum(videoBuffer.begin(), videoBuffer.end(),videoBuffer.begin());
	
	for (int & var : videoBuffer)
	{
		var -= D;
	}
	vector<int> dp(N,INT_MAX),actualJump(N,-1);
	dp[0] = 0;
	int i = 0;
	while (videoBuffer[i] < 0 && i < N)
		i++;

	for(i;i<N;i++)
		for (int j = 0; j < i; j++)
		{
			if (videoBuffer[j]+j >= i)
			{
				if (dp[i] > dp[j] + 1)
				{
					dp[i] = dp[j] + 1;
					actualJump[i] = j;
				}
			}

		}


	return 0;


}