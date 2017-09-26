//10 7 6
//1 3
//5 7
//3 5
//2 6
//2 4
//8 4
//10 9
//1 9 2 3 10 3


//10 8 15
//1 2
//1 3
//2 7
//3 1
//4 5
//6 8
//9 6
//10 5
//1 4 5 7 9 8 1 3 10 4 5 10 2 7 8

#include "stdafx.h"
#include<iostream>
#include<vector>
using namespace std;

int *parentArr=NULL;
int n;
    int k;
    int m;

	

int maxPalindrome(vector<int>& arr)
{
	 int result =1;
	 int n = arr.size();
	 int** dp =  nullptr ;
	 dp = new int*[n];
	 for(int i=0;i<n;++i)
	 {
		dp[i] = new int[n];
	 }
	 int j=0;
	 // Strings of length 1 are palindrome of lentgh 1
   for (int i = 0; i < n; i++)
      dp[i][i] = 1;
	 for(int len=2;len <=n ; ++len)
	 {
		 for(int i =0; i < n-len+1; ++i)
		 {
			 j= i + len -1;
			
			 if(parentArr[arr[i]] == parentArr[arr[j]] && len ==2)
				 dp[i][j] =2;
			 else if(parentArr[arr[i]] == parentArr[arr[j]] )
				 dp[i][j] = dp[i+1][j-1]+2;
			 else 
				 dp[i][j] = max(dp[i+1][j],dp[i][j-1]);
		 }
		
	 }

	 result = dp[0][n-1];
	 for(int i=0;i<n;++i)
	 {
		delete[] dp[i] ;
	 }
	 delete dp;

	 return result;
}

void changeParent( int v , int pr)
{
	if(parentArr[v] != -1)
		for(int i=1; i <=n;++i)
			if(parentArr[i]==v)
				parentArr[i]=pr;
	
	parentArr[v]=pr;
	
}

void connectedComponent(int v1, int v2)
{
	if(-1 == parentArr[v1] && -1 == parentArr[v2])
	{
		parentArr[v1]=v1;
		parentArr[v2]=v1;
		
	}
	else if(parentArr[v1] == parentArr[v2])
		return;
	
	else if( parentArr[v1] == -1)
	{
		changeParent(v1,parentArr[v2]);
		
	}
	else
		changeParent(v2,parentArr[v1]);
	
	
}



void initArray(int* arr, int n)
{
	for(int i =1 ; i <= n;++i)
		arr[i]=-1;
	
}


void convertArray(vector<int> & arr)
{
	for(int i =0 ; i < arr.size();++i)
		if(parentArr[arr[i]] != -1)
		arr[i]=parentArr[arr[i]];

}

void print(vector<int> & arr)
{
	for(int i =0 ; i < arr.size();++i)
		cout<<arr[i]<<'\t';

}
int main() {
    
    cin >> n >> k >> m;

	parentArr= new int[n+1];
	
	initArray(parentArr,n);
	
    for(int a0 = 0; a0 < k; a0++){
        int x;
        int y;
        cin >> x >> y;
		//build connected component
		connectedComponent(x,y);
    }
    vector<int> a(m);
    for(int a_i = 0; a_i < m; a_i++){
       cin >> a[a_i];
    }
/*
	convertArray(a);
	
	print(a);*/


	
	cout<<endl<<"\n\n\t"<<maxPalindrome(a);
	
	delete[] parentArr;
    return 0;
}
