#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<iomanip>
using namespace std;



const int N = 100000;
vector<int> tree[N+1];
long double expectedValue = 0, totalDepth=0;
vector<int> sz(N+1),visited(N+1);
int n = 0;

void dfs(int root, int dist)
{
	sz[root] = 1;
	visited[root] = 1;
	for (int child : tree[root])
	{
		if (!visited[child])
		{
			dfs(child, dist + 1);
			sz[root] += sz[child];
		}
	}
	if (root != 1)

	{
		expectedValue += ( dist*(n-sz[root]) *1LL);
		totalDepth += dist;

	}

}


int main() {
	
	cin >> n;
	
	for (int a0 = 0; a0 < n - 1; a0++) {
		int x;
		int y;
		cin >> x >> y;
		tree[x].push_back(y);
		tree[y].push_back(x);
		
	}

	dfs(1, 0);

	long double ans = (long double)expectedValue / (long double)totalDepth;
	cout << fixed << setprecision(10);
	cout <<  ans<< endl;
		

	// Write Your Code Here
	return 0;
}
