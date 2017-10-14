#include<map>
#include<set>
#include<string>
#include<unordered_map>
#include<numeric>
#include<climits>
#include<iterator>
#include<array>
#include<iostream>
#include<vector>

using namespace std;



set<long long> visited;
vector<set<long long>> connectedComponent;

void dfs(long long node, long long parent, const vector<long long> adjList[], set<long long>& curCntdCmpnt)
{
	if (visited.insert(node).second == false)
		return;
	curCntdCmpnt.insert(node);
	for (int i = 0; i<adjList[node].size(); i++)
	{
		int child = adjList[node][i];
		if (node == child || child == parent)
			continue;
		curCntdCmpnt.insert(child);
		dfs(child, parent, adjList, curCntdCmpnt);

	}

}

int main() {
	int q;
	cin >> q;
	for (int a0 = 0; a0 < q; a0++) {
		visited.clear();
		connectedComponent.clear();
		int n;
		int m;
		long x;
		long y;
		cin >> n >> m >> x >> y;
		vector<long long> *adjList = new vector<long long >[n+1];
		for (int a1 = 0; a1 < m; a1++) {
			int city_1;
			int city_2;
			cin >> city_1 >> city_2;
			adjList[city_1].push_back(city_2);
			adjList[city_2].push_back(city_1);
		}
		if (x > y)
		{
			for (long long i = 1; i <= n; i++)
			{
				set<long long> curCntCmpt;
				dfs(i, -1, adjList, curCntCmpt);
				if (curCntCmpt.size() > 0)
					connectedComponent.push_back(curCntCmpt);
			}
			unsigned long long numOfConnectedComponents = connectedComponent.size();
			unsigned long long libraryCost = numOfConnectedComponents*x;
			unsigned long long  roadCost = 0;
			for (auto it : connectedComponent)
			{
				roadCost += y*(it.size() - 1);
			}
			unsigned long long   totalCost = roadCost + libraryCost;
			cout << totalCost << endl;
			


		}
		else
		{
			unsigned long long totalCost = x*n;
			cout << totalCost << endl;

		}
		delete[] adjList;
	}
	return 0;
}
