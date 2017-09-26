#include "Node.h"



int longestIncreasingSubSeq(const vector<int> & arr)
{
	vector<int> tail;

	for (const int &a : arr)
	{
		auto it = upper_bound(tail.begin(), tail.end(), a);
		auto it1 = find(tail.begin(), tail.end(), a);
		if (it1 != tail.end())
			continue;
		if (it == tail.end() )
		{
			/*if (it1 != tail.end() && *it1 == a)
				continue;*/

			tail.emplace_back(a);
		}
		else /*if(it ==( tail.end()-1) )*/
		{
			*it = a;
		}
	}

	return tail.size();
}

int main()
{

	vector<int> vec;
	int tmp = 0, n = 0;
	cin >> n;
	for (int i = 0; i<n; i++)
	{
		cin >>tmp;
		vec.emplace_back(tmp);
	}

	cout << longestIncreasingSubSeq(vec);
	return 0;

}