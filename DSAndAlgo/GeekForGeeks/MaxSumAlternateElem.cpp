
#include "stdafx.h"
#include <iostream>
#define _CRTDBG_MAP_ALLOC  
#include <stdlib.h>  
#include <crtdbg.h> 
using namespace std;

int main() {
	//code
	int T,n;
	cin>>T;
	
	for(int i=0;i<T;++i)
	{
		cin>>n;
	    int *arr = new int[n];
		int *dp = new int[n];
		for(int j=0;j<n;j++)
		{
			cin>>arr[j];
		}
		dp[0]=arr[0];
		dp[1] = max(arr[1],arr[0]);
	    for(int j=2;j<n;j++)
	    {
	        dp[j] = max(arr[j]+dp[j-2],dp[j-1]);
	        
	    }
	    cout<<dp[n-1];
	    delete [] arr;
		delete []dp;
	
	}
	_CrtDumpMemoryLeaks(); 
	return 0;
}