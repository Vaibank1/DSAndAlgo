#include<map>
#include<set>
#include<string>
#include<unordered_map>
#include<numeric>
#include<climits>
#include<iterator>
#include<array>
#include<iostream>
#include<bitset>
using namespace std;


int wrongSolver(std::vector <unsigned int> a) {
	int n = a.size();
	std::vector<unsigned int> prefSum(n), sufSum(n);
	bool overflow = false;

	prefSum[0] = a[0];
	for (int i = 1; i < n; i++) {
		prefSum[i] = prefSum[i - 1] + a[i];
		if (prefSum[i] < prefSum[i - 1])
			overflow = true;
	}
	sufSum[n - 1] = a[n - 1];
	for (int i = n - 2; i >= 0; i--) {
		sufSum[i] = sufSum[i + 1] + a[i];
		if (sufSum[i] < sufSum[i + 1])
			overflow = true;

	}
	unsigned int mn = prefSum[0] + sufSum[0];
	int where = 1;
	for (int i = 1; i < n; i++) {
		unsigned int val = prefSum[i] + sufSum[i];
		if (val < prefSum[i] || val < sufSum[i])
			overflow = true;
		if (val < mn) {
			mn = val;
			where = i + 1;
		}
	}
	if (overflow)
		cout << "true";
	else
		cout << "false";
	return where;
}


int main()
{
	int t = 0;
	cin >> t;
	while (t--)
	{
		int n = 0;
		cin >> n;
		unsigned int val = (4294967296) / (n)+1;



		for (int i = 0; i < n; i++)
		{
			cout << val << ' ';
		}


	}
	//cout << INT32_MAX/2;

	return 0;
}