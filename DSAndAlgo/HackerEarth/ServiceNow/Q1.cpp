/*
// Sample code to perform I/O:

cin >> name;                            // Reading input from STDIN
cout << "Hi, " << name << ".\n";        // Writing output to STDOUT

// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
*/

// Write your code here

#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

bool myfunction(pair<int, bool> i, pair<int, bool> j) {
	return (i.first<j.first);

}

bool cmp(pair<int, bool> i, int j) {
	return (i.first<j);

}
bool cmp1(int i, pair<int, bool>  j) {
	return (i<j.first);

}
int main()
{
	int T = 0;
	cin >> T;
	while (T--)
	{
		int  N, M, K;
		cin >> N >> M >> K;

		vector<pair<int, bool>> weights(N);
		for (int i = 0; i<N; i++)
			cin >> weights[i].first;
		sort(weights.begin(), weights.end(), myfunction);
		int ans = 0, b;
		for (int i = 0; i<M; i++)
		{
			cin >> b;
			auto itIndex = upper_bound(weights.begin(), weights.end(), b, cmp1);
			if (itIndex == weights.begin())
			{
				continue;
			}
			itIndex--;
			int a = (*itIndex).first;
			if ((a <= b && (a + K) >= b) && (*itIndex).second == false)
			{
				ans++;
				(*itIndex).second = true;
			}
			else
				continue;
		}
		cout << ans;
		
	}

	return 0;
}
