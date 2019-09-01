#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

// INCLUDE HEADER FILES NEEDED BY YOUR PROGRAM
// SOME LIBRARY FUNCTIONALITY MAY BE RESTRICTED
// DEFINE ANY FUNCTION NEEDED
// FUNCTION SIGNATURE BEGINS, THIS FUNCTION IS REQUIRED

	#include<algorithm>

	bool compare(pair<int, int>& p1, pair<int, int>& p2)
	{

		return p1.second < p2.second;

	}

	bool comparelb(pair<int, int>& p1,  const int& n)
	{

		return p1.second < n;

	}


	vector<pair<int, int> > optimalUtilization(int maxTravelDist,
		vector<pair<int, int> > forwardRouteList,
		vector<pair<int, int> > returnRouteList)
	{
		// WRITE YOUR CODE HERE

		vector<pair<int, int>> res;
		pair<int, int> cur;
		int optimaVal = 0;
		std::sort(returnRouteList.begin(), returnRouteList.end(), compare);
		for (auto & fRoute : forwardRouteList)
		{
			int diff = maxTravelDist - fRoute.second;
			if (diff <0)
				continue;
			vector<pair<int, int> >::iterator lb = lower_bound(returnRouteList.begin(), returnRouteList.end()
				, diff,comparelb);
			if (lb == returnRouteList.end() || lb->second !=diff)
				lb--;

			int  total = fRoute.second + lb->second;
			if (total == maxTravelDist) {
				cur.first = fRoute.first;
				cur.second = lb->first;
				res.push_back(cur);
				optimaVal = maxTravelDist;
				continue;
			}
			if (total > optimaVal)
			{
				optimaVal = total;
				cur.first = fRoute.first;
				cur.second = lb->first;
			}

		}
		if (optimaVal != maxTravelDist)
			res.push_back(cur);

		return res;
	}
// FUNCTION SIGNATURE ENDS


int main()
{

	vector<pair<int, int> > forwardRouteList = { {1,8},{2,7},{3,14} };
		vector<pair<int, int> > returnRouteList= { { 1,5 },{ 2,10 },{ 3,14 } };


		optimalUtilization(20, forwardRouteList, returnRouteList);

	return 0;
}

