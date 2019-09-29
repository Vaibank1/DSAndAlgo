
#include<iostream>

using namespace std;
int main() {
	long long rows=5, cols=5, k=8, left = 0, right, ans, total, mid, j, i;
	//cin >> rows >> cols >> k;
	right = rows*cols;
	do 
		for (total = 0, mid = (left + right) >> 1, j = cols, i = 1; j&&i <= rows; i++, total += j)
			while (mid <= i*j)
				j--;
	while (left <= right && (total>k - 1 ? right = mid - 1 : left = (ans = mid) + 1));
	cout << ans;
}