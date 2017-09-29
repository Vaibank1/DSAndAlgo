#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;


int main() {
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */
	int  n, m, tmp, maxP = 0;
	cin >> n;
	int** matrix = new int*[n];
	cin >> m;
	vector<int>x, y, p;
	for (int i = 0; i < n; i++)
	{
		matrix[i] = new int[n];
		for (int j = 0; j < n; j++)
		{

			matrix[i][j] = 0;
		}
	}
	for (int i = 0; i<m; i++)
	{
		cin >> tmp;
		x.push_back(tmp);
		cin >> tmp;
		y.push_back(tmp);
		cin >> tmp;
		p.push_back(tmp);
		matrix[x[i]][y[i]] = p[i];
		maxP = max(maxP, p[i]);

	}
	int xDiff, yDiff, pow;
	for (int i = 0; i<n; i++)
		for (int j = 0; j<n; j++)
		{
			for (int k = 0; k<m; k++)
			{
				xDiff = abs(i - x[k]);
				yDiff = abs(j - y[k]);
				if (i == x[k] && j == y[k])
					continue;
				
				//same x
				if (xDiff == 0 && yDiff != 0)
				{
					pow = max(0, p[k] - yDiff);
					matrix[i][j] += pow;
				}
				//same y
				else if (yDiff == 0 && xDiff != 0)
				{
					pow = max(0, p[k] - xDiff);
					matrix[i][j] += pow;
				}
				//on one diagonal
				else if (xDiff == yDiff && xDiff != 0)
				{
					pow = max(0, p[k] - xDiff);
					matrix[i][j] += pow;
				}
				//on other diagonal
				else if (x[k]+y[k] == i+j )
				{
					pow = max(0, p[k] - min(xDiff, yDiff));
					matrix[i][j] += pow;
				}
				//other than above
				else
				{
					pow = max(0, p[k] - max(xDiff, yDiff));
					matrix[i][j] += pow;
				}

				maxP = max(maxP, matrix[i][j]);
			}

		}

	cout << maxP;

	for (int i = 0; i < n; i++)
	{
		cout << endl;
		for (int j = 0; j < n; j++)
		{

			cout << matrix[i][j] << '\t';
		}
	}
	return 0;
}
