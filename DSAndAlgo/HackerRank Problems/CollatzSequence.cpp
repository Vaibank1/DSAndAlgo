#include<map>
#include<set>
#include<string>
#include<unordered_map>
#include<numeric>
#include<climits>
#include<iterator>
#include<array>
#include<iostream>
using namespace std;


map<int, int> dp;
int collatzSequenceLen(int n) {
	if (n == 0) {
		return 0;
	}
	if (n == 1) {
		return 1;
	}
	if (n % 2 == 0) {
		if (dp.find(n) == dp.end())
			dp[n] = 1 + collatzSequenceLen(n / 2);
	}
	else
	{
		if (dp.find(n) == dp.end())
			dp[n] = 1 + collatzSequenceLen(3 * n + 1);

	}
	return dp[n];
}

int collatzSequenceSum(int T, int A, int B) {
	int n = 0;
	int result = 0;
	while (T--) {
		n = (A*n + B) % 5003;
		int best_len = 0;
		int best_num = 0;
		for (int k = 0; k <= n; ++k) {
			int cur_len = collatzSequenceLen(k);
			if (cur_len >= best_len) {
				best_len = cur_len;
				best_num = k;
			}
		}
		result += best_num;
	}
	return result;
}



int main() {
	int T;
	int A;
	int B;
	cin >> T >> A >> B;



	int result = collatzSequenceSum(T, A, B);
	cout << result << endl;
	return 0;
}