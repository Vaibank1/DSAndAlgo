
#include <vector>
#include <iostream>
#include <conio.h>
#include <math.h>
#include <string>

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include<memory>

#include<algorithm>
#include<functional>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<string>
#include<unordered_map>
#include<numeric>
#include<climits>
#include<iterator>
#include<array>
using namespace std;


int main()
{
	int n = 3, m = 3, k = 2;
	int arr[] = {0,1,2,3,1,2,3};
	int dp[10][4] = { 0 };
	for (int i = 1; i <= m*k; i++)
	{
		//dp[i][1] = i%2?(i/2 +1):i/2;
		dp[i][1] = 1;
	}
	
	for (int p = 2; p <= m; p++)
	{
		vector<int> num(4, 0);

		for (int i = 2;  i <= k*m; i++)
		{
			num[arr[i - 1]] += dp[i - 1][p-1];
			for (int j = 1; j <arr[i]; j++)
			{
				dp[i][p] += num[j];
			}

		}
	}



	return 0;
}