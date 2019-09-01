#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef unsigned long long ULL;


ULL forLoopRow( int** board,int iStart, int iEnd, int jStart, int jEnd, bool isPositiveSign)
{
	ULL total = 0;
	for (int i = iStart; isPositiveSign ? i<iEnd : i>=iEnd; isPositiveSign ? i++ : i--)
	{
		for (int j = jStart; isPositiveSign ? j<jEnd : j>=jEnd; isPositiveSign ? j++ : j--)
		{
			if(j== jStart)
				total += board[i][j];

			if (isPositiveSign ? j + 1 < jEnd : j - 1 >= jEnd)
			{

				int res = isPositiveSign ? board[i][j + 1] - board[i][j] : (board[i][j] - board[i][j - 1])*-1;
				if (res > 0)
					total += res;

			}

		}
	}

	return total;

}

ULL forLoopCol(int** board, int iStart, int iEnd, int jStart, int jEnd, bool isPositiveSign)
{
	ULL total = 0;
		for (int j = jStart; isPositiveSign ? j<jEnd : j>=jEnd; isPositiveSign ? j++ : j--)
			for (int i = iStart; isPositiveSign ? i<iEnd : i >= iEnd; isPositiveSign ? i++ : i--)
		{
			if (i == iStart)
				total += board[i][j];

			if (isPositiveSign ? i + 1 < iEnd: i - 1 >= iEnd)
			{
				int res = isPositiveSign ? board[i + 1][j] - board[i][j] : (board[i][j] - board[i - 1][j])*-1;
				if (res > 0)
					total += res;
			}
		}
		
	

	return total;

}


unsigned long long calcArea( int **board,int  H,int W)
{
	//from each view, calculate number of faces visible
	ULL topPlusBottom = H*W*2;

	ULL front = 0, back = 0, left = 0, right = 0;

	left = forLoopRow(board, 0, H, 0, W, true);
	right = forLoopRow(board, H-1, 0, W-1, 0, false);	
	back = forLoopCol(board, 0, H, 0, W, true);
	front = forLoopCol(board, H-1, 0, W-1, 0, false);
		
	ULL total = topPlusBottom + front + back + right + left;
	return total;

}

int main() {
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */
	int H = 0, W = 0;
	cin >> H >> W;

	int ** board = new int*[H];

	for (int i = 0; i < H; i++)
	{
		board[i] = new int[W];
		for (int j = 0; j < W; j++)
		{
			cin >> board[i][j];

		}

	}
	if (H ==1 && W == 1)
	{
		ULL total = 2 * H*W + 2 * H*board[H - 1][W - 1] + 2 * W*board[H - 1][W - 1];
		cout << total;
	}
	else 
		cout<<calcArea(board, H, W);


	//for (int i = 0; i < H; i++)
	//{
	//	cout << endl;
	//	for (int j = 0; j < W; j++)
	//	{
	//		cout<< board[i][j]<<" ";

	//	}

	//}
	return 0;
}
