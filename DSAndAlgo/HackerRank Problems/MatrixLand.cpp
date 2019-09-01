#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef unsigned long long ULL;


int matrixland(vector<vector<int> > grid) {
	int width = grid[0].size();

	vector<int> prevline(width);
	vector<int> going_left(width);
	vector<int> going_right(width);

	for (vector<int> line : grid) {
		fill(going_left.begin(), going_left.end(), 0);
		fill(going_right.begin(), going_right.end(), 0);

		int top = -2000000000;
		int notop = 0;
		for (int i = 0; i<width; i++) {
			notop = max(0, notop);
			going_right[i] += notop;
			notop += line[i];
			top = max(top + line[i], prevline[i] + notop);
			going_left[i] += top;
		}

		top = -2000000000;
		notop = 0;
		for (int i = width - 1; i >= 0; i--) {
			notop = max(0, notop);
			going_left[i] += notop;
			notop += line[i];
			top = max(top + line[i], prevline[i] + notop);
			going_right[i] += top;
		}

		for (int i = 0; i<width; i++) {
			prevline[i] = max(going_left[i], going_right[i]);
		}
	}

	int answer = -2000000000;
	for (int i = 0; i<width; i++) {
		answer = max(answer, prevline[i]);
	}

	return answer;
}

//int matrixLand(vector<vector<int> > grid) {
//	int width = grid[0].size();
//
//	
//	vector<int> going_left(width);
//	vector<int> going_right(width);
//
//	for (vector<int> line : grid) {
//		fill(going_left.begin(), going_left.end(), 0);
//		fill(going_right.begin(), going_right.end(), 0);
//
//		int curSum = 0;
//		int maxSum = INT_MIN;
//		for (int i = 0; i < width; i++)
//		{
//			curSum = max(0, curSum);
//			going_right[i] += curSum;
//			curSum += line[i];
//			maxSum = max(line[i], curSum);
//			going_left[i] += maxSum;
//
//		}
//
//		curSum = 0, maxSum = INT_MIN;
//		for (int i = width - 1; i >= 0; i--)
//		{
//			curSum = max(0, curSum);
//			going_left[i] += curSum;
//			curSum += line[i];
//			maxSum = max(line[i], curSum);
//			going_right[i] += maxSum;
//		}
//		int a = 0;
//		
//	}
//
//	int answer = -2000000000;
//	
//
//	return answer;
//}



int main() {
	int n;
	int m;
	cin >> n >> m;
	vector< vector<int> > A(n, vector<int>(m));
	for (int A_i = 0; A_i < n; A_i++) {
		for (int A_j = 0; A_j < m; A_j++) {
			cin >> A[A_i][A_j];
		}
	}
	int result = matrixland(A);

	

	cout << result << endl;
	return 0;
}
