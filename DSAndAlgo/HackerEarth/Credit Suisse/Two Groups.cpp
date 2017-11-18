
#include<iostream>
#include<algorithm>

using namespace std;
typedef unsigned long long ULL;
ULL** C;

void nCrModp(ULL n, ULL p)
{
	
	 C = new ULL*[n+1];
	
	 C[0] = new ULL[1];
	C[0][0] = 1; 

			  // One by constructs remaining rows of Pascal
			  // Triangle from top to bottom
	for (ULL i = 1; i <= n; i++)
	{
		C[i] = new ULL[i+1];
		// Fill entries of current row using previous
		// row values
		for (ULL j = 0; j <= i; j++)
		{
			if (j == 0 || j==i)
				C[i][j] = 1;
			else
			{
				C[i][j] = ( C[i - 1][j - 1] + C[i - 1][j] )%p;
			}
		}

	}
}




int main() 
{

	ULL T = 0, N = 0,P= pow(10,9)+7;

	cin >> T >> N;
	nCrModp(N, P);
	ULL total = 0,cur;
	for (ULL i = 1; i < N; i++)
	{
		cur = 0;
		for (int j = 1; j <= N-i; j++)
		{
			cur += C[N - i][j];
			cur %= P;
		}

		cur *= C[N][i];
		cur %= P;
		
		total += cur;
		total %= P;
	}

	cout << total;
	return 0;
}