

#include <vector>
#include <bitset>
#include <iostream>
#include <conio.h>
#include <math.h>
#include <string>

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include<memory>

using namespace std;


void DPSoultion(const int arr[],int n )
{
	int sum=0;

	for (int i = 0; i < n; i++)
	{
		sum += arr[i];
	}

	//dp[i][j] = including or excluding i'th element can sum ==j be obtained ?
	//1 if yes,else 0 
	int** dp  = new int*[n+1];
	for (int i = 0; i <= n; i++)
	{
		dp[i] = new int[sum/2+1];
	}

	//
	dp[0][0] =1;
	
	for (int i = 1; i <=sum/2 ; i++)
	{

		dp[0][i] = 0;

	}

	for (int i = 1; i <=n ; i++)
	{

		dp[i][0] = 1;

	}

	for (int i = 1; i <=n ; i++)
	{
		for (int j = 1; j <=sum/2; j++)
		{
			dp[i][j] = dp[i-1][j];

			if(arr[i-1] <= j)
			{
				dp[i][j] |= dp[i-1][j-arr[i-1]];
			}
		}

	}



	for (int i = sum/2; i >0; i--)
	{
		if(dp[n][i])
		{
			cout<<"partition sum = "<< i<<endl;
			break;
		}

	}


	cout<<"DP Table"<<endl;

	for (int i = 0; i <=n ; i++)
	{
		
		cout<<(i!=0?arr[i-1]:0);
		cout<<'\t';
		for (int j = 0; j <=sum/2; j++)
		{
			if(i==0)
				cout<<j<<'\t';
			else
			cout<<dp[i][j]<<'\t';
		}
		cout<<endl;
	}


	for (int i = 0; i <= n; i++)
	{
		delete[] dp[i];
	}
	delete[] dp;


}
bitset<4> bit;

int recursiveSolution(const int arr[], int n, int sum1 , int sum2)
{
	if(n <0)
		return abs((sum1 - sum2));
	//two cases:
	//include this element is first subset
	bit[n] = 1;
	int min1 = recursiveSolution(arr,n-1,sum1+arr[n]+1,sum2);
	bit[n] = 0;
	//exclude , i.e. this element is in second subset.
	int min2 = recursiveSolution(arr,n-1,sum1,sum2+arr[n]);

	return min1>min2?min2:min1;


}

int main()
{

	int arr[]={6,6,4,1};	
	int n =sizeof(arr)/sizeof(arr[0]);
	//DPSoultion(arr,n);

	int min = recursiveSolution(arr,n-1,0,0);
		_CrtDumpMemoryLeaks();	
	return 0;

}