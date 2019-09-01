#include<iostream>
#include<vector>
#include<queue>

using namespace std;

bool isvalid(int i, int j, int N)
{
	return (i >= 0 && j >= 0 && i < N && j < N);
}

bool isdelim(pair<int,int>& temp)
{
	return (temp.first == -1 && temp.second == -1);
}

void bsf(vector<vector<char>>& matrix)
{
	queue<pair<int,int>> que;
	int i = 0, j = 0;
	for (auto row : matrix)
	{
		j = 0;
		for (auto cell : row)
		{
			if (cell == '0')
			{
				que.push(make_pair(i, j));
			}
			j++;
		}
		i++;

	}
	int N = matrix.size();
	//insert a deliiter to track the distance
	pair<int, int> delim = make_pair(-1, -1);
	que.push(delim);
	int curDist = 1;
	while (!que.empty())
	{
		pair<int, int>  item;
		while (!isdelim(item = que.front()))
		{		
			int x = item.first,y=item.second;

			if (isvalid(x + 1, y, N) && matrix[x + 1][y] == 'x')
			{
				que.push(make_pair(x + 1, y));
				matrix[x + 1][y] = curDist+'0';
			}
			 if (isvalid(x - 1, y, N) && matrix[x - 1][y] == 'x')
			{
				que.push(make_pair(x - 1, y));
				matrix[x - 1][y] = curDist + '0';
			}
			 if (isvalid(x, y+1, N) && matrix[x ][y+1] == 'x')
			{
				que.push(make_pair(x, y+1));
				matrix[x ][y+1] = curDist + '0';
			}
			 if (isvalid(x , y-1, N) && matrix[x] [y-1] == 'x')
			{
				que.push(make_pair(x, y));
				matrix[x ][y-1] = curDist + '0';
			}
			que.pop();
			

		}
		que.pop();
		if (!que.empty())
		{
			curDist++;
			que.push(delim);
		}	


	}
}

int main()
{
	int N = 0;
	cin >> N;
	vector<vector<char>> matrix(N,vector<char>(N));
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			cin >> matrix[i][j];
	}

	bsf(matrix);

	cout<<endl<<endl;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			cout << matrix[i][j]<<" ";
		cout << endl;
	}


	return 0;

}