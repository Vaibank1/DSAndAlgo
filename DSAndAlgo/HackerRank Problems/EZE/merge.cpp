#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


vector <int> mergeArrays(vector <int> a, vector <int> b) {
	if (a.size() == 0)
		return b;
	else if (b.size() == 0)
		return a;

	vector<int> res(a.size() + b.size());
	int aLen = 0, bLen = 0;
	for (int i = 0; i<a.size() + b.size(); ++i)
	{
		if (aLen >= a.size())
		{
			res[i] = b[bLen++];

		}
		else if (bLen >= b.size())
		{
			res[i] = a[aLen++];

		}
		else if (a[aLen] <b[bLen])
		{
			res[i] = a[aLen++];
		}
		else
		{
			res[i] = b[bLen++];
		}

	}

	return res;
}


int main()
{
	vector<int> a = { 1,5,7,7 }, b = { 0,1,2,3 },c;
	c=mergeArrays(a, b);


	return 0;
}