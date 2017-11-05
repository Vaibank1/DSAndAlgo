#include<iostream>
#include<vector>
#include<algorithm>
#include<iterator>

using namespace std;
const int N = 100000 + 1;
vector<int>tree[N];

void findPath(int node, int root,vector<int>& path,bool& isFound, vector<bool>& visited)
{
	if (isFound)
		return;
	visited[root] = true;
	if (root == node)
	{
		path.push_back(root);
		isFound = true;
		return;
	}
	path.push_back(root);

	for (int child : tree[root])
	{
		if (!visited[child] )
			findPath(node, child, path,isFound,visited);
		if (isFound)
			return;
	}
	path.pop_back();


}

int main()
{
	int n = 0  ;
	cin >> n;

	int x, y;
	for (int i = 0; i < n-1; i++)
	{
		cin >> x >> y;
		tree[x].push_back(y);
		tree[y].push_back(x);
	}
	int q = 0,t=0;
	cin >> q;
	for (int i = 0; i < q; i++)
	{
		cin >> t;
		vector<int> path;
		bool found = false;
		vector<bool> visited(N + 1, false);
		findPath(t, 1, path,found,visited);
		int count = 0;
		for (int node : path)
		{			
			count += tree[node].size()-1;
			
			if ( node !=1  && node!= *(path.end()-1))
				count--;
			

		}
		if (t == 1)
			count++;
		cout << count<<endl;
	}

	return 0;
}