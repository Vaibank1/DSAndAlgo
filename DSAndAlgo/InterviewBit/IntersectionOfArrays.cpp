#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> intersect(const vector<int> &A, const vector<int> &B) {

	vector<int> res;

	int i = 0, j = 0;

	for (; i<A.size(), j<B.size();)
	{
		if (A[i] == B[j])
		{
			res.push_back(A[i]);

			i++; j++;
		}
		else if (A[i]<B[j])
		{
			i++;
		}
		else
			j++;

	}

	return res;
}


int main()
{
	vector<int> a = { 21, 26, 43, 44, 45, 56, 58, 59, 65, 80, 80, 84, 85 }, b = { 3, 4, 7, 21, 25, 27, 38, 44, 56, 58, 60, 63, 67, 71, 72, 78, 79, 86, 86, 93, 99 }, c;
	
	intersect(a, b);

	return 0;
}