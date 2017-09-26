#include <iostream>
#include <vector>

#include <conio.h>
#include <math.h>
#include <string>
using namespace std;



void printPascalTriangle(int n)
{
	if (n <= 0)
		return;
	int** dp = new int*[n];


	for (int i = 0; i < n; ++i)
	{
		dp[i] = new int[n];
		for (int j= 0; j <= i; j++)
		{
			if (j == 0 || j == i)
				dp[i][j] = 1;
			else
			{
				dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j ];
			}
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}

}

void printPascalTriangleNoSpace(int n)
{
	if (n <= 0)
		return;



	for (int i = 1; i <= n; ++i)
	{
		int c = 1;
		for (int j = 1; j <= i; j++)
		{
			cout << c << " ";
			c = c*(n - j) / j;			
			
		}
		cout << endl;
	}

}

int main()
{
	int n = 5;

	printPascalTriangle(n);

	cout << endl << endl;
	printPascalTriangleNoSpace(n);

	return 0;
}

