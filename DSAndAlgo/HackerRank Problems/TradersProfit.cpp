#include "stdafx.h"
#include <algorithm>

using namespace std;


int traderProfit(int k, int n, vector <int> A) {
    // Complete this function
	int** dp;
	dp =new int*[k+1];


	for (int i = 0; i < k+1; i++)
	{
		dp[i] = new int[n];

	}

	for (int i = 0; i < n; i++)
	{
		dp[0][i]=0;
	}
	for (int i = 0; i < k+1; i++)
	{
		dp[i][0]=0;
	}

	int maxDiff ;
	for (int i = 1; i < k+1; i++)
	{
		maxDiff=dp[i-1][0]-A[0];
		for (int j = 1; j < n; j++)
		{
		
			dp[i][j] = max(dp[i][j-1], A[j]+ maxDiff);
			maxDiff =  max(maxDiff, (dp[i-1][j] - A[j]));
		}

	}

	int ans = dp[k][n-1];
	delete[] dp;

	return ans;

}

int main() {
    int q;
    cin >> q;
    for(int a0 = 0; a0 < q; a0++){
        int k;
        cin >> k;
        int n;
        cin >> n;
        vector<int> arr(n);
        for(int arr_i = 0; arr_i < n; arr_i++){
           cin >> arr[arr_i];
        }
        int result = traderProfit(k, n, arr);
        cout << result << endl;
    }
    return 0;
}