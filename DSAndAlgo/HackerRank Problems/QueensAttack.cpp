#include<map>
#include<set>
#include<string>
#include<unordered_map>
#include<numeric>
#include<climits>
#include<iterator>
#include<array>
#include<iostream>
using namespace std;



	bool isValid(int x, int y, int n)
	{
		//1: Row
		//2: col
		// 3 : Daigonal
		//4: other Daigonal

		if (x<1 || y<1 || x>n || y>n)
			return false;
		
		return true;
	}


	int main() {
		
		int n ;
		cin >> n;

		int k ;
		cin >> k;
		int rQueen; cin >>rQueen;
		int cQueen; cin >> cQueen;
		
		/*int** chessBoard = new int* [n+1];
		for (int i = 0; i < n; i++)
			chessBoard[i] = new int[n + 1]{ 0 };*/

		rQueen = n + 1 - rQueen;
		for (int a0 = 0; a0 < k; a0++) {
			int x;cin>>x;
			x = n + 1 - x;
			int y; cin >> y;
			

		}

		int ans = 0;

		//squares on the same row
		for (int i = cQueen + 1; i <= n; i++)
		{
			if (isValid( rQueen, i, n))
				ans++;
			else
				break;
		}
		for (int i = cQueen - 1; i>0; i--)
		{
			if (isValid( rQueen, i, n))
				ans++;
			else
				break;
		}

		//same col
		for (int i = rQueen + 1; i <= n; i++)
		{
			if (isValid( i, cQueen, n))
				ans++;
			else
				break;
		}
		for (int i = rQueen - 1; i>0; i--)
		{
			if (isValid( i, cQueen, n))
				ans++;
			else
				break;
		}

		int xDaig = rQueen + 1;
		int yDaig = cQueen + 1;
		//for Daigonal 1
		while (xDaig <= n && yDaig <= n)
		{
			if (isValid( xDaig, yDaig, n))
				ans++;
			else
				break;

			xDaig++;
			yDaig++;

		}

		xDaig = rQueen - 1;
		yDaig = cQueen - 1;
		while (xDaig >0 && yDaig >0)
		{
			if (isValid( xDaig, yDaig, n))
				ans++;
			else
				break;

			xDaig--;
			yDaig--;

		}

		//for Daigonal 2
		xDaig = rQueen - 1;
		yDaig = cQueen + 1;
		while (xDaig >0 && yDaig <= n)
		{
			if (isValid( xDaig, yDaig, n))
				ans++;
			else
				break;

			xDaig--;
			yDaig++;

		}

		xDaig = rQueen + 1;
		yDaig = cQueen - 1;
		while (xDaig <= n  && yDaig >0)
		{
			if (isValid( xDaig, yDaig, n))
				ans++;
			else
				break;

			xDaig++;
			yDaig--;

		}



		cout<<(ans);
	}

