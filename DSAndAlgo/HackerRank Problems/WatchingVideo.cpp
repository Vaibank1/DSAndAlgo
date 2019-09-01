#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

typedef long long LL;
const int N = 100005;
const int M = 100000;
const int X = 1000000;
int a[N], d, n;
bool func(int T) {
	LL res = 0;
	for (int i = 1; i <= n; ++i) {
		res += a[i];
		if (i >= T) res -= d;
		if (res < 0) return false;
	}
	return true;
}
int bsearch(int L, int R) {
	int mid;
	while (R - L > 1) {
		mid = (L + R) >> 1;
		if (func(mid)) {
			R = mid;
		}
		else {
			L = mid;
		}
	}
	return R;
}
int main() {
	
	cin>>n>>d;
	
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		
	}
	int ans = bsearch(0, n);
	printf("%d", ans);
	
	return 0;
}