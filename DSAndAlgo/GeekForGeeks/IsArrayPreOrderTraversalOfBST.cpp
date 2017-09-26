#include "stdafx.h"

#include <vector>
#include <iostream>
#include <conio.h>
#include <math.h>
#include <string>
#include <queue>
#include <stack>


using namespace std;




bool canRepresentBST(int pre[], int n)
{
	// Create an empty stack
	stack<int> s;

	int lowerBound = std::numeric_limits<int>::min();

	for (int i = 0; i < n; i++)
	{
		if (pre[i] < lowerBound)
			return false;
		while (!s.empty() && s.top() < pre[i])
		{
			lowerBound = s.top();
			s.pop();
		}
		s.push(pre[i]);

	}
	return true;
}


bool recurse(int arr[], int l , int h)
{
	if (l >= h)
		return true;
	int k = arr[l];
	int mark = 0;
	int index = 0;
	for (int i = l+1; i < h; ++i)
	{
		
		if (arr[i] > k && mark ==0)
		{
			mark = 1;
			index = i;
		}
		else if (arr[i] < k && mark == 1)
		{
			return false;
		}
	}

	return recurse(arr, l + 1, index - 1) && recurse(arr, index + 1, h);



}

	

// Driver program
int main()
{
	/*int pre1[] = { 40, 30, 35, 80, 100 };*/
	int pre1[] = { 2,4,3 };
	int n = sizeof(pre1) / sizeof(pre1[0]);
	/*canRepresentBST(pre1, n) ? cout << "truen" :
		cout << "falsen";*/
	recurse(pre1,0, n) ? cout << "truen" :
		cout << "falsen";

	int pre2[] = { 40, 30, 35, 20, 80, 100 };
	n = sizeof(pre2) / sizeof(pre2[0]);
	/*canRepresentBST(pre2, n) ? cout << "truen" :
		cout << "falsen";*/
	recurse(pre2,0, n) ? cout << "truen" :
		cout << "falsen";

	return 0;
}