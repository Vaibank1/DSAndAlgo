#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


void fillMatrix(int** matrix, int start, int end, int value)
{
	int sub = 0;

	for (int i = start; i < end; i++)
	{
		if (i == start)
			matrix[i][i] = value;
		else
		{
			matrix[start][i] = value - sub;
			matrix[i][start] = value - sub;
		}
		sub++;
	}

}

int main() {
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */
	int N = 0, K = 0, M = 0;
	cin >> N >> M >> K;
	int **matrix = new int*[N];
	for (int i = 0; i < N; i++)
		matrix[i] = new int[N];

	for (int i = 0; i < N; i++)
	{		
		fillMatrix(matrix,i,N,M+(i*K));

	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			cout << matrix[i][j] << " ";
		cout << endl;
	}



	return 0;
}
