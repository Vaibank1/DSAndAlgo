#include<vector>
#include<string>

using namespace std;



int num(string s, int curPos)
{
	if (curPos >= s.length())
		return 1;

	int a = s[curPos] - '0';

	if (a == 0)
		return 0;
	int res = 0;
	res = num(s, curPos + 1);

	if (curPos + 1 < s.length()) {
		curPos++;
		int b = s[curPos] - '0';
		int x = a * 10 + b;
		if (x>0 && x <27)
			res += num(s, curPos + 1);

	}

	return res;

}

int numDP(string s)
{
	if (s.empty() || s[0] == '0')
		return 0;
	int n = s.length();
	vector<int> dp( n+1);

	dp[n] = 1;
	for (int i = n-1; i >=0; i--)
	{
		if (s[i] == '0') {
			dp[i] = 0;
			continue;
		}

		dp[i] = dp[i + 1];
		if ( i<n-1 && ( s[i] == '1' || (s[i ] == '2' && s[i+1] < '7')))
			dp[i] += dp[i +2];
	}

	return dp[0];

}


int main()
{
int res =	numDP("101");
	return 0;
}