#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;





using namespace std;

#define mi 1000000007
#define rep(i,a,b) for(i=a;i<b;i++)

int dp[1005][10005], presum[1005][10005];
inline int mod(int x) {
	return (x + mi) % mi;
}
int main() {
	int n, m, k, i, j;
	scanf_s("%d", &n); scanf_s("%d", &m); scanf_s("%d", &k);

	for (i = 1; i<n + 1; i++)
		dp[0][i] = 0, presum[0][i] = 1;
	for (i = 0; i<m + 1; i++)
		presum[i][0] = dp[i][0] = 1;
	for (i = 1; i<m + 1; i++) {
		for (j = 1; j<n + 1; j++)
		{
			dp[i][j] = presum[i - 1][j];

			if (j>k) {
				dp[i][j] -= presum[i - 1][j - k - 1];
				dp[i][j] = mod(dp[i][j]);
			}

		}

		for (j = 1; j<n + 1; j++)
			presum[i][j] = (dp[i][j] + presum[i][j - 1]) % mi;
	}
	printf("%lld\n", dp[m][n]);
	return 0;
}



//My solution unfortunately didn't work :S
//unsigned long long dp[7][4] = { 0 };
//
//
//
//
//
//
//int main() {
//	/* Enter your code here. Read input from STDIN. Print output to STDOUT */
//
//	unsigned long long n = 3, m = 3, k = 2;
////	cin >> n >> m >> k;
//	//int n = 7, k = 3,m=2;
//	int arr[7] = {0,1,1,2,2,3,3};
//	for (int i = 1; i <= k*m; i++)
//	{
//		dp[i][1] = 1;
//
//	}
//
//	//for each length of p
//	for (int p = 2; p <= n;p++)
//	{
//		vector<int> num(m+1,0);
//		//calc num of sequence of length p-1 and one less element
//		for (int i = 2; i <= k*m; i++)
//		{
//			num[arr[i - 1]] += dp[i - 1][p - 1];
//
//			//add all the sequences which are less than arr[i] and off length p-1 ,as now with current element we can make sequence of length p.
//			for (int j = 1; j < arr[i]; j++)
//			{
//				dp[i][p] += num[j];
//			}
//		}
//
//	}
//			return 0;
//}