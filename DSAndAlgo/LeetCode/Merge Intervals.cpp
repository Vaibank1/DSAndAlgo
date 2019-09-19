#include<vector>
#include<algorithm>

using namespace std;



vector<vector<int>> merge(vector<vector<int>>& intervals) {
	
	if (intervals.size() == 0)
		return vector<vector<int>>();
	if (intervals.size() == 1)
		return intervals;


	sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b) {
		return a[0] < b[0]; });

	vector<vector<int>> res;
	res.push_back(intervals[0]);
	for (auto & it : intervals) {
		if (res.back().at(1) >= it.at(0)) {
			if (res.back().at(1) < it.at(1))
				res.back().at(1) = it.at(1);
		}
		else
			res.push_back(vector<int>{it[0],it[1]});
	}

	return res;

}


int main()
{
	vector<vector<int>> in = { {1,3 }, { 2,6 }, { 8,10 }, { 15,18 } };

	merge(in);


	return 0;
}