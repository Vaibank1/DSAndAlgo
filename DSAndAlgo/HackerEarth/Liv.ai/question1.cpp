#include<iostream>
#include<vector>
#include<algorithm>
#include<iterator>

using namespace std;

const int N = 1000000;
vector<bool> isPrime(N + 1,true);

void calcPrime(int n)
{
	isPrime[1] = false;
	for (int i = 2; i*i <= n; i++)
	{
		if (isPrime[i])
		{
			for (int j = i * 2; j <= n; j += i)
			{
				isPrime[j] = false;
			}
		}

	}
}

int main()
{


	int n = 0;
	cin >> n;
	vector<int> que;
	vector<int> stk;
	vector<int> input(n);
	int mx = 0;
	int tmp;
	for (int i = 0; i < n; i++)
	{
		cin >> input[i];
		mx = max(mx, input[i]);
	
	}
	calcPrime(mx);
	for (int i = 0; i < n; i++)
	{		
		tmp = input[i];
		if (isPrime[tmp])
		{
			que.push_back(tmp);
		}
		else
			stk.push_back(tmp);
	}

	copy(que.begin(), que.end(), ostream_iterator<int>(cout," "));
	cout << endl;
	copy(stk.rbegin(), stk.rend(), ostream_iterator<int>(cout, " "));

	return 0;
}
