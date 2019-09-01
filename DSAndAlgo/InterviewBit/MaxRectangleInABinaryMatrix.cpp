
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void bfs(const vector<vector<int> > &A, vector<vector<bool> > &visit, int & count, int row, int col)
{
	if (visit[row][col] == true)
		return;
	if (A[row][col] == 0)
		return;

	count++;
	visit[row][col] = true;
	if (row - 1 >-1 && !visit[row - 1][col])
		bfs(A, visit, count, row - 1, col);
	if (row + 1< A.size() && !visit[row + 1][col])
		bfs(A, visit, count, row + 1, col);
	if (col - 1 >-1 && !visit[row][col - 1])
		bfs(A, visit, count, row, col - 1);
	if (col + 1 <A[0].size() && !visit[row][col + 1])
		bfs(A, visit, count, row, col + 1);
}


int maximalRectangle(vector<vector<int> > &A) {

	int count = 0;
	int maxC = 0;
	vector<vector<bool> > visit(A.size(), vector<bool>(A[0].size(), false));

	for (int i = 0; i<A.size(); i++)
		for (int j = 0; j<A[0].size(); j++)
		{
			bfs(A, visit, i, j, count);
			maxC = max(maxC, count);
			count = 0;

		}
	return maxC;

}


int main()
{
	vector<vector<int> > A = { {1 ,1, 1},
	{0 ,1 ,1 },
		{1, 0, 0
}};


	maximalRectangle(A);
	return 0;
}

