//
//#include<iostream>
//#include<vector>
//#include<string>
//
//using namespace std;
//
////string longestPalindrome(string A) {
////
////	vector<vector<int>> dp(A.length(), vector<int>(A.length()));
////
////	for (int i = 0; i < A.length(); i++)
////	{
////		dp[i][i] = true;
//// 
////	}
////
////	int start = 0;
////	int maxLen = 1;
////	for (int i = 0; i < A.length() - 2; i++)
////		if (A[i] == A[i + 1])
////		{
////			dp[i][i + 1] = 1;
////			if (maxLen < 2)
////			{
////				maxLen = 2;
////				start = i;
////			}
////		}
////	for(int k=3;k<=A.length();k++)
////		for (int i = 0; i < A.length() - k+1; i++)
////		{
////			int j = i + k - 1;
////			if (dp[i + 1][j - 1] == 1 && A[i] == A[j])
////			{
////				dp[i][j] = 1;
////				if (maxLen < k)
////				{
////					start = i;
////					maxLen = k;
////				}
////			}
////
////		}
////
////	return A.substr(start, maxLen);
////}
//
//
//string expand(string s,int c1, int c2)
//{
//	int l = c1;
//	int r = c2;
//
//	while (l>=0 && r <s.length() && s[l]==s[r])
//	{
//		l--;
//		r++;
//
//	}
//	return s.substr(l+1,r-l-1);
//
//}
//
//string longestPalindrome(string s)
//{
//	string longest;
//	for (int i = 0; i < s.length()-1; i++)
//	{
//		string p1 = expand(s,i,i);
//		if (p1.length() > longest.length())
//			longest = p1;
//		p1 = expand(s, i, i+1);
//		if (p1.length() > longest.length())
//			longest = p1;
//
//	}
//
//	return longest;
//}
//int main()
//{
//	string a = "aaaabaaa";
//	cout<<longestPalindrome(a);
//	return 0;
//}
// C++ program to find maximum rectangular area in
// linear time
#include<iostream>
#include<stack>
using namespace std;

// The main function to find the maximum rectangular 
// area under given histogram with n bars
int getMaxArea(int hist[], int n)
{
	// Create an empty stack. The stack holds indexes 
	// of hist[] array. The bars stored in stack are 
	// always in increasing order of their heights.
	stack<int> s;

	int max_area = 0; // Initalize max area
	int tp;  // To store top of stack
	int area_with_top; // To store area with top bar
					   // as the smallest bar

					   // Run through all bars of given histogram
	int i = 0;
	while (i < n)
	{
		// If this bar is higher than the bar on top 
		// stack, push it to stack
		if (s.empty() || hist[s.top()] <= hist[i])
			s.push(i++);

		// If this bar is lower than top of stack, 
		// then calculate area of rectangle with stack 
		// top as the smallest (or minimum height) bar. 
		// 'i' is 'right index' for the top and element 
		// before top in stack is 'left index'
		else
		{
			tp = s.top();  // store the top index
			s.pop();  // pop the top

					  // Calculate the area with hist[tp] stack 
					  // as smallest bar
			area_with_top = hist[tp] * (s.empty() ? i :
				i - s.top() - 1);

			// update max area, if needed
			if (max_area < area_with_top)
				max_area = area_with_top;
		}
	}

	// Now pop the remaining bars from stack and calculate
	// area with every popped bar as the smallest bar
	while (s.empty() == false)
	{
		tp = s.top();
		s.pop();
		area_with_top = hist[tp] * (s.empty() ? i :
			i - s.top() - 1);

		if (max_area < area_with_top)
			max_area = area_with_top;
	}

	return max_area;
}

// Driver program to test above function
int main()
{
	int hist[] = {2,2,1,2,2,1};
	int n = sizeof(hist) / sizeof(hist[0]);
	//cout << "Maximum area is " << getMaxArea(hist, n);


	int base = 16;
	string num = "F";
	int ret = 0;
	for (auto ch : num)
	{
		ret = ret * 16;
		if (isdigit(ch))
			ret += ch - '0';
		else
			ret += ch - 'A' + 10;
	}
	return 0;
}