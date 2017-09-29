#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool isValid(int x, int y, int n, int** m)
{
	if (x<0 || y<0)
		return false;
	if (x >= n || y >= n)
		return false;
	if (m[x][y] != 0)
		return false;
	return true;
}

void withDirection(int x, int y, int& newx, int& newy, char direction)
{
	switch (direction)
	{
	case 'e':
		newy = ++y;
		newx = x;
		break;
	case 'w':
		newy = --y;
		newx = x;
		break;
	case 'n':
		newx = --x;
		newy = y;
		break;
	case 's':
		newx = ++x;
		newy = y;
		break;
	}

}


void perpendicularDirection1(int x, int y, int& newx, int& newy, char direction)
{
	switch (direction)
	{
	case 'n':
		newy = ++y;
		newx = x;
		break;
	case 's':
		newy = --y;
		newx = x;
		break;
	case 'e':
		newx = --x;
		newy = y;
		break;
	case 'w':
		newx = ++x;
		newy = y;
		break;
	}

}

void perpendicularDirection2(int x, int y, int& newx, int& newy, char direction)
{
	switch (direction)
	{
	case 's':
		newy = ++y;
		newx = x;
		break;
	case 'n':
		newy = --y;
		newx = x;
		break;
	case 'w':
		newx = --x;
		newy = y;
		break;
	case 'e':
		newx = ++x;
		newy = y;
		break;
	}

}

void oppositeDirection(int x, int y, int& newx, int& newy, char direction)
{
	switch (direction)
	{
	case 'w':
		newy = ++y;
		newx = x;
		break;
	case 'e':
		newy = --y;
		newx = x;
		break;
	case 's':
		newx = --x;
		newy = y;
		break;
	case 'n':
		newx = ++x;
		newy = y;
		break;
	}

}

int main() {
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */

	int n;
	cin >> n;

	int **matrix = new int*[n];
	for (int i = 0; i < n; ++i)
	{
		matrix[i] = new int[n];
		for (int j = 0; j < n; j++)
			matrix[i][j] = 0;
		
	}

	char direction;
	cin >> direction;
	int startX, startY,curX,curY,nextX,nextY;
	cin >> startX >> startY;
	matrix[startX][startY] = 1;
	curX = startX; curY = startY;
	for (int i = 2; i <= n*n; i++)
	{
		withDirection(curX, curY, nextX, nextY, direction);
		if (isValid(nextX, nextY, n,matrix))
		{
			matrix[nextX][nextY] = i;
			curX = nextX;
			curY = nextY;
			continue;
		}
		perpendicularDirection1(curX, curY, nextX, nextY, direction);
		if (isValid(nextX, nextY, n, matrix))
		{
			curX = nextX;
			curY = nextY;
			matrix[nextX][nextY] = i;
			continue;
		}
		perpendicularDirection2(curX, curY, nextX, nextY, direction);
		if (isValid(nextX, nextY, n, matrix))
		{
			curX = nextX;
			curY = nextY;
			matrix[nextX][nextY] = i;
			continue;
		}
		oppositeDirection(curX, curY, nextX, nextY, direction);
		if (isValid(nextX, nextY, n, matrix))
		{
			curX = nextX;
			curY = nextY;
			matrix[nextX][nextY] = i;
			continue;
		}
	}


	for (int i = 0;  i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << matrix[i][j] << '\t';
		cout << endl;
	}
	return 0;
}
