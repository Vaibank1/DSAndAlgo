#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;


int lcs(const string& X, const string& Y)
{
	int m = X.length(); int n=Y.length();
	vector<vector<int>> dp(m + 1, vector<int>(n + 1));
	
	for (int i = 0; i <= m; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			if (i == 0 || j == 0)
				dp[i][j] = 0;

			else if (X[i - 1] == Y[j - 1])
				dp[i][j] = dp[i - 1][j - 1] + 1;

			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}

	
	return dp[m][n];
}

int LCS(const string& str1, const string &str2, int K)
{
	int maxLCS = str1.length() < str2.length() ? str1.length() : str2.length();
	if (K >= maxLCS)
		return maxLCS;

	vector<vector<vector<int>>> dp(str1.length()+1, vector<vector<int>>(str2.length()+1, vector<int>(K+1)));

	for(int i=0;i<=str1.length();i++)
		for(int j=0;j<=str2.length();j++)
			for (int k = 0; k <= K; k++)
			{
				if (i == 0 || j == 0)
					dp[i][j][k] = 0;
				else if (str1[i - 1] == str2[j - 1])
					dp[i][j][k] = max(dp[i - 1][j][k], max(dp[i][j - 1][k], 1 + dp[i - 1][j - 1][k]));
				else
				{
					int res = max(dp[i - 1][j][k], dp[i][j - 1][k]);
					int res1=1;
					if (k != 0)
						res1 += dp[i - 1][j - 1][k - 1];

					dp[i][j][k] = max(res,res1);

				}

			}

	return dp[str1.length()][str2.length()][K]-1;

}

int main()
{
	string str1, str2;
	getline(cin, str1);
	getline(cin, str2);
	int K1, K2;
	cin >> K1 >> K2;
	int res= K1+K2 == 0? lcs(str1,str2): LCS(str1, str2, K1 + K2);
	cout << res;

	return 0;
}