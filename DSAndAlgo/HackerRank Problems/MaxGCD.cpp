#include "stdafx.h"
#include <vector>
#include <iostream>
#include <conio.h>
#include <math.h>
#include <string>

#include <algorithm>

using namespace std;

//int maximumGcdAndSum(vector <int> A, vector <int> B) {
//	int n = B.size();
//	if(n==1)
//		return A[0]+B[0];
//	std::sort(B.begin(),B.end(),std::greater<int>());
//	std::sort(A.begin(),A.end(),std::greater<int>());
//	
//	int maxGCD=0;
//	int maxSum=0;
//	int tmp=0;
//	for(int i=0;i<n;++i)
//	{
//		if(maxGCD >= A[i])
//			break;
//		for(int j=0;j<n;++j)
//		{
//			if(maxGCD >= B[j])
//				break;
//			tmp=  gcd(A[i],B[j]);
//			if( maxGCD < tmp)
//			{
//				maxSum = A[i]+B[j];
//				maxGCD = tmp;
//			}
//		}
//	}
//
//	for(int i=0;i<n;++i)
//	{
//		if(maxGCD >= B[i])
//			break;
//		for(int j=0;j<n;++j)
//		{
//			if(maxGCD >= A[j])
//				break;
//				tmp=  gcd(A[i],B[j]);
//			if( maxGCD < tmp)
//			{
//				maxSum = A[i]+B[j];
//				maxGCD = tmp;
//			}
//		}
//	}
//
//	return maxSum;
//
//
//}
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

//

void maxGCDandSum(vector <int> A, vector <int> B, int& maxGCD, int& maxSum)
{
	int n = B.size();
	int maxValue = B[n-1];
	maxGCD=0;
	maxSum=0;
	bool found=false;
	
	for(int i =n-1 ;i>=0;--i)
	{
		if(A[i] <= 0)
			continue;
		if(maxGCD>A[i])
		{
				found=true;
				break;
		}
		for(int j=A[i]; j<=maxValue; j+=A[i])
		{
			if(std::binary_search(B.begin(),B.end(),j))
			{
				//found elem
				if(maxGCD == A[i])
				{
					
					maxSum = max(maxSum,A[i]+j);
				}
				else if(maxGCD <A[i])
				{
					maxGCD = A[i];
					maxSum = A[i]+j;
					
				}
				
			}
		}

		if(found)
			break;

		
	}
	
}

int maximumGcdAndSum(vector <int> A, vector <int> B) {
    // Complete this function
	int n = B.size();
	if(n==1)
		return A[0]+B[0];
	std::sort(B.begin(),B.end());
	std::sort(A.begin(),A.end());
	int maxValue = B[n-1];
	int maxGCD=0, maxA=0,maxB=0;
	int maxSum=0,sumA=0,sumB=0;
	
	maxGCDandSum(A,B,maxA,sumA);
	maxGCDandSum(B,A,maxB,sumB);

	if(maxA > maxB)
	{
		maxGCD = maxA;
		maxSum = sumA;
	}
	else
	{
		maxGCD = maxB;
		maxSum = sumB;
	}


	if(maxGCD ==0)
	{
		//all primes in two arrays
		maxGCD =1;
		maxSum = A[n-1]+B[n-1];
	}

	return maxSum;

}

int main() {
    int n;
    cin >> n;
    vector<int> A(n);
    for(int A_i = 0; A_i < n; A_i++){
       cin >> A[A_i];
    }
    vector<int> B(n);
    for(int B_i = 0; B_i < n; B_i++){
       cin >> B[B_i];
    }
	
    int res = maximumGcdAndSum(A, B);
    cout << res << endl;
    return 0;
}