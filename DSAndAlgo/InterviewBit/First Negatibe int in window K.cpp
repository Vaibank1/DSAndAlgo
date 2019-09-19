#include<vector>
#include<algorithm>

using namespace std;


vector<int> solve(vector<int> &A, int B) {

	int ans = 0, index = -1;
	int n = A.size() - 1;
	vector<int> res;
	for (int i = n - B + 1; i <= n; i++)
	{
		if (A[i]<0) {
			index = i;
			ans = A[i];
			break;
		}
	}
	res.push_back(ans);
	for (int i = n - 1; i-B+1>-1; i--) {
		int start = i - B + 1;
		if (A[start]<0) {
			index = start;
			ans = A[start];
		}
		else {
			if (index == -1 || index > i) {
				index = -1;
				ans = 0;
			}

		}
		res.push_back(ans);

	}

	reverse(res.begin(), res.end());
	return res;


}



int main()
{
	vector<int> in = { -9, 4, 8, -1, 1, 2, 0, -2, 8, -7, 9 };

	int B = 4;

	solve(in, B);


	return 0;
}