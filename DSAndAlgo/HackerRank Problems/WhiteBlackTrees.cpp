#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <List>
#include <map>
using namespace std;

#define n 111111

vector<int> parent(n);
vector<int> dpMax(n);
vector<int> dpMin(n);
vector<int> adjList[n];
vector<int> color(n);
vector<int> result;
int ans = 0, ansNode = -1;




void dfs(int node, int par)
{

	parent[node] = par;
	
	dpMax[node] = +color[node];
	dpMin[node] = -color[node];

	for (int child : adjList[node])
	{
		if (child == par)
			continue;
		dfs(child, node);
		dpMax[node] += max(0, dpMax[child]);
		dpMin[node] += max(0, dpMin[child]);

	}

	int curr = max(dpMax[node],dpMin[node]);
	if (ans < curr)
	{
		ans = curr;
		ansNode = node;
	}

}

void getNodes(int node, bool isInDPMax)
{
	result.push_back(node);
	for (int child : adjList[node])
	{
		if (child == parent[node])
			continue;
		if ((isInDPMax ? dpMax : dpMin)[child] > 0)
		{
			getNodes(child, isInDPMax);
		}

	}
}

int main() {
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */
	int N,tmp,u,v;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> tmp;
		if (!tmp)
			tmp = -1;
		color[i] = tmp;

	}
	for (int i = 0; i < N-1; i++)
	{
		cin >> u>>v;
		--u; --v;
		adjList[v].push_back(u);
		adjList[u].push_back(v);
	}

	dfs(0,-1);
	getNodes(ansNode, ans == dpMax[ansNode]);
	for (int i : result)
	{
		cout << i + 1 << " ";
	}
	return 0;
}
